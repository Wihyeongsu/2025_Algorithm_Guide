#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int zero = 0, one = 0;

    if(s[0] == '0')  zero++;
    else  one++;

    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i-1]){
            if(s[i] == '0')  zero++;
            else  one++;
        }
    }

    int min = (zero < one) ? zero : one;

    cout << min << endl;
    
    return 0;
}
