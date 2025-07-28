#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    vector<long long> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    long long count = 0;

    for (int j = N - 1; j >= 0; j--) {
        if (K >= v[j]) {
            long long x = K / v[j];
            count += x;
            K -= v[j] * x;
        } else {
            continue;
        }
    }
    cout << count;

    return 0;
}