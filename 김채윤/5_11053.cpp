#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[1000];
    long long dp[1000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int j = 1; j < N; j++) {
        for (int k = 0; k < j; k++) {
            if (arr[k] < arr[j]) {
                dp[j] = max(dp[j], dp[k] + 1);
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