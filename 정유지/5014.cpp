#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000001;
int f, s, g, u, d;
bool visited[MAX];  // 방문 여부 확인
int steps[MAX];  // 각 층에 도달하기 위한 단계

// 너비 우선 탐색
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    steps[start] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        int next[] = {current-d, current+u};
        for(int n : next){
            if(n >= 1 && n <= f && !visited[n]){
                visited[n] = true;
                steps[n] = steps[current] + 1; 
                q.push(n);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    bfs(s);

    if(visited[g])  cout << steps[g]-1 << "\n";
    else  cout << "use the stairs\n";
    
    return 0;
}
