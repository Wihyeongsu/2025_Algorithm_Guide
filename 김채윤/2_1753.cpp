#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, K;
    cin >> V >> E;
    cin >> K;

    vector<pair<int, int>> v[V + 1];

    for (int i = 0; i < E; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        v[X].push_back({Y, Z});
    }

    vector<int> D(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    D[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist > D[now]) continue;

        for (auto [next, cost] : v[now]) {
            if (D[next] > D[now] + cost) {
                D[next] = D[now] + cost;
                pq.push({D[next], next});
            }
        }
    }

    for (int j = 1; j <= V; j++) {
        if (D[j] == INF) cout << "INF" << "\n";
        else cout << D[j] << "\n";
    }

    return 0;
}