#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        vector<long long> v(N);
        long long profit = 0;
        long long max = 0;

        for (int i = 0; i < N; i++) 
            cin >> v[i];

        for (int j = N - 1; j >= 0; j--) {
            if (max < v[j]) max = v[j];
            else profit += max - v[j];
        }
        cout << profit << "\n";
    }

    return 0;
}
