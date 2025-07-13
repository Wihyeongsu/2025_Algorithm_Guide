#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, m, v;
int arr[1001][1001] = {0};
int visited[1001] = {0};

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 1; i <= n; i++) {
        if (arr[v][i] == 1 && visited[i] == 0)
            DFS(i);
        if (i == n) return;
    }
}

void BFS(int v) {
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
        int next = q.front();
        visited[next] = 1;
        cout << next << " ";
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (arr[next][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int a, b;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    DFS(v);
    cout << endl;
    memset(visited, 0, sizeof(visited));

    BFS(v);
    return 0;
}