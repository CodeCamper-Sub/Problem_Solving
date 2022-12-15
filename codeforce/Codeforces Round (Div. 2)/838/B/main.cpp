#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n;
ll arr[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    while(tt--) {
        cin >> n;
        vector<ll> v;
        for(ll i = 0; i < n; i++) {
            cin >> arr[i];
            v.push_back(i);
        }
        sort(v.begin(), v.end(), [](ll a, ll b) {
            return arr[a] < arr[b];
        });
        ll now = arr[v[0]];
        cout << v.size() - 1 << '\n';
        for(ll i = 1; i < v.size(); i++) {
            if(now < arr[v[i]]) {
                now = ((arr[v[i]] / now) + 1) * now;
            }
            cout << v[i] + 1 << ' ' << now-arr[v[i]] << '\n';
        }
    }

    return 0;
}