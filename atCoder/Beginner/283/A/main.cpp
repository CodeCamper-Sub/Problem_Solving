#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll A, B;
    cin >> A >> B;
    ll answer = 1;
    for(ll i = 0; i < B; i++) {
        answer *= A;
    }
    cout << answer << '\n';

    return 0;
}