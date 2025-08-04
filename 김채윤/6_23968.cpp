#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long K;
    cin >> K;
    
    long long arr[10000];

    for (int i = 0; i < N; i++) cin >> arr[i];

    long long count = 0;

    for (int j = N; j >= 2; j--) {
        for (int k = 0; k < j-1; k++) {
            if (arr[k] > arr[k + 1]) {
                long long a = arr[k];
                long long b = arr[k + 1];
                count++;

                if (count == K) {
                    if (a < b) cout << a << " " << b;
                    else cout << b << " " << a;
                    return 0;
                }
                long long temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
    if (count < K) cout << -1;

    return 0;
}