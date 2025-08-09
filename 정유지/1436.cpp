#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, count = 0, i = 666;

    cin >> n;

    while(true){
        string s = to_string(i);
        if(s.find("666") != string::npos){
            count++;
            if(count == n){
                cout << i << endl;
                break;
            }
        }
        i++;
    }

    return 0;
}
