#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    // 동전 개수의 최솟값 계산
    int cnt = 0, sum = k;
    for(int i = 0; i < n; i++){
        if(sum == 0)  break;
        if(a[i] > k)  continue;

        cnt += sum / a[i];
        sum %= a[i];
    }

    cout << cnt << endl;

    return 0;
}
