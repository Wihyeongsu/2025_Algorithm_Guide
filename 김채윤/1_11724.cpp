#include <iostream>

using namespace std;

int arr[1001][1001] = {0};
int visited[1001] = {0};
int n, m;

void DFS(int v) {
    visited[v] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (arr[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    int connected = 0;
    for (int j = 1; j <= n; j++) {
        if (visited[j] != 1) {
            DFS(j);
            connected++;
        }
    }
    cout << connected;

    return 0;
}