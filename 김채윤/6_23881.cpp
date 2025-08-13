#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long A[10001];

    for (int idx = 1; idx <= N; idx++) cin >> A[idx];

    int count = 0;
    for (int last = N; last >= 2; last--) {
        int max_idx = 1;
        
        for (int i = 2; i <= last; i++) {
            if (A[i] > A[max_idx]) max_idx = i;
        }
        
        if (last != max_idx) {
            long long temp = A[last];
            A[last] = A[max_idx];
            A[max_idx] = temp;
            count++;
            if (count == K) {
                cout << A[max_idx] << " " << A[last];
                return 0;
            }
        }
    }
    if (count != K) cout << -1;


    return 0;
}