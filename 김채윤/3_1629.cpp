#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;
    
    long long mux = 1;

    if (A == 1 || B == 0) cout << 1 % C;
    else {
        A %= C;

        while (B > 0) {
            if (B % 2 == 1) {
                mux = mux * A % C;
            }
            A = A * A % C;
            B /= 2;
        }
        cout << mux;
    }
    return 0;
}

// (A×B)%C는 ((A%C) × (B%C))%C