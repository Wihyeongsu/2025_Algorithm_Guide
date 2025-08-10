#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, max_weight = 0;
    cin >> n;

    vector<int> rope(n);
    for(int i = 0; i < n; i++)  
        cin >> rope[i];

    sort(rope.begin(), rope.end(), greater<int>());    

    // 물체의 최대 중량 구하기
    for(int i = 0; i < n; i++){
        if(max_weight < (i+1) * rope[i])
            max_weight = (i+1) * rope[i];
    }

    cout << max_weight << endl;

    return 0;
}
