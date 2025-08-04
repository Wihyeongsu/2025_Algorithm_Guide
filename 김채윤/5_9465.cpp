#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        long long arr[2][100000];
        long long dp[2][100000] = {0};

        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];

        if (n > 1) {
            dp[0][1] = dp[1][0] + arr[0][1];
            dp[1][1] = dp[0][0] + arr[1][1];
        }
        for (int j = 2; j < n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + arr[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + arr[1][j];
        }

        long long answer = max(dp[0][n - 1], dp[1][n - 1]);
        cout << answer << "\n";
    }

    return 0;
}