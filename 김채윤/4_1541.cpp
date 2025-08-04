#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> plus;
    vector<int> minus;
    bool isPlus = true;

    int sum = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '+') {
            if (isPlus) plus.push_back(sum);
            else minus.push_back(sum);
            sum = 0;
        }
        else if (S[i] == '-') {
            if (isPlus) plus.push_back(sum);
            else minus.push_back(sum);
            sum = 0;
            isPlus = false;
        }
        else {
            sum = sum * 10 + (S[i] - '0');
        }
    }
    if (isPlus) plus.push_back(sum);
    else minus.push_back(sum);

    int count = 0;
    for (int j = 0; j < plus.size(); j++)
        count += plus[j];
    for (int k = 0; k < minus.size(); k++)
        count -= minus[k];

    cout << count;

    return 0;
}