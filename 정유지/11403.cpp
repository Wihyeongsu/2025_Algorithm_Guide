#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int graph[MAX][MAX] = {0,};

    // 인접행렬 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int edge;
            cin >> edge;
            graph[i][j] = edge;
        }
    }

    // 플로이드 와샬 알고리즘
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(graph[i][k] == 1 && graph[k][j] == 1)  graph[i][j] = 1;

    // 인접행렬 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
        
    return 0;
}
