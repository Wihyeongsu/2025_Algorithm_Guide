#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int friends[MAX][MAX] = {0,};

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            friends[i][j] = (s[j] == 'Y') ? 1 : 0;
        }
    }

    
    int maxFriend = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            // 직접 친구인 경우
            if(friends[i][j] == 1)  count++; 
            else{
                for(int k = 0; k < n; k++){
                    // 간접 친구인 경우
                    if(friends[i][k] == 1 && friends[k][j] == 1){  
                        count++;
                        break;
                    }
                }
            }
        }
        maxFriend = max(maxFriend, count);
    }
        
    cout << maxFriend << endl;
    return 0;
}
