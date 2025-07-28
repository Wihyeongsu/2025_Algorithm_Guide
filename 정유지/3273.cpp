#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, target, count = 0;
    cin >> n;
    set<int> sequence;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        sequence.insert(num);
    }
    cin >> target;

    for(auto it = sequence.begin(); it != sequence.end(); it++){
        int searchNum = target - *it;
        if(searchNum != *it && sequence.count(searchNum))  count++;
    }

    cout << count/2 << "\n";
    return 0;
}
