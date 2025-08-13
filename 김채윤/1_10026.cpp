#include <iostream>
using namespace std;

void DFS(string arr[][100], int visited[][100], int u, int v, int N) {
    visited[u][v] = 1;

    string s = arr[u][v];
    if (u - 1 >= 0 && arr[u - 1][v] == s && visited[u - 1][v] == 0)
        DFS(arr, visited, u - 1, v, N);
    if (u + 1 < N && arr[u + 1][v] == s && visited[u + 1][v] == 0)
        DFS(arr, visited, u + 1, v, N);
    if (v - 1 >= 0 && arr[u][v - 1] == s && visited[u][v - 1] == 0)
        DFS(arr, visited, u, v - 1, N);
    if (v + 1 < N && arr[u][v + 1] == s && visited[u][v + 1] == 0)
        DFS(arr, visited, u, v + 1, N);
}

int main() {
    int N;
    string arrN[100][100];
    string arrY[100][100];
    int visitedN[100][100] = {0};
    int visitedY[100][100] = {0};

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            arrN[i][j] = s[j];
            if (s[j] == 'R' || s[j] == 'G') arrY[i][j] = 'G';
            else arrY[i][j] = s[j];
        }
    }
    int countN = 0;
    int countY = 0;

    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (!visitedN[j][k]) {
                countN++;
                DFS(arrN, visitedN, j, k, N);
            }
            if (!visitedY[j][k]) {
                countY++;
                DFS(arrY, visitedY, j, k, N);
            }
        }
    }
    cout << countN << " " << countY;

    return 0;
}