#include <iostream>
#include <vector>
#include <deque>  
using namespace std;
const int INF = 1e9;

int main() {
    int M, N;
    cin >> M >> N;

    int arr[101][101];
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j - 1] == '0') arr[i][j] = 0;
            else if (s[j - 1] == '1') arr[i][j] = 1;
        }
    }

    vector<vector<int>> D(N + 1, vector<int>(M + 1, INF));
    deque<pair<int, int>> q;  

    q.push_front({1, 1});
    D[1][1] = 0;

    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop_front();

        if (u + 1 <= N) {
            int cost = D[u][v] + arr[u + 1][v];
            if (D[u + 1][v] > cost) {
                D[u + 1][v] = cost;
                if (arr[u + 1][v] == 0) q.push_front({u + 1, v});  
                else q.push_back({u + 1, v});
            }
        }
        if (u - 1 >= 1) {
            int cost = D[u][v] + arr[u - 1][v];
            if (D[u - 1][v] > cost) {
                D[u - 1][v] = cost;
                if (arr[u - 1][v] == 0) q.push_front({u - 1, v});
                else q.push_back({u - 1, v});
            }
        }
        if (v + 1 <= M) {
            int cost = D[u][v] + arr[u][v + 1];
            if (D[u][v + 1] > cost) {
                D[u][v + 1] = cost;
                if (arr[u][v + 1] == 0) q.push_front({u, v + 1});
                else q.push_back({u, v + 1});
            }
        }
        if (v - 1 >= 1) {
            int cost = D[u][v] + arr[u][v - 1];
            if (D[u][v - 1] > cost) {
                D[u][v - 1] = cost;
                if (arr[u][v - 1] == 0) q.push_front({u, v - 1});
                else q.push_back({u, v - 1});
            }
        }
    }

    cout << D[N][M];
    return 0;
}