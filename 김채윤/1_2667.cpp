#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[26][26];
int visited[26][26] = {0};
int home[626] = {0};
int a = -1;

void DFS(int u, int v) {
    visited[u][v] = 1;
    home[a]++;
    if (u - 1 >= 0 && arr[u - 1][v] == 1 && visited[u - 1][v] == 0)
        DFS(u - 1, v);
    if (u + 1 < n && arr[u + 1][v] == 1 && visited[u + 1][v] == 0)
        DFS(u + 1, v);
    if (v - 1 >= 0 && arr[u][v - 1] == 1 && visited[u][v - 1] == 0)
        DFS(u, v - 1);
    if (v + 1 < n && arr[u][v + 1] == 1 && visited[u][v + 1] == 0)
        DFS(u, v + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            arr[i][j] = line[j] - '0';
        }
    }
    for (int l = 0; l < n; l++) {
        for (int m = 0; m < n; m++) {
            if (arr[l][m] == 1 && visited[l][m] == 0) {
                a++;
                DFS(l, m);
            }
        }
    }
    cout << a + 1 << "\n";

    sort(home, home + a + 1);

    for (int j = 0; j <= a; j++) {
        cout << home[j] << "\n";
    }

    return 0;
}