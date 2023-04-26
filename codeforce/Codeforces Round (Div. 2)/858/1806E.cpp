#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, q, x, y, sqrtN;
vector<ll> a, p, level, level_cnt, id;
vector<vector<ll>> table;
vector<vector<ll>> e;

void get_level(ll now) {
  for(ll next: e[now]) {
    level[next] = level[now] + 1;
    id[next] = ++level_cnt[level[next]];
    get_level(next);
  }
}

void init() {
  cin >> n >> q;
  sqrtN = sqrt(n) + 1;
  a.resize(n + 1);
  p.resize(n + 1);
  table.assign(n + 1, vector<ll>(sqrtN + 1, -1));
  level.resize(n + 1);
  id.resize(n + 1);
  level_cnt.resize(n + 1);
  e.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  p[1] = 0;
  for(ll i = 2; i <= n; i++) {
    cin >> p[i];
    e[p[i]].push_back(i);
  }
  level[1] = 0;
  get_level(1);
}

ll dfs(ll x, ll y) {
  if(x == 0 || y == 0) return 0;
  if(x > y) swap(x, y);
  if(level_cnt[level[x]] <= sqrtN && table[x][id[y]] != -1) {
    return table[x][id[y]];
  } else if(level_cnt[level[x]] <= sqrtN) {
    return table[x][id[y]] = dfs(p[x], p[y]) + a[x] * a[y];
  } else {
    return dfs(p[x], p[y]) + a[x] * a[y];
  }
}

void solve() {
  while(q--) {
    cin >> x >> y;
    cout << dfs(x, y) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  return 0;
}