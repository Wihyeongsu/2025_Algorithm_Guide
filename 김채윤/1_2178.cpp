#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore();

    int arr[101][101];
    int visited[101][101] = {0};
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++) {
        string line;
        getline(cin, line);
        for (int j = 1; j <= M; j++) {
            arr[i][j] = line[j - 1] - '0';
        }
    }
    q.push({1, 1});
    visited[1][1] = 1;

    while (q.empty() == 0) {
        pair<int, int> p = q.front();
        int now_x = p.first;
        int now_y = p.second;
        q.pop();

        if (now_x == N && now_y == M) {
            cout << visited[now_x][now_y];
            return 0;
        }
        if (now_x - 1 >= 1 && visited[now_x - 1][now_y] == 0 && arr[now_x - 1][now_y] == 1) {
            q.push({now_x - 1, now_y});
            visited[now_x - 1][now_y] = visited[now_x][now_y] + 1;
        }
        if (now_x + 1 <= N && visited[now_x + 1][now_y] == 0 && arr[now_x + 1][now_y] == 1) {
            q.push({now_x + 1, now_y});
            visited[now_x + 1][now_y] = visited[now_x][now_y] + 1;
        }
        if (now_y - 1 >= 1 && visited[now_x][now_y - 1] == 0 && arr[now_x][now_y - 1] == 1) {
            q.push({now_x, now_y - 1});
            visited[now_x][now_y - 1] = visited[now_x][now_y] + 1;
        }
        if (now_y + 1 <= M && visited[now_x][now_y + 1] == 0 && arr[now_x][now_y + 1] == 1) {
            q.push({now_x, now_y + 1});
            visited[now_x][now_y + 1] = visited[now_x][now_y] + 1;
        }
    }

    return 0;
}