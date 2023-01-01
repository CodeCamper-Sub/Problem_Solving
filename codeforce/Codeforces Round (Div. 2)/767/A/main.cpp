#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll tt;
    cin >> tt;
    while(tt--){ 
        cin >> n >> k;
        vector<pair<ll, ll>> a = vector<pair<ll, ll>>();
        vector<ll> b = vector<ll>(n);
        for(ll i = 0; i < n; i++) {
            ll a_i;
            cin >> a_i;
            a.push_back({a_i, i});
        }
        for(ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        for(ll i = 0; i < a.size(); i++) {
            if(k >= a[i].first) {
                k += b[a[i].second];
            }
        }
        cout << k << '\n';
    }

    return 0;
}