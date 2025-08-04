#include <iostream>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    long long A[10000];
    for (int i = 0; i < N; i++) cin >> A[i];

    long long count = 0;

    for (int j = N; j >= 2; j--) {
        for (int k = 0; k < j-1; k++) {
            if (A[k] > A[k + 1]) {
                count++;
                long long temp = A[k];
                A[k] = A[k + 1];
                A[k + 1] = temp;

                if (count == K) {
                    for (int i = 0; i < N; i++) 
                        cout << A[i] << " ";
                }
            }
        }
    }
    if (count < K) cout << -1;

    return 0;
}