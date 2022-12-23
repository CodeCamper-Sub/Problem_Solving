#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    ll s[20], a[20];

    cin >> N;
    for(ll i = 0; i < N; i++) {
        cin >> s[i];
        if(i > 0) {
            a[i] = s[i] - s[i-1];
        } else {
            a[i] = s[i];
        }
    }

    for(ll i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}