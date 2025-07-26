#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;

    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') s.push('(');
        else {
            s.pop();
            if (i != 0 && str[i - 1] == '(')
                count += s.size();
            else count++;
        }
    }

    cout << count;

    return 0;
}

/*
()(((()())(())()))(())

*/