#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define rep(i,b)for (int i = 0; i < b; ++i)
string a, b;
char s[40][40];
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    memset(s, '.', sizeof(s));
    cin >> a >> b;
    rep(i, a.length())
        rep(j, b.length())
            if (a[i] == b[j]) {
                rep(k, a.length()) s[j][k] = a[k];
                rep(q, b.length()) s[q][i] = b[q];
                rep(k, b.length()) {
                    rep(q, a.length()) cout << s[k][q];
                    cout <<endl;
                }
                return 0;
            }
    return 0;
}