#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;  

// 깊이 우선 탐색 함수
void dfs(int v){
    cout << v << " ";  // 시작 정점 방문
    visited[v] = true;

    for(int next : graph[v])  // 인접 정점들에 대해서
        if(!visited[next])   // 아직 방문하지 않은 경우
            dfs(next);  
}

// 너비 우선 탐색 함수
void bfs(int v){
    queue<int> q;
    q.push(v);  // 큐에 push
    visited[v] = true;  // 시작 정점 방문 

    while(!q.empty()){  // 큐가 공백이 아닐동안
        int current = q.front();  // 가장 최근에 방문했던 정점을 현재 정점으로
        q.pop();
        cout << current << " ";

        for(int next : graph[current])  // 인접 정점들에 대하여
            if(!visited[next]){  // 아직 방문하지 않은 경우
                visited[next] = true;  // 방문 처리
                q.push(next);  // 큐에 push
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    graph.resize(n+1);  

    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    // 작은 번호부터 탐색하기 위해 정렬
    for(int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    visited.assign(n+1, false);
    dfs(v);
    cout << endl;

    visited.assign(n+1, false);
    bfs(v);
    cout << endl;

    return 0;
}
