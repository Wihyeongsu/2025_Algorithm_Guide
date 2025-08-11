#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int main() {
    int N;
    cin >> N;

    int num = 1;
    
    while (N != 0) {
        int arr[125][125];
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) cin >> arr[i][j];

        vector<vector<int>> D(N, vector<int>(N, INF));
        queue<pair<int, int>> q; 

        q.push({0, 0});
        D[0][0] = arr[0][0];

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            if (u + 1 < N) {
                int cost = D[u][v] + arr[u + 1][v];
                if (D[u + 1][v] > cost) {
                    D[u + 1][v] = cost;
                    q.push({u + 1, v});
                }
            }
            if (u - 1 >= 0) {
                int cost = D[u][v] + arr[u - 1][v];
                if (D[u - 1][v] > cost) {
                    D[u - 1][v] = cost;
                    q.push({u - 1, v});
                }
            }
            if (v + 1 < N) {
                int cost = D[u][v] + arr[u][v + 1];
                if (D[u][v + 1] > cost) {
                    D[u][v + 1] = cost;
                    q.push({u, v + 1});
                }
            }
            if (v - 1 >= 0) {
                int cost = D[u][v] + arr[u][v - 1];
                if (D[u][v - 1] > cost) {
                    D[u][v - 1] = cost;
                    q.push({u, v - 1});
                }
            }
        }
        
        cout << "Problem " << num << ": " << D[N - 1][N - 1] << "\n";
        num++;
        cin >> N;
    }

    return 0;
}