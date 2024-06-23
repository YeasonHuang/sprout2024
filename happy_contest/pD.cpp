#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int g(int x);
int f(int x) {
    cnt ++;
    if(x == 0) return 1;
    return g(x + x / 2);
}
int g(int x) {
    cnt++;
    return f(x / 2);
}

int main() {
    f(20240622);
    cout << cnt << '\n';
}