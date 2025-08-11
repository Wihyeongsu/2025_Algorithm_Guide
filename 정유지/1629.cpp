#include <iostream>
using namespace std;

int remainder(int a, int b, int c){
    if(b == 0)  return 1;  // 0제곱은 1
    long remain = remainder(a, b/2, c);  // 분할 정복

    remain = (remain * remain) % c;  // b가 짝수인 경우
    if(b % 2 == 1)  remain = (remain * a) % c;  // b가 홀수인 경우

    return remain;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;

    cout << remainder(a, b, c) << "\n";

    return 0;
}
