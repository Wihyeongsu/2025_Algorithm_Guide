use std::{collections::{VecDeque}, io::{prelude::*, stdout, BufWriter}, isize, vec};

// dist[next_node] = min(dist[next_node], dist[cur_node] + graph[cur_node][next_node] - earn[next_node])

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
    let s = input.next().unwrap();
    let e = input.next().unwrap();
    let m = input.next().unwrap();

    let mut dist: Vec<isize> = vec![isize::MAX; n];
    // let mut graph: HashMap<(usize, usize), usize> = HashMap::with_capacity(m);
    // => 해시 충돌? 때문인지 계속 오답 발생
    let mut graph: Vec<Vec<(usize, usize)>> = vec![Vec::new(); n];

    for _ in 0..m {
        let from = input.next().unwrap();
        let to = input.next().unwrap();
        let cost = input.next().unwrap();
        graph[from].push((to, cost));
    }
    let earn:Vec<usize> = input.collect();
    dist[s] = 0-earn[s] as isize;

    // Bellman ford
    let mut queue: VecDeque<(usize, isize, usize)> = VecDeque::new(); // (node, cost, stage)
    let n = 2*n;
    queue.push_back((s, dist[s], 1));
    for stage in 1..=n {
        while let Some(&(cur_node, cur_cost, cur_stage)) = queue.front() {
            if cur_stage > stage {
                break;
            }
            queue.pop_front();
            for &(next_node, cost) in &graph[cur_node] {
                    let next_cost = cur_cost + cost as isize - earn[next_node] as isize;
                    if dist[next_node] > next_cost {
                        if cur_stage == n {
                            // Negative cycle
                            // bfs를 통해 도착지에 도달 가능한지 확인
                            let mut queue = VecDeque::new();
                            queue.push_back(next_node);
                            let mut visited = vec![false; n];
                            while let Some(cur_node) = queue.pop_front() {
                                visited[cur_node] = true;
                                for &(next_node, _) in &graph[cur_node] {
                                    if next_node == e {
                                        writeln!(writer, "Gee").unwrap();
                                        return;
                                    }
                                    if visited[next_node] {
                                        continue;
                                    }
                                    queue.push_back(next_node);
                                    visited[next_node] = true;
                                }
                            }
                        }
                        dist[next_node] = next_cost;
                        queue.push_back((next_node, next_cost, cur_stage+1));
                    }
                }
        }
    }
    match dist[e] {
        isize::MAX => writeln!(writer, "gg" ).unwrap(),
        money => writeln!(writer, "{}", -money).unwrap(),
    }
}
