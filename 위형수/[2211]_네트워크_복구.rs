use std::{cmp::Reverse, collections::{BinaryHeap, HashMap}, io::{prelude::*, stdout, BufWriter}, usize::MAX};

// Node를 탐색하면서 거쳐온 경로를 저장

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    // println!("Input: {:?}", input);

    let mut writer = BufWriter::new(stdout().lock());

    let n = input.next().unwrap();
    let m = input.next().unwrap();

    let mut graph: Vec<Vec<u8>> = vec![vec![11; n+1]; n+1];
    let mut djk: Vec<(usize, Vec<usize>)> = vec![(MAX, Vec::new()); n+1]; // [(dist, route)]
    djk[1].0 = 0;

    for _ in 0..m {
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        let c = input.next().unwrap() as u8;

        graph[a][b] = c;
        graph[b][a] = c;
    }

    let mut max_heap: BinaryHeap<Reverse<(usize, usize, Vec<usize>)>> = BinaryHeap::new();
    max_heap.push(Reverse((0, 1, vec![1])));

    while !max_heap.is_empty() {
        let Reverse((cur_dist, cur_node, cur_route)) = max_heap.pop().unwrap();

        for next_node in 1..=n {
            if graph[cur_node][next_node] > 10 {
                continue;
            }

            let next_dist = cur_dist + graph[cur_node][next_node] as usize;
            let mut next_route = cur_route.clone();
            next_route.push(next_node);

            if next_dist < djk[next_node].0 {
                djk[next_node] = (next_dist, next_route.clone());
                max_heap.push(Reverse((next_dist, next_node, next_route)));
            }
        }
    }

    let mut result = HashMap::new();
    for i in 2..=n {
        let route = &djk[i].1;
        for j in 0..(route.len()-1) {
            if route[j] > route[j+1] {
                result.insert((route[j+1], route[j]), 0);
            }
            else {
                result.insert((route[j], route[j+1]), 0);
            }
        }
    }

    writeln!(writer, "{}", result.len()).unwrap();
    result.into_keys().for_each(|(from, to)| {
        writeln!(writer, "{from} {to}").unwrap();
    });

}
