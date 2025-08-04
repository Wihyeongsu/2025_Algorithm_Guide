#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long arr[100] = {0};
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 1;

        for (int i = 3; i < N; i++) {
            arr[i] = arr[i - 3] + arr[i - 2];
        }
        cout << arr[N - 1] << "\n";
    }

    return 0;
}