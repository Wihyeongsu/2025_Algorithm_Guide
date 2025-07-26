#include <iostream>
#include <vector>

using namespace std;
const long long MAX = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    
    vector<pair<int, int>> v[10001];
    
    for (int i = 0; i < N; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        if (e > D) continue;
        v[s].push_back({e, l});
    }
    for (int j = 0; j < D; j++) {
        v[j].push_back({j + 1, 1});
    }

    vector<int> d(D + 1, MAX);
    vector<int> visited(D + 1, 0);
    d[0] = 0;

    for (int k = 0; k <= D; k++) {
        int u = -1;
        int min = MAX;
        for (int l = 0; l <= D; l++) {
            if (visited[l] == 0 && d[l] < min) {
                min = d[l];
                u = l;
            }
        }

        if (u == -1) break;
        
        visited[u] = 1;

        for (auto [e, l] : v[u]) {
            if (d[e] > d[u] + l) 
                d[e] = d[u] + l;
        }
    }

    cout << d[D];

    return 0;
}