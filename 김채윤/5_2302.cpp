#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibo(int n) {
    if (n <= 1) return 1;
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int N;
    cin >> N;
    int M;
    cin >> M;

    int arr[41] = {0};
    vector<long long> v;
    long long answer = 1;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        arr[x] = 1;
    }

    int count = 0;
    for (int j = 1; j <= N; j++) {
        if (arr[j] != 1) count++;
        else {
            v.push_back(fibo(count));
            count = 0;
        }
    }
    if (count) 
        v.push_back(fibo(count));

    for (int k = 0; k < v.size(); k++) {
        answer *= v[k];
    }

    cout << answer;

    return 0;
}