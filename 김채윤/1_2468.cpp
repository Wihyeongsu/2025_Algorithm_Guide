#include <iostream>

using namespace std;

int n;
int arr[100][100] = {0};
int visited[100][100];

void DFS(int u, int v, int high) {
    visited[u][v] = 1;
    if (u - 1 >= 0 && arr[u - 1][v] > high && visited[u - 1][v] == 0) DFS(u - 1, v, high);
    if (u + 1 < n && arr[u + 1][v] > high && visited[u + 1][v] == 0) DFS(u + 1, v, high);
    if (v - 1 >= 0 && arr[u][v - 1] > high && visited[u][v - 1] == 0) DFS(u, v - 1, high);
    if (v + 1 < n && arr[u][v + 1] > high && visited[u][v + 1] == 0) DFS(u, v + 1, high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int high = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > high) high = arr[i][j];
        }
    }

    int max = 1;
    for (int j = 0; j < high; j++) {
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++)
                visited[k][l] = 0;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (arr[i][k] > j && visited[i][k] == 0) {
                DFS(i, k, j);
                sum++;
                }
            }
        }
    
        if (sum > max) max = sum;
    }

    cout << max;


    return 0;
}