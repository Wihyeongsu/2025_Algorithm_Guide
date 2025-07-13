#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    int arr[100001];
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    cin >> x;

    sort(arr, arr + n);

    int s = 0, e = n - 1, sumX = 0;
    int sum;

    while (e > s) {
        sum = arr[s] + arr[e];
        if (sum == x) {
            sumX++;
            s++;
            e--;
        }
        else if (sum > x) e--;
        else s++;
    }

    cout << sumX;

    return 0;
}