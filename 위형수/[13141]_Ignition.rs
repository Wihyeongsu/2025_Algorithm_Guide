use std::{io::{prelude::*, stdout, BufWriter}};

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut writer = BufWriter::new(stdout().lock());

    let n = input.next().unwrap();
    let m = input.next().unwrap();
    let mut dist: Vec<Vec<usize>> = vec![vec![30000; n+1]; n+1];
    let mut edges: Vec<(usize, usize, usize)> = Vec::new();

    for _ in 0..m {
        let s = input.next().unwrap();
        let e = input.next().unwrap();
        let l = input.next().unwrap();

        edges.push((s,e,l));
        dist[s][e] = l.min(dist[s][e]);
        dist[e][s] = dist[s][e];
    }

    // Floyd warshall
    for k in 1..=n {
        for from in 1..=n {
            if dist[from][from] == 30000 {
                dist[from][from] = 0;
            }
            for to in 1..=n {
                // if dist[from][k] == 30000 || dist[k][to] == 30000 {
                //     continue;
                // }
                dist[from][to] = dist[from][to].min(dist[from][k] + dist[k][to]);
            }
        }
    }

    // Ignite
    let mut result = f64::MAX;
    for ignite in 1..=n {
        let mut temp: f64= 0.0;
        edges.iter().for_each( |&(n1, n2, len)|{
            // diff: 점화 시작 node에서 각 n1, n2가 점화되는 시각 차 
            let diff= dist[ignite][n1].abs_diff(dist[ignite][n2]);
            let min_dist = dist[ignite][n1].min(dist[ignite][n2]) as f64; 
            if diff >= len {
                // n1, n2 사이의 edge의 길이보다 두 node가 점화되는 시각 차가 크거나 같다.
                // => n1, n2 사이의 edge는 늦게 점화된 node가 점화됐을 때 이미 모두 타버렸음을 의미.
                // => 늦게 점화된 node는, 먼저 점화된 node와 edge를 통해서 점화됐음을 의미.
                temp = temp.max(min_dist + len as f64);
            }
            else {
                // n1, n2 사이의 edge의 길이가 두 node가 점화되는 시각 차보다 크다
                // => n1, n2 사이의 edge가 diff만큼 타고있는 중이다.
                // => 남은 길이(len - diff)는 양쪽에서 타게된다.
                temp = temp.max(min_dist + diff as f64 + (len - diff) as f64/2.0);
            }
        });
        result = result.min(temp);
    }
    writeln!(writer, "{:.1}", result).unwrap();

}
