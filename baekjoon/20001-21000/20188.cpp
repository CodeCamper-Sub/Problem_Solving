#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, cnt, answer;
vector<vector<ll>> e;
vector<ll> in, out;

void euler_tour(ll now, ll parent) {
  in[now] = cnt++;
  for(ll next: e[now]) {
    if(next == parent) continue;
    euler_tour(next, now);
  }
  out[now] = cnt;
}

void dfs(ll now, ll parent) {
  if(now != 1) {
    ll childs = out[now] - in[now];
    ll whole = n * (n - 1) / 2;
    answer += whole - (n - childs) * (n - childs - 1) / 2;
  }
  for(ll next: e[now]) {
    if(next == parent) continue;
    dfs(next, now);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  in.resize(n + 1);
  out.resize(n + 1);
  e.resize(n + 1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  euler_tour(1, -1);
  dfs(1, -1);

  cout << answer << '\n';
  
  return 0;
}