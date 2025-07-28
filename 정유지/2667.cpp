#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 26;
int maps[MAX][MAX];  // 지도
vector<int> complexs;  // 단지 내 집 개수 저장 벡터
bool visited[MAX][MAX];
int n;

// 깊이 우선 탐색 함수
int dfs(int x, int y);
// 단지 찾는 함수
void isComplex(void);
// 방문 여부 확인 함수
bool isVisited(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(int j = 0; j < n; j++)
            maps[i][j] = s[j] - '0';
    }

    isComplex();

    return 0;
}

int dfs(int x, int y){
    int count = 1;
    visited[y][x] = true;

    if(isVisited(x, y-1))  count += dfs(x, y-1);  // 상
    if(isVisited(x, y+1))  count += dfs(x, y+1);  // 하
    if(isVisited(x-1, y))  count += dfs(x-1, y);  // 좌
    if(isVisited(x+1, y))  count += dfs(x+1, y);  // 우 

    return count;
}

void isComplex(void){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(maps[i][j] == 1 && !visited[i][j]){
                int count = dfs(j, i); // x == j, y == i
                complexs.push_back(count);
            }
        }             
    }

    sort(complexs.begin(), complexs.end());

    cout << complexs.size() << "\n";
    for(int c : complexs)
        cout << c << "\n";
}

bool isVisited(int x, int y){
    bool res = false;
    if(x >= 0 && x < n && y >= 0 && y < n && 
        maps[y][x] == 1 && !visited[y][x])
            res = true;

    return res;
}
