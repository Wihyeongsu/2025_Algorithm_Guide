#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void cantor(vector<string>& v, int s, int e) {
    int n = e - s + 1;
    if (n < 3) return;
    n = n / 3;
    for (int i = s + n; i < s + 2 * n; i++) {
        v[i] = " ";
    }
    cantor(v, s, s + n - 1);
    cantor(v, s + 2 * n, e);
}

int main() {
    int N;
    while (cin >> N) {
        int len = 1;
        for (int i = 0; i < N; ++i) len *= 3;

        vector<string> v(len, "-");
        cantor(v, 0, len - 1);
        
        for (auto& x : v) cout << x;
        cout << "\n";
    }

    return 0;
}