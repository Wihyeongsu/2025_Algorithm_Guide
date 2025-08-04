use std::{io::{prelude::*, stdout, BufWriter}};

#[derive(PartialEq, Eq, Debug, Clone)]
struct Line {
    from: isize,
    to: isize,
    num: usize
}

impl Ord for Line {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.from
            .cmp(&other.from)
            .then(other.to.cmp(&self.to))
    }
}

impl PartialOrd for Line {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut input = input.split_ascii_whitespace();

    let mut writer = BufWriter::new(stdout().lock());

    let n: isize = input.next().unwrap().parse().unwrap();
    let m = input.next().unwrap().parse().unwrap();
    let mut lines = Vec::new(); // [(from, to, num)]

    for i in 1..=m {
        let a = input.next().unwrap().parse().unwrap();
        let b = input.next().unwrap().parse().unwrap();
        if a > b {
            lines.push(
                Line{
                    from: a-n,
                    to: b,
                    num: i,
                }
            );
            lines.push(
                Line{
                    from: a,
                    to: b+n,
                    num: i,
                }
            );
        }
        else {    
            lines.push(
                Line{
                    from: a,
                    to: b,
                    num: i,
                }
            );
        }
    }

    // 시작점 오름차순, 도착점 내림차순 정렬 후 순차적으로 진행하여
    // 노선의 도착점의 번호가 커지면 포함되지 않는 노선
    lines.sort_unstable();

    let mut result = lines.iter().scan(-1, |to, line|{
        if *to < line.to {
            *to = line.to;
            return Some(line.num);
        }
        else {
            return Some(0);
        }
    })
    .filter(|num| *num > 0)
    .collect::<Vec<usize>>();
    result.sort_unstable();
    result.dedup();
    result.iter().for_each(|num| write!(writer, "{num} ").unwrap());
}
