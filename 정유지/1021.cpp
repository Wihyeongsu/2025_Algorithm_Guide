#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for(int i = 1; i <= n; i++)
        dq.push_back(i);
    int count = 0;

    for(int i = 0; i < m; i++){
        int target;
        cin >> target;   

        int index = 0;
        while(dq[index] != target)  index++;

        if(index <= dq.size() / 2){
            while(index != 0){
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
                index--;
            }
        }
        else{
            int cnt = dq.size() - index;
            while(cnt != 0){
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
                cnt--;
            }
        }

        dq.pop_front();
    }

    cout << count << "\n";

    return 0;
}
