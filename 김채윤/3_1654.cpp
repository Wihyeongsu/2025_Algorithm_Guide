#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCut(long long mid, vector<long long>& v, long long n) {
    long long count = 0;

    for (int x : v) {
        count += (x / mid);
    }
    return count >= n;
}

long long binary_search(long long low, long long high, long long n, vector<long long>& v) {
    long long max = 0;

    while (low <= high) {
        long long mid = (high + low) / 2;

        if (canCut(mid, v, n)) {
            max = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return max;
}

int main() {
    int K;
    long long N;
    cin >> K >> N;

    vector<long long> v(K);
    long long max = 0;

    for (int i = 0; i < K; i++) {
        cin >> v[i];
        if (max < v[i]) max = v[i];
    }
    
    cout << binary_search(1, max, N, v);

    return 0;
}