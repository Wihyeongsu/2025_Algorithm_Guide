#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long a[1000];
    long long dp[1000];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    long long answer = dp[0];
    for (int i = 1; i < N; i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer;
    return 0;
}