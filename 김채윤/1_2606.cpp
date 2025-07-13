#include <iostream>

using namespace std;

int c, cg;
int arr[101][101] = {0};
int visited[101] = {0};

void DFS(int v) {
    visited[v] = 1;

    for (int i = 1; i <= c; i++) {
        if (arr[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    cin >> c;
    cin >> cg;

    int a, b;
    for (int i = 0; i < cg; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    DFS(1);

    int sum = -1;
    for (int j = 1; j <= c; j++) {
        if (visited[j] == 1)
            sum++;
    }
    cout << sum;

    return 0;
}