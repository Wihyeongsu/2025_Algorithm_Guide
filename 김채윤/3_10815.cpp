#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& v, int n) {
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
    int N, M;
    cin >> N;
    string s1, s2;
    cin.ignore(); // 개행문자 삭제
    getline(cin, s1);
    cin >> M;
    cin.ignore(); 
    getline(cin, s2);

    vector<int> v1;
    vector<int> v2;

    istringstream iss1(s1); // 공백으로 구분된 문자열 나눠줌
    int x;
    while (iss1 >> x)
        v1.push_back(x);
    sort(v1.begin(), v1.end());

    istringstream iss2(s2);
    int y;
    while (iss2 >> y)
        v2.push_back(y);

    for (int x : v2) {
        cout << binary_search(v1, x) << " ";
    }

    return 0;
}