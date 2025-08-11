#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void cantor(string& s, int start, int length){   
    if(length == 1)  return;

    int middle = length / 3;
    // 가운데 구간 처리
    for(int i = start + middle; i < start + 2 * middle; i++)
        s[i] = ' ';

    cantor(s, start, middle);  // 왼쪽 구간 처리
    cantor(s, start + 2 * middle, middle);  // 오른쪽 구간 처리
}

string makeString(int len){
    string s = "";
    for(int i = 0; i < len; i++)
        s += "-";

    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    // 입력이 있는 동안
    while(cin >> n){
        int len = pow(3, n);

        string s = makeString(len);
        cantor(s, 0, len);
        
        cout << s << "\n";
    }

    return 0;
}
