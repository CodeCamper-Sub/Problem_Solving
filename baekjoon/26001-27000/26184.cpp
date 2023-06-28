#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, k;
vector<set<ll>> e;
vector<bool> is_leaf;
vector<bool> visited;

void dfs(ll now, ll parent, ll& cnt, bool& has_cycle) {
  cnt++;
  for(ll next: e[now]) {
    if(now == next || parent == next) continue;
    if(!visited[next]) {
      visited[next] = true;
      dfs(next, now, cnt, has_cycle);
    } else {
      has_cycle = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  e.resize(k + 1);
  is_leaf.assign(k + 1, false);
  for(ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    e[a].insert(b);
    e[b].insert(a);
  }

  for(ll i = 1; i <= k; i++) {
    if(e[i].size() <= 1) is_leaf[i] = true;
  }

  for(ll i = 1; i <= k; i++) {
    if(e[i].size() <= 2) continue;
    ll cnt = 0;
    for(ll next: e[i]) {
      if(i == next) continue;
      if(!is_leaf[next]) cnt++;
    }
    if(cnt >= 3) {
      cout << "impossible\n";
      return 0;
    }
  }

  visited.assign(k + 1, false);
  ll all_cnt = k;
  for(ll i = 1; i <= k; i++) {
    if(e[i].size() == 0) all_cnt--;
  }

  for(ll i = 1; i <= k; i++) {
    if(!visited[i] && e[i].size()) {
      ll cnt = 0;
      bool has_cycle = false;
      visited[i] = true;
      dfs(i, -1, cnt, has_cycle);
      if(has_cycle && cnt != all_cnt) {
        cout << "impossible\n";
        return 0;
      }
    }
  }

  cout << "possible\n";
  
  return 0;
}