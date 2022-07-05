#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, r, c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int I = 1; I <= t; I++) {
        cout << "Case #" << I << ":" << '\n';
        cin >> r >> c;
        for(int i = 1; i <= r*2 + 1; i++) {
            for(int j = 1; j <= c*2 + 1; j++) {
                if(i <= 2 && j <= 2) {
                    cout << ".";
                } else if (i % 2 && j % 2) {
                    cout << "+";
                } else if (i % 2) {
                    cout << "-";
                } else if (i % 2 == 0 && j % 2) {
                    cout << "|";
                } else {
                    cout << ".";
                }
            }
            cout << '\n';
        }
    }
    return 0;
}