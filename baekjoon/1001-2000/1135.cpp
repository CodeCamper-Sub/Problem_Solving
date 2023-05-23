#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<vector<ll>> e;

ll dfs(ll now) {
  vector<ll> childs;
  for(ll next: e[now]) {
    childs.push_back(dfs(next));
  }
  if(childs.empty()) return 0;
  ll result = 0;
  sort(childs.rbegin(), childs.rend());
  for(ll i = 0; i < childs.size(); i++) {
    result = max(result, childs[i] + 1 + i);
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n);
  for(ll i = 0; i < n; i++) {
    ll p;
    cin >> p;
    if(i == 0) continue;
    e[p].push_back(i);
  }
  
  cout << dfs(0) << '\n';
  return 0;
}