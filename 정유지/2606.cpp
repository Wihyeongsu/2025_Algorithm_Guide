#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;  
vector<bool> visited;  

// 너비 우선 탐색 함수
int bfs(int v){
    int infection = 0;
    queue<int> q;
    q.push(v);  // 큐에 push
    visited[v] = true;  // 시작 정점 방문 

    while(!q.empty()){  // 큐가 공백이 아닐동안
        int current = q.front();  // 다음으로 방문할 정점 
        q.pop();
        infection++;

        for(int next : graph[current])  // 인접 정점들에 대하여
            if(!visited[next]){  // 아직 방문하지 않은 경우
                visited[next] = true;  // 방문 처리
                q.push(next);  // 큐에 push
            }

          
    }

    return infection;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, linkage;
    cin >> n >> linkage;

    graph.assign(n+1, vector<int>());  // 그래프 초기화
    visited.assign(n+1, false);  // 방문 여부 벡터 초기화

    for(int i = 0; i < linkage; i++){
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());

    int infection = bfs(1);

    cout << infection - 1 << endl;

    return 0;
}
