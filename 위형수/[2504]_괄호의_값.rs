use std::io::Read;

// 깊이가 커질수록 곱하기
// 한 쌍의 괄호일 때 값을 계산
// 깊이가 작아질 때 나누기

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    let input = input.trim();
    
    let mut stack:Vec<char> = Vec::new();
    let mut temp = 1;
    let mut former_token = '#'; // init any

    let mut result = input.chars().fold(0, |mut acc, token| 
        {
            match token {
                '(' => {
                    temp *= 2;
                    stack.push(token);
                },
                '[' => {
                    temp *= 3;
                    stack.push(token);
                },
                ')' if stack.last() == Some(&'(') => {
                    if former_token == '(' { acc += temp; }
                    temp /= 2;
                    stack.pop();
                }
                ']' if stack.last() == Some(&'[') => {
                    if former_token == '[' { acc += temp; }
                    temp /= 3;
                    stack.pop();
                },
                _ => { acc = 0; temp = 0; }
            };

            former_token = token;

            acc
        }
    );

    if !stack.is_empty() { result = 0; }
    println!("{result}")
}
