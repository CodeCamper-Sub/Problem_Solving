#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, k, sum;
ll arr[200200];
multiset<ll, greater<ll>> least;
multiset<ll> remain;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<ll> v;
    for(ll i = 1; i <= m; i++) {
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < k; i++) {
        least.insert(v[i]);
        sum += v[i];
    }

    for(ll i = k; i < v.size(); i++) {
        remain.insert(v[i]);
    }
    
    cout << sum << ' ';
    for(ll i = 2; i <= n - m + 1; i++) {
        if(arr[i-1] <= *(least.begin())) {
            least.erase(arr[i-1]);
            sum -= arr[i-1];
        }
    }

    return 0;
}