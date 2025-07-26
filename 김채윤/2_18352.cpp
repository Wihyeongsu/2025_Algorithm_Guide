#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 300000; // 무한대값

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<vector<int>> list(N + 1); // 인접 리스트
    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        list[A].push_back(B);
    }

    vector<int> D(N + 1, MAX); // 최단 거리 저장
    queue<int> q; // BFS 수행 위한 큐

    D[X] = 0; // 출발 도시 X 최단 거리 0으로 저장
    q.push(X); // X 큐에 삽입

    while (!q.empty()) { // 큐가 빌 때까지 반복
        int u = q.front(); // 현재 탐색 중인 도시 큐에서 꺼내기
        q.pop();
        for (int v : list[u]) {   // u번 도시의 모든 인접 도시 v 순회    
        if (D[v] == MAX) {       
            D[v] = D[u] + 1;
            q.push(v); // 다음에 v의 이웃을 탐색하기 위해 큐에 삽입
        }
    }
    }

    bool found = false;
    for (int k = 1; k <= N; k++) {
        if (D[k] == K) {
            cout << k << "\n";
            found = true;
        }
    }
    if (found == false) cout << -1;

    return 0;
}