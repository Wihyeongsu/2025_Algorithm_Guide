#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> friends(n+1, vector<int>(n+1, INF));

    // 자기 자신
    for(int i = 1; i <= n; i++)
        friends[i][i] = 0;

    // 친구 관계 입력
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        friends[a][b] = friends[b][a] = 1;
    }

    // 플로이드-와샬
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(friends[i][j] > friends[i][k] + friends[k][j])
                    friends[i][j] = friends[i][k] + friends[k][j];
            }

    // 케빈 베이컨 수 계산
    int min_person = 0, min = INF;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++)
            sum += friends[i][j];

        if(sum < min){
            min = sum;
            min_person = i;
        }
    }

    cout << min_person << endl;
        
    return 0;
}
