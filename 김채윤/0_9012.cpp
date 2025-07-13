#include <iostream>

using namespace std;

void isVPS(string s) {
    int n = s.length();
    int m = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(' && m == 0) {
            cout << "NO" << "\n";
            return;
        }
        else if (s[i] == '(' && m > 0) m--;
        else m++;
    }
    if (m == 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    int t;
    cin >> t;
    string s;
    
    for (int i = 0; i < t; i++) {
        cin >> s;
        isVPS(s);
    }

    return 0;
}