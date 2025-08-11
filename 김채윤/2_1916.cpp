#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    cin >> M;
    vector<pair<int, int>> v[N + 1];

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        v[A].push_back({B, C});
    }

    int S, E;
    cin >> S >> E;

    vector<int> D(N + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 우선순위 큐

    D[S] = 0;
    pq.push({0, S});

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

    cout << D[E] << "\n";
    
    return 0;
}