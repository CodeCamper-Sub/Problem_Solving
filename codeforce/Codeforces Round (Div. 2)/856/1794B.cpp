#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) { 
    cin >> a;
    if(a == 1) a++;
  }
}

void solve() {
  for(ll i = 0; i < n - 1; i++) {
    if(a[i + 1] % a[i]) continue;
    a[i + 1]++;
  } 
  for(ll i = 0; i < n; i++) {
    cout << a[i] << ' ';
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