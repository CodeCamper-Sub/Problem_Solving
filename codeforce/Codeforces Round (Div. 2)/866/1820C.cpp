#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n;
vector<ll> a;
map<ll, ll> m;

void init() {
  cin >> n;
  a.resize(n);
  m.clear();
  for(ll& a: a) cin >> a;
}

void solve() {
  ll mex = 0;
  for(ll i = 0; i < n; i++) {
    m[a[i]]++;
  }
  for(auto [k, v]: m) {
    if(mex == k) mex++;
  }
  if(m.find(mex + 1) == m.end()) {
    for(auto [k, v]: m) {
      if(v >= 2 || k >= mex + 2) {
        cout << "Yes\n";
        return;
      }
    }
    cout << "No\n";
    return;
  }
  ll l, r;
  for(ll i = 0; i < n; i++) {
    if(a[i] == mex + 1) {
      l = i;
      break;
    }
  }
  for(ll i = n - 1; i >= 0; i--) {
    if(a[i] == mex + 1) {
      r = i;
      break;
    }
  }
  for(ll i = l; i <= r; i++) {
    m[a[i]]--;
    if(m[a[i]] == 0) {
      m.erase(a[i]);
    }
  }
  ll mex_2 = 0;
  for(auto [k, v]: m) { 
    if(mex_2 == k) mex_2++;
  }
  if(mex == mex_2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}