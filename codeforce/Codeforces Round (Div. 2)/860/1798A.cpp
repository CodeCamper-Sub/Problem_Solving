#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b;

void init() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> b[i];
  }
}

void solve() {
  if(a.back() > b.back()) swap(a, b);
  for(ll i = 0; i < n; i++) {
    if(a[i] > b[i]) swap(a[i], b[i]);
  }
  for(ll i = 0; i < n; i++) {
    if(a[i] > a.back() || b[i] > b.back()) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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