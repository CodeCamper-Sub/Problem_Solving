#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, m, r, n;
vector<ll> x;
vector<pair<ll, ll>> v;

void init() {
  cin >> m >> r >> n;
  x.resize(n);
  v.clear();
  for(ll &x: x) {
    cin >> x;
    v.push_back({x - r, x + r});
  }
  sort(v.begin(), v.end());
}

void solve() {
  ll answer = 0;
  ll last = 0;
  bool is_impossible = false;
  for(ll i = 0; i < n; i++) {
    if(i < n - 1 && v[i + 1].first <= last) continue;
    if(last < v[i].first) {
      is_impossible = true;
      break;
    }
    answer++;
    last = v[i].second;
    if(last >= m) break;
  }
  if(is_impossible || last < m) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << answer << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for(ll i = 1; i <= tt; i++) {
    cout << "Case #" << i << ": ";
    init();
    solve();
  }
  return 0;
}