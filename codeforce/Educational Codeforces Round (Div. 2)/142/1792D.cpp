#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<ll>> p, inv;

void init() {
  cin >> n >> m;
  p.assign(n, vector<ll>(m));
  inv.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> p[i][j];
      p[i][j] -= 1;
      inv[i][p[i][j]] = j;
    }
  }
}

ll back_tracking(ll k, ll now, ll left, ll right) {
  if(now == m) return 0;
  ll l = left, r = right;
  // p[k][now]를 찾아야 함
  // 다음 왼쪽 찾기
  while(l <= r) {
    ll mid = (l + r) / 2;
    if(inv[mid][now] < p[k][now]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  ll next_left = l;
  // 다음 오른쪽 찾기
  l = left, r = right;
  while(l <= r) {
    ll mid = (l + r) / 2;
    if(p[k][now] < inv[mid][now]) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  ll next_right = r;
  if(next_left <= next_right) {
    return 1 + back_tracking(k, now + 1, next_left, next_right);
  } else {
    return 0;
  }
}

void solve() {
  sort(inv.begin(), inv.end());
  for(ll i = 0; i < n; i++) {
    cout << back_tracking(i, 0, 0, n - 1) << ' ';
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