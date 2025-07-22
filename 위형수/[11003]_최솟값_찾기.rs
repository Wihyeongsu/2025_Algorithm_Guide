use std::{collections::VecDeque, io::Read};

// deque에 최솟값이 될 수 있는 후보들을 오름차순으로 저장
// 주어지는 token의 값이 deque의 마지막 값과 비교하여 token 값이 더 작은 경우 deque 마지막을 pop하는 과정을 반복
// => 주어지는 token이 deque의 값보다 작다는 것은, deque에 존재하는 token보다 큰 값은
//    token보다 짧게 유지(window가 이동함에 따라 window size내에서 일찍 벗어남)되기 때문

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    let input = input.trim();
    // println!("Input: {:?}", input);

    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<isize>);

    input.next();// n: unused
    let l = input.next().unwrap() as usize;
    let a: Vec<isize> = input.collect();
    let mut deque: VecDeque<(usize, isize)> = VecDeque::new(); // 최솟값 후보 오름차순으로 저장
    let mut index = 0;

    a.iter().fold(Vec::new(), |mut result: Vec<isize>, &token| {
        loop {
            match deque.back() {
                Some(&(_, last)) if last > token => {deque.pop_back();}
                _ => {
                    deque.push_back((index, token));
                    break;
                }
            }
        };
        if let Some((i, _)) = deque.front(){
            if i+l <= index {
                deque.pop_front();
            }
        }
        result.push(deque.front().unwrap().1);
        index += 1;
        result
    }).iter().for_each(|a| print!("{a} "));
    

}
