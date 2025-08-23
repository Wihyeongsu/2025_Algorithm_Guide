use std::{io::{prelude::*, stdout, BufWriter}, vec};

// Sub problem
// 가장 큰 빌딩부터 내림차순으로 배치하면서
// 현재 상태(좌우에서 보이는 빌딩 수)에서
// 목적 상태(최종 좌우에서 보이는 빌딩 수)까지 도달하기 위해
// 현재 배치된 빌딩의 개수와 현재 상태에 따라
// 배치할 수 있는 빌딩의 경우의 수

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut writer = BufWriter::new(stdout().lock());

    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n = input.next().unwrap();
    let l = input.next().unwrap();
    let r = input.next().unwrap();
    let mut memo = vec![vec![vec![0; r+1]; l+1]; n+1]; // memo[n][l][r]

    // DP(bottom-up)
    // 양끝에 배치하는 경우의 수 + 건물들 중간에 배치하는 경우의 수
    // Sol(N, L, R) = Sol(N-1, L-1, R) + Sol(N-1, L, R-1) + (N-2)*Sol(N-1, L, R)
    memo[1][1][1] = 1;
    for cur_n in 2..=n {
        for cur_l in 1..=l {
            for cur_r in 1..=r {
                memo[cur_n][cur_l][cur_r] = (memo[cur_n-1][cur_l-1][cur_r] + memo[cur_n-1][cur_l][cur_r-1] + (cur_n-2)*memo[cur_n-1][cur_l][cur_r]) % 1000000007
            }
        }
    }
    

    writeln!(writer, "{}", memo[n][l][r]).unwrap();
}
