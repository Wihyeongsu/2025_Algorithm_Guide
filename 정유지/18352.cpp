#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<int>> graph(n+1);
    vector<int> distance(n+1, -1);
    set<int> k_city;

    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    // bfs
    queue<int> q;
    q.push(x);
    distance[x] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int next : graph[current]){
            if(distance[next] == -1){
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    // 거리가 k인 도시 찾기
    for(int i = 1; i <= n; i++){
        if(distance[i] == k)
            k_city.insert(i);
    }

    // 출력
    if(k_city.empty())  cout << -1 << "\n";
    else  
        for(int c : k_city)  cout << c << "\n";


    return 0;
}
