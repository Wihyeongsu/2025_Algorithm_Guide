#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    long long max = 0;

    for (int i = 0; i < N; i++) 
        cin >> v[i];
    sort(v.begin(), v.end(), greater<>());

    for (int j = 0; j < N; j++) {
        long long able = v[j] * (j + 1);
        if (able > max) max = able;
    }
    cout << max;

    return 0;
}