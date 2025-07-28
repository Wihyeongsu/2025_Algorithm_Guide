#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;
vector<int> adj[MAX];  // 인접 리스트 이용
bool visited[MAX];

// 깊이 우선 탐색 함수
void dfs(int v){
    visited[v] = true;

    for(int n : adj[v]){
        if(!visited[n])
            dfs(n);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
