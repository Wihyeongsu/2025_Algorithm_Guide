#include <iostream>
#include <vector>

using namespace std;
const int INF = 10000;

int arr[5001][5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            arr[i][j] = (i == j ? 0 : INF);

    for (int j = 1; j <= M; j++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
    int rel[5001] = {0};
    int min = INF * N;
    int p = -1;
    for (int n = 1; n <= N; n++) {
        bool isConnected = true;
        for (int m = 1; m <= N; m++) {
            if (arr[n][m] == INF) {
                isConnected = false;
                break;
            }    
            rel[n] += arr[n][m];
        }
        if (min > rel[n] && isConnected) {
            min = rel[n];
            p = n;
        }
    }

    cout << p;

    return 0;
}