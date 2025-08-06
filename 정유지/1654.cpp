#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MAX = pow(2, 31);
vector<int> cable;

// 랜선 자르기
int cut_cable(int middle){
    int count = 0;
    for(int i = 0; i < cable.size(); i++){
        count += cable[i] / middle;
    }

    return count;
}

int max_length(int n){
    long long left = 1, right = MAX, answer = 0;

    // 이분 탐색
    while(left <= right){
        long long middle = (left + right) / 2;
        int count = cut_cable(middle);

        // 개수가 충분하면 오른쪽 탐색, 부족하면 왼쪽 탐색
        if(count >= n){
            answer = middle;
            left = middle + 1;
        }
        else   
            right = middle - 1;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        cable.push_back(x);
    }

    cout << max_length(n) << "\n";

    return 0;
}
