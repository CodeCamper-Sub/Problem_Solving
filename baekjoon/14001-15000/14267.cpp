#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, p, cnt, i, w;
vector<vector<ll>> e;
vector<ll> in, out, psum;

void dfs(ll now) {
  in[now] = cnt++;
  for(ll next: e[now]) {
    dfs(next);
  }
  out[now] = cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  psum.assign(n + 1, 0);
  in.resize(n + 1);
  out.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> p;
    if(p == -1) continue;
    e[p].push_back(i);
  }

  dfs(1);
  while(m--) {
    cin >> i >> w;
    psum[in[i]] += w;
    psum[out[i]] -= w;
  }

  for(ll i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + psum[i];
  }
  for(ll i = 1; i <= n; i++) {
    cout << psum[in[i]] << ' ';
  }

  return 0;
}