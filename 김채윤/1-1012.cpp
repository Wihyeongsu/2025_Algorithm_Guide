#include <iostream>

using namespace std;

int arr[51][51];
int visited[51][51];
int m, n;

void DFS(int u, int v) {
    visited[u][v] = 1;
    if (u - 1 >= 0 && arr[u - 1][v] == 1 && visited[u - 1][v] == 0)
        DFS(u - 1, v);
    if (u + 1 < m && arr[u + 1][v] == 1 && visited[u + 1][v] == 0)
        DFS(u + 1, v);
    if (v - 1 >= 0 && arr[u][v - 1] == 1 && visited[u][v - 1] == 0)
        DFS(u, v - 1);
    if (v + 1 < n && arr[u][v + 1] == 1 && visited[u][v + 1] == 0)
        DFS(u, v + 1);
}

int main() {
    int t, k, x, y;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                arr[a][b] = 0;
                visited[a][b] = 0;
            }
        }
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        int sum = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (arr[row][col] == 1 && visited[row][col] == 0) {
                    sum++;
                    DFS(row, col);
                }
            }
        }

        cout << sum << "\n";
    }

    return 0;
}