use std::{io::{prelude::*, stdout, BufWriter}, isize};

// 가능한 모든 칸을 가야함
// r 홀수 | c 홀수이면 지그재그로 모든 칸을 거칠 수 있음
// r 짝수 & c 짝수에 대해 모든 칸 통과 불가
//   체스판
//     이동할 때마다 색이 다른 칸으로 이동
//     시작 칸(B)과 도착 칸(B)의 색이 같음
//     한 칸(W)을 통과할 수 없음
//     W칸 중 최솟값을 저장하여 포기할 칸을 결정

fn zig_zag(dir: char) -> impl Fn(usize, usize) -> String {
    let symbol = match dir {
        'v' => ('R', 'D', 'L'), // vertical
        'h' => ('D', 'R', 'U'), // horizontal
        'r' => ('L', 'D', 'R'), // reverse vertical
        _ => unreachable!()
    };
    
    return move |r, c|{
        // ex: zig_zag_v
        // r/2
        //   R * (c-1)
        //   D * 1
        //   L * (c-1)
        //   D * 1
        // r is odd
        //   R * (c-1)
        let result = (0..r/2).fold(String::new(), |mut acc, _|{
            acc += symbol.0.to_string().repeat(c-1).as_str();
            acc.push(symbol.1);
            acc += symbol.2.to_string().repeat(c-1).as_str();
            acc.push(symbol.1);
            acc
        });
        if r%2 == 0 {
            return result;
        }
        result + symbol.0.to_string().repeat(c as usize-1).as_str()
    }
}

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    // println!("Input: {:?}", input);
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<isize>);

    let mut writer = BufWriter::new(stdout().lock());

    let r = input.next().unwrap() as usize;
    let c = input.next().unwrap() as usize;
    let (_, min_x, min_y)= input.enumerate()
        .fold((1001, 0, 0), |(mut min, mut min_x, mut min_y), (i, v)|{
            let y = i/c as usize;
            let x = i%c as usize;
            if (y+x)%2 == 1 && min > v {
                min = v;
                min_x = x;
                min_y = y;
            };
            (min, min_x, min_y)
        }
    );
    let zig_zag_v = zig_zag('v');
    let zig_zag_h = zig_zag('h');
    let zig_zag_r = zig_zag('r');

    let mut result = 
        if r%2 == 1 {
            zig_zag_v(r, c)
        }
        else if c%2 == 1 {
            zig_zag_h(c, r)
        }
        else {
            // 2행씩 분할
            let mut temp = String::new();
            for cur_r in 0..r/2 {
                let cur_r = cur_r*2;
                // 피할 칸이 포함된 2행
                if cur_r == min_y || cur_r+1 == min_y {
                    // DRUR * c/2 - 2*char
                    // ex) (c=4) DR/UR/DR/(UR)
                    // 한 칸을 피하는 것은 이후의 행동을 끌어다 쓰는 것
                    // -> ex) (min_x=1) DR/R/UR/D(R)
                    let mut result = zig_zag_h(c, 2);
                    result.pop();
                    result.pop();
                    // 피할 칸이 구석에 있는 경우 알아서 피해감
                    if min_x != c-1 {
                        let ex_move = result.pop().unwrap();
                        result.insert(min_x*2, ex_move);
                    }
                    result.push('D');
                    temp += result.as_str();
                }
                // 피할 칸이 있는 구간 이후 시작 위치 전환 오른쪽에서 시작
                else if min_y <= cur_r+1 {
                    temp += zig_zag_r(2, c).as_str();
                }
                else {
                    temp += zig_zag_v(2, c).as_str();
                }
            }
            temp.pop();
            temp
        };
        
    writeln!(writer, "{result}").unwrap();
}
