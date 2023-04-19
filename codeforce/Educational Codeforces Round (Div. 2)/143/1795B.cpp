#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, l, r;

void init() {
  cin >> n >> k;  
}

void solve() {
  bool start_with_k = false;
  bool end_with_k = false;
  for(ll i = 0; i < n; i++) {
    cin >> l >> r;
    if(l == k) start_with_k = true;
    if(r == k) end_with_k = true;
  }

  if(start_with_k && end_with_k) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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