#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    long long change1 = 0;
    long long change0 = 0;

    if (S[0] == '0') change0++;
    else change1++;

    for (int i = 1; i < S.length(); i++) {
        if (S[i] != S[i - 1]) {
            if (S[i - 1] == '0') change1++;
            else change0++;
        }
    }
    if (change1 > change0) cout << change0;
    else cout << change1;
    
    return 0;
}