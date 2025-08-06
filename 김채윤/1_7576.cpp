#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& mat, vector<vector<int>>& visited, queue<pair<int,int>>& q, int N, int M) {
    while(!q.empty()) {
        int nextU = q.front().first;
        int nextV = q.front().second;
        q.pop();

        if (nextU - 1 >= 0 && mat[nextU - 1][nextV] == 0 && visited[nextU - 1][nextV] == 0) {
            q.push({nextU - 1, nextV});
            visited[nextU - 1][nextV] = visited[nextU][nextV] + 1;
        }
        if (nextU + 1 < N && mat[nextU + 1][nextV] == 0 && visited[nextU + 1][nextV] == 0) {
            q.push({nextU + 1, nextV});
            visited[nextU + 1][nextV] = visited[nextU][nextV] + 1;
        }
        if (nextV - 1 >= 0 && mat[nextU][nextV - 1] == 0 && visited[nextU][nextV - 1] == 0) {
            q.push({nextU, nextV - 1});
            visited[nextU][nextV - 1] = visited[nextU][nextV] + 1;
        }   
        if (nextV + 1 < M && mat[nextU][nextV + 1] == 0 && visited[nextU][nextV + 1] == 0) {
            q.push({nextU, nextV + 1});
            visited[nextU][nextV + 1] = visited[nextU][nextV] + 1;
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N; 
    vector<vector<int>> mat(N, vector<int>(M));
    vector<vector<int>> visited(N, vector<int>(M));
    queue<pair<int, int>> q;

    bool isTomato = true;
    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < M; j++) { 
            cin >> mat[i][j];
            if (mat[i][j] == 0) isTomato = false;
            if (mat[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    if (isTomato) {
        cout << 0;
        return 0;
    }

    BFS(mat, visited, q, N, M);

    int max = 0;
    for (int i = 0; i < N; i++)     
        for (int j = 0; j < M; j++) { 
            if (mat[i][j] == 0 && visited[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (max < visited[i][j]) max = visited[i][j];
        }

    cout << max - 1;

    return 0;
}