#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> is_even(n);
        for(ll i = 0; i < n; i++) {
            cin >> v[i];
        }

        ll odd_cnt = 0;
        for(ll i = 0; i < n; i++) {
            if(v[i] % 2 == 0) {
                is_even[i] = true;
            } else {
                is_even[i] = false;
                odd_cnt++;
            }
        }
        if(odd_cnt % 2 == 0) {
            cout << 0 << '\n';
            continue;
        }
        ll answer = 0;
        ll flag = true;
        while(flag) {
            answer++;
            for(ll i = 0; i < n; i++) {
                if(v[i] % 2 == 0) {
                    if((v[i] / 2) % 2 == 1) {
                        flag = false;
                        break;
                    }
                } else {
                    if((v[i] / 2) % 2 == 0) {
                        flag = false;
                        break;
                    }
                }
                v[i] /= 2;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}