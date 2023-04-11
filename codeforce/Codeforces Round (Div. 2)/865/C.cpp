#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
}

void solve() {
  if(n % 2) {
    cout << "YES\n";
    return;
  }
  for(ll i = 0; i < n; i += 2) {
    if(a[i] == a[i + 1]) continue;
    else if(a[i] < a[i + 1] && i + 2 < n) {
      ll delta = a[i + 1] - a[i];
      a[i + 1] -= delta;
      a[i + 2] -= delta;
    } else if(a[i] > a[i + 1] && i + 2 < n) {
      ll delta = a[i] - a[i + 1];
      a[i + 1] += delta;
      a[i + 2] += delta;
    }
  }
  if(a[n - 2] <= a[n - 1]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  // bool is_valid = true;
  // for(ll i = 0; i < n - 1; i++) {
  //   if(a[i] > a[i + 1]) is_valid = false;
  // }

  // cout << (is_valid ? "YES" : "NO") << "\n";
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