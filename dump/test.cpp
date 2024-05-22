#include <bits/stdc++.h>
using namespace std;
void dp(int a, int b, int c, int d) {
    if(a == -1) dp(1, b, c, d), dp(0, b, c, d);
    else if(b == -1) dp(a, 0, c, d), dp(a, 1, c, d);
    else if(c == -1) dp(a, b, 0, d), dp(a, b, 1, d);
    else if(d == -1) dp(a, b, c, 0), dp(a, b, c, 1);
    else {
        if((a || !d) && (!a || b) && (!b || c) && (!a || !b || !c) && (a || !c || d)) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        return;
    }
}
int main(){
    dp(-1, -1, -1, -1);
}