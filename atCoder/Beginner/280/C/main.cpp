#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S, T;
    cin >> S >> T;
    ll found = -1;
    for(ll i = 0; i < S.size(); i++) {
        if(S[i] != T[i]) {
            found = i+1;
            break;
        }
    }
    if(found == -1){
        cout << T.size() << '\n';
    } else {
        cout << found << '\n';
    }

    return 0;
}