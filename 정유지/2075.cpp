#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소 힙

    for(int i = 0; i < n*n; i++){
        int num;
        cin >> num;
        pq.push(num);

        if(pq.size() > n)  pq.pop();  // 가장 작은 값 제거
    }

    cout << pq.top() << endl;

    return 0;
}
