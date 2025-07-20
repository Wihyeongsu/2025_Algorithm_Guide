use std::io::Read;

// 괄호를 쌍으로 가지므로 길이가 짝수
// 한 쌍의 괄호를 child로 가지는 트리 형성

#[derive(Clone, Copy, Debug, PartialEq)]
enum Token{
    Parenthesis(char),
    SquareBracket(char),
    Eof
}

struct Lexer{
    tokens:Vec<Token>
}

impl Lexer {
    fn new(input: &str) -> Lexer {
        let mut tokens = input
        .chars()
        .map(|c| match c {
            '('|')' => Token::Parenthesis(c),
            '['|']' => Token::SquareBracket(c),
            _ => unreachable!()
        }).collect::<Vec<_>>();
        tokens.reverse();

        Lexer{ tokens }
    }

    fn next(&mut self) -> Token{
        self.tokens.pop().unwrap_or(Token::Eof)
    }

    fn peek(&self) -> Token{
        self.tokens.last().copied().unwrap_or(Token::Eof)
    }
}

fn parse(lexer: &mut Lexer, recent_token: &Token) -> (Token, usize){
    let mut sum = 0;
    loop {
        let lhs = match lexer.next() {
            Token::Eof => return (Token::Eof, sum), // End
            t @ Token::Parenthesis(')') => {
                if *recent_token == Token::Parenthesis('('){
                    return (t, sum);
                }else {
                    return (Token::Eof, 0);
                }
            },
            t @ Token::SquareBracket(']') => {
                if *recent_token == Token::SquareBracket('['){
                    return (t, sum);
                }else {
                    return (Token::Eof, 0);
                }
            },
            t => t,
        };
        let rhs= match lexer.peek() {
            Token::Parenthesis('(') | Token::SquareBracket('[') => {
                let rhs = match parse(lexer, &lhs) {
                    (t @ Token::Parenthesis(')'), v) => {
                        sum += 2 * v;
                        t
                    },
                    (t @ Token::SquareBracket(']'), v) =>{
                        sum += 3 * v;
                        t
                    },
                    _ => return (Token::Eof, 0), // upto different pair result
                };
                rhs
            },
            t @ Token::Parenthesis(')') => {
                lexer.next(); // consume
                sum += 2;
                t
            } 
            t @ Token::SquareBracket(']') => {
                lexer.next(); // consume
                sum += 3;
                t
            } 
            t => return (t, 0)
        };


        // different pair
        if !((lhs == Token::Parenthesis('(') && rhs == Token::Parenthesis(')')) 
        || (lhs == Token::SquareBracket('[') && rhs == Token::SquareBracket(']'))) {return (Token::Eof, 0);}
    }
}

fn main() {
    let input = {
        let mut buf = String::new();
        std::io::stdin().read_to_string(&mut buf).unwrap();
        buf
    };
    let input = input.trim();
    // println!("Input: {:?}", input);

    let result = if input.len() % 2 == 0 {
        let mut lexer = Lexer::new(input);
        let (_, result) = parse(&mut lexer, &Token::Eof);
        result
    } else{
        0
    };

    println!("{result}");

}
