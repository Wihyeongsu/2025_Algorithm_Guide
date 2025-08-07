#include <iostream>
using namespace std;

const int MAX = 64;
int n;
int video[MAX][MAX];

void compress(int x, int y, int size){
    int first = video[x][y];
    bool same = true;

    // 현재 영역이 모두 같은 값인지 확인
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(video[i][j] != first){
                same = false;
                break;
            }
        }
        if(!same)  break;
    }

    if(same)  cout << first;
    else{
        cout << "(";

        int mid = size / 2;
        compress(x, y, mid);  // 왼쪽 위
        compress(x, y + mid, mid);  // 오른쪽 위
        compress(x + mid, y, mid);  // 왼쪽 아래
        compress(x + mid, y + mid, mid);  // 오른쪽 아래
        cout << ")";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            video[i][j] = s[j] - '0';
    }

    compress(0, 0, n);
    return 0;
}
