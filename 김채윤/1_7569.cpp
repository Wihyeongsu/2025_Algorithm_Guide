#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void BFS(vector<vector<vector<int>>>& box, vector<vector<vector<int>>>& visited, queue<tuple<int, int, int>>& q, int H, int N, int M) {
    while(!q.empty()) {
        int nextH, nextU, nextV;
        tie(nextH, nextU, nextV) = q.front();
        q.pop();

        if (nextU - 1 >= 0 && box[nextH][nextU - 1][nextV] == 0 && visited[nextH][nextU - 1][nextV] == 0) {
            q.push({nextH, nextU - 1, nextV});
            visited[nextH][nextU - 1][nextV] = visited[nextH][nextU][nextV] + 1;
        }
        if (nextU + 1 < N && box[nextH][nextU + 1][nextV] == 0 && visited[nextH][nextU + 1][nextV] == 0) {
            q.push({nextH, nextU + 1, nextV});
            visited[nextH][nextU + 1][nextV] = visited[nextH][nextU][nextV] + 1;
        }
        if (nextV - 1 >= 0 && box[nextH][nextU][nextV - 1] == 0 && visited[nextH][nextU][nextV - 1] == 0) {
            q.push({nextH, nextU, nextV - 1});
            visited[nextH][nextU][nextV - 1] = visited[nextH][nextU][nextV] + 1;
        }   
        if (nextV + 1 < M && box[nextH][nextU][nextV + 1] == 0 && visited[nextH][nextU][nextV + 1] == 0) {
            q.push({nextH, nextU, nextV + 1});
            visited[nextH][nextU][nextV + 1] = visited[nextH][nextU][nextV] + 1;
        }
        if (nextH - 1 >= 0 && box[nextH - 1][nextU][nextV] == 0 && visited[nextH - 1][nextU][nextV] == 0) {
            q.push({nextH - 1, nextU, nextV});
            visited[nextH - 1][nextU][nextV] = visited[nextH][nextU][nextV] + 1;
        }
        if (nextH + 1 < H && box[nextH + 1][nextU][nextV] == 0 && visited[nextH + 1][nextU][nextV] == 0) {
            q.push({nextH + 1, nextU, nextV});
            visited[nextH + 1][nextU][nextV] = visited[nextH][nextU][nextV] + 1;
        }
    }
}

int main() {
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<tuple<int, int, int>> q;

    bool isTomato = true;
    for (int i = 0; i < H; i++) 
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push({i, j, k});
                    visited[i][j][k] = 1;
                }
                if (box[i][j][k] == 0) isTomato = false;
            }
    
    if (isTomato) {
        cout << 0;
        return 0;
    }

    BFS(box, visited, q, H, N, M);

    int max = 0;
    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (box[k][i][j] == 0 && visited[k][i][j] == 0) {
                    cout << -1;
                    return 0;
                }
                if (max < visited[k][i][j]) max = visited[k][i][j];
            }

    cout << max - 1;

    return 0;
}