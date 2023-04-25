#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, a, b, c;
vector<ll> k;

void init() {
  cin >> n >> m;
  k.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> k[i];
  }
  sort(k.begin(), k.end());
}

void solve() {
  for(ll i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if(c <= 0) {
      cout << "NO\n";
      continue;
    }
    ll mini = b - floor(sqrt(a * c) * 2.0);
    ll maxi = b + floor(sqrt(a * c) * 2.0);
    ll tmp = ll(sqrt(a * c) + 0.05);
    if(tmp * tmp == a * c) {
      mini = b - 2 * round(sqrt(a * c)) + 1;
      maxi = b + 2 * round(sqrt(a * c)) - 1;
    }
    auto min_iter = lower_bound(k.begin(), k.end(), mini);
    auto max_iter = upper_bound(k.begin(), k.end(), maxi);
    if(min_iter < max_iter) {
      cout << "YES\n";
      cout << *(min_iter) << '\n';
    } else {
      cout << "NO\n";
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}