#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> field;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int m, n, k;

// 인접 좌표 확인 함수
void adj(int dij_x, int dij_y){
    if(dij_x >= 0 && dij_x < m && dij_y >= 0 && dij_y < n){
        if(field[dij_y][dij_x] == 1 && !visited[dij_y][dij_x]){
            visited[dij_y][dij_x] = true;
            q.push({dij_x, dij_y});
        }
    }
}

// 너비 우선 탐색 함수
void bfs(int x, int y){
    q.push({x, y});
    visited[y][x] = true;

    while(!q.empty()){
        pair<int, int> p = q.front();
        x = p.first;
        y = p.second;
        q.pop();

        adj(x, y-1);  // 좌
        adj(x, y+1);  // 우
        adj(x-1, y);  // 상
        adj(x+1, y);  // 하
    }
}

// 최소의 배추흰지렁이 마리 수 반환 함수
int minium_worm(void){
    int count = 0;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(field[y][x] == 1 && !visited[y][x]){
                bfs(x, y);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> m >> n >> k;

        field.assign(n, vector<int>(m, 0));
        visited.assign(n, vector<bool>(m, false));

        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        cout << minium_worm() << "\n";
    }

    return 0;
}
