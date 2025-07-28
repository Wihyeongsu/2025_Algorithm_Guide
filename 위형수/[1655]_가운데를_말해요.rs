use std::{cmp::Reverse, collections::BinaryHeap, io::{stdout, BufWriter, Write, Read}};

// 주어지는 token을 두 개의 heap에 반 씩 나누어 저장
// 1. max_heap이 비어있으면 max_heap에 push
// 2. max_heap.peek와 token, min_heap.peek을 비교하여 max_heap.peek <= token <= min_heap.peek를 유지
// 3. 원소 수는 max_heap이 하나 더 많도록 저장(max_heap.peek가 medium)


fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    let input = input.trim();
    // println!("Input: {:?}", input);

    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<isize>);

    let n = input.next().unwrap() as usize;
    let arr:Vec<isize> = input.collect();
    let mut max_heap:BinaryHeap<isize> = BinaryHeap::new();
    let mut min_heap: BinaryHeap<Reverse<isize>> = BinaryHeap::new();

    for i in 0..n {
        if max_heap.is_empty() {
            max_heap.push(arr[i]);
        }
        else if *max_heap.peek().unwrap() < arr[i] {
            min_heap.push(Reverse(arr[i]));
            if max_heap.len() < min_heap.len() {
                let Reverse(temp) = min_heap.pop().unwrap();
                max_heap.push(temp);
            }
        }
        else {
            max_heap.push(arr[i]);
            if max_heap.len() == min_heap.len() + 2 {
                let temp = max_heap.pop().unwrap();
                min_heap.push(Reverse(temp));
            }
        }

        writeln!(writer, "{}", max_heap.peek().unwrap()).unwrap();
        // println!() macro는 내부적으로 매번 lock을 걸고 해제하며, 버퍼를 flush하므로 많은 출력에 대해서 오버헤드 발생 -> 시간초과
        // => writeln!() macro를 사용하여 버퍼를 저장하여 한 번에 flush하여 오버헤드 감소
    }
}
