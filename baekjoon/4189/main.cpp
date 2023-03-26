#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, m;
vector<ll> v;

void solve() {
  ll left = 0;
  ll right = 10000000;
  while(left <= right) {
    ll mid = (left + right) / 2;
    ll last_position = v[0] + mid;
    ll cnt = 1;
    for(ll i = 1; i < v.size(); i++) {
      if(v[i] - last_position > mid) {
        last_position = v[i] + mid;
        cnt++;
        if(cnt > n) break;
      }
    }
    if(cnt <= n) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << double(left) / double(10) << '\n';
}

void init() {
  v.clear();
  cin >> n >> m;
  v.resize(m);
  for(ll &i: v) {
    cin >> i;
    i *= 10;
  }
  sort(v.begin(), v.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed;
  cout.precision(1);

  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  
  return 0;
}