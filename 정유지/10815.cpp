#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    map<int, int> cards;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        cards[num] = 1;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        if(cards[num] == 1)  cout << 1 << " ";
        else  cout << 0 << " ";
    }
    cout << endl;

    return 0;
}
