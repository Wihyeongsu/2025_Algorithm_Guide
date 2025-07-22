#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<char> bars;
    string s;
    char symbol;
    int count = 0;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        symbol = s[i];

        if(symbol == '(')  bars.push(symbol);
        else{
            bars.pop();

            if(s[i-1] == '(')  count += bars.size();
            else  count += 1;
        }
    }

    cout << count << endl;

    return 0;
}
