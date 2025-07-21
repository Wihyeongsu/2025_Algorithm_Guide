#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, top, current = 1;
    cin >> n;
    stack<int> s;
    vector<int> v(n);
    vector<char> chars;

    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 0; i < n; i++){

        // v[i]가 나올때까지 스택에 push
        while(current <= v[i]){
            s.push(current);
            chars.push_back('+');
            current++;
        }

        if(s.top() == v[i]){
            s.pop();
            chars.push_back('-');
        }
        else{
            cout << "NO" << "\n";
            return 0;
        }
    }

    for(char c : chars)
        cout << c << "\n";

    return 0;
}
