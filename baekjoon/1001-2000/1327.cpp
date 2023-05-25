#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

map<vector<ll>, ll> visited;
vector<ll> v;
ll n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  queue<vector<ll>> q;
  visited[v] = 0;
  q.push(v);
  while(q.size()) {
    vector<ll> now = q.front();
    q.pop();
    for(ll i = 0; i + k <= n; i++) {
      vector<ll> next = now;
      for(ll j = 0; j < k; j++) {
        next[i + j] = now[i + k - j - 1];
      }
      if(visited.count(next) == 0) {
        visited[next] = visited[now] + 1;
        q.push(next);
      }
    }
  }

  sort(v.begin(), v.end());
  if(visited.count(v) == 0) {
    cout << -1 << '\n';
  } else {
    cout << visited[v] << '\n';
  }

  
  return 0;
}