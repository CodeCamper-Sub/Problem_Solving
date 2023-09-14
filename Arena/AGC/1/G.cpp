#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, q;
vector<ll> l, dp;
map<ll, ll> a;

ll divide_conquer(ll x) {
  if(dp[x] != -1) return dp[x];
  if(a.count(x)) dp[x] = 1;
  else dp[x] = 0;

  if(x == 1) return dp[x];
  
  for(ll i = 1; i * i <= x; i++) {
    if(i == 1) {
      dp[x] += divide_conquer(1);
    } else if(i * i == x) {
      dp[x] += divide_conquer(i);
    } else if(x % i == 0) {
      dp[x] += divide_conquer(i);
      dp[x] += divide_conquer(x / i);
    }
  }

  return dp[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a[x]++;
  }

  cin >> q;
  l.resize(q);
  for(ll i = 0; i < q; i++) {
    cin >> l[i];
  }

  ll maxi = (*max_element(l.begin(), l.end())) + 1;
  dp.assign(maxi + 1, -1);

  for(ll i = 0; i < q; i++) {
    cout << divide_conquer(l[i]) << ' ';
  }

  
  return 0;
}