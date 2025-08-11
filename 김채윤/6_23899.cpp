#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long A[10001], B[10001];

    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int j = 1; j <= N; j++) cin >> B[j];

    bool isSame = true;
    for (int j = 1; j <= N; j++) {
        if (A[j] != B[j]) {
            isSame = false;
            break;
        }
    }
    if (isSame) {
        cout << 1;
        return 0;
    }
    
    for (int last = N; last >= 2; last--) {
        int max_idx = 1;
        
        for (int i = 2; i <= last; i++) 
            if (A[i] > A[max_idx]) max_idx = i;
        
        if (last != max_idx) {
            long long temp = A[last];
            A[last] = A[max_idx];
            A[max_idx] = temp;
        }

        bool isSame = true;
        for (int j = 1; j <= N; j++) {
            if (A[j] != B[j]) {
                isSame = false;
                break;
            }
        }

        if (isSame) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}