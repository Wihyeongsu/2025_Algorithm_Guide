#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> roads[10001];  // 지름길 저장 벡터

    for(int i = 0; i < n; i++){
        int start, end, length;
        cin >> start >> end >> length;
        if(end <= d)
            roads[start].push_back({end, length});
    }

    vector<int> move(d+1, INF);  // 최소 이동 거리 벡터
    move[0] = 0;
    
    for(int i = 0; i <= d; i++){
        if(i > 0)
            move[i] = min(move[i], move[i-1] + 1);  // 직선으로 이동하는 경우
        for(auto &p : roads[i]){
            int e = p.first, l = p.second;
            move[e] = min(move[e], move[i] + l);  // 지름길로 이동
        }
    }

    cout << move[d] << endl;

    return 0;
}
