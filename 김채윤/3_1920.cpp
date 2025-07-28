#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int binary_search(vector<long long>& v, long long n) {
    int low = 0;
    int high = v.size() - 1;
    int idx = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (v[mid] == n) {
            idx = mid;
            break;
        }
        else if (n < v[mid]) high = mid - 1;
        else if (v[mid] < n) low = mid + 1;
    }
    if (idx == -1) return 0;
    else return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string s1, s2;
    cin >> N;
    cin.ignore();
    getline(cin, s1);
    cin >> M;
    cin.ignore();
    getline(cin, s2);

    vector<long long> v1;
    vector<long long> v2;

    istringstream iss1(s1);
    long long x1;
    while (iss1 >> x1)
        v1.push_back(x1);
    sort(v1.begin(), v1.end());

    istringstream iss2(s2);
    long long x2;
    while (iss2 >> x2)
        v2.push_back(x2);

    for (long long x : v2) {
        cout << binary_search(v1, x) << "\n";
    }

    return 0;
}