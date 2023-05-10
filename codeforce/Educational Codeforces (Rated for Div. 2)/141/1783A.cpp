#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
bool all_same = true;

void init() {
  cin >> n;
  a.resize(n);
  
  for(ll& a: a) {
    cin >> a;
  }
}

void solve() {
  sort(a.begin(), a.end(), greater<>());
  all_same = true;
  for(ll i = 1; i < n; i++) {
    if(a[i] != a[i - 1]) {
      all_same = false;
      break;
    }
  }
  if(all_same) {
    cout << "NO\n";
    return;
  }
  if(a[0] == a[1]) {
    for(ll j = 2; j < n; j++) {
      if(a[j] != a[0]) {
        swap(a[1], a[j]);
        break;
      }
    }
  }
  cout << "YES\n";
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