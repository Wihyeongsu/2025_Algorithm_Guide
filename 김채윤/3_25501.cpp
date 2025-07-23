#include <iostream>
#include <string>

using namespace std;

int n;

int recursion(const string& s, int l, int r) {
    n++;
    if (l >= r) {
        return 1;
    }
    else if (s[l] != s[r]) {
        return 0;
    }
    else {
        return recursion(s, l + 1, r - 1);
    }
}
int isPalindrome(const string& s){
    return recursion(s, 0, s.length()-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        n = 0;
        int m = isPalindrome(s);

        cout << m << " " << n << "\n";
    }

    return 0;
}