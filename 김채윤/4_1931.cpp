#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, n;
int start, end, total;

void time(int &start, int &n, vector<pair<int, int>>& v) {
    if ((n >= N)) return;
    bool found = false;
    for (int i = n; i < N; i++) {
        if (start <= v[i].first) {
            total++;
            start = v[i].second;
            n = i + 1;
            found = true;
            break;
        }
    }
    if (!found) return; 
    time(start, n, v);
}

int main() {
    cin >> N;
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) 
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(),
    [](auto &a, auto &b) {
        if (a.second != b.second) 
            return a.second < b.second;
        return a.first < b.first;
    }); 

    start = 0;
    total = 0;
    n = 0;

    time(start, n, v);

    cout << total;

    return 0;
}