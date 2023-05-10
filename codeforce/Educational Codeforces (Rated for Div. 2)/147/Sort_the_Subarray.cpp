#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a1, a2;

void init() {
  cin >> n;
  a1.resize(n);
  a2.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a1[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> a2[i];
  }
}
void solve() {
  ll l = 0, r = n - 1;
  while(l < n && a1[l] == a2[l]) {
    l++;
  }
  while(r >= 0 && a1[r] == a2[r]) {
    r--;
  }
  sort(a1.begin() + l, a1.begin() + r + 1);
  while(l > 0 && a1[l - 1] <= a1[l]) {
    l--;
  }
  while(r < n - 1 && a1[r] <= a2[r + 1]) {
    r++;
  }
  cout << l + 1 << ' ' << r + 1 << '\n';
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