#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
string s;
vector<vector<ll>> e, inv_e;
vector<ll> dist, inv_dist;

using Edge = pair<ll, ll>;
priority_queue<Edge, vector<Edge>, greater<Edge>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.assign(n, vector<ll>());
  inv_e.assign(n, vector<ll>());
  dist.assign(n, INF);
  inv_dist.assign(n, INF);
  for(ll i = 0; i < n; i++) {
    cin >> s;
    for(ll j = 0; j < s.size(); j++){
      if(s[j] == '0' || i + j + 1 >= n) continue;
      e[i].push_back(i + j + 1);
      inv_e[i + j + 1].push_back(i);
    }
  }

  dist[0] = 0;
  q.push({0, 0});
  while(q.size()) {
    auto [d, now] = q.top();
    q.pop();
    if(d > dist[now]) continue;
    for(ll next: e[now]) {
      if(dist[next] > dist[now] + 1) {
        dist[next] = dist[now] + 1;
        q.push({dist[next], next});
      }
    }
  }

  inv_dist[n - 1] = 0;
  q.push({0, n - 1});
  while(q.size()) {
    auto [d, now] = q.top();
    q.pop();
    if(d > inv_dist[now]) continue;
    for(ll next: inv_e[now]) {
      if(inv_dist[next] > inv_dist[now] + 1) {
        inv_dist[next] = inv_dist[now] + 1;
        q.push({inv_dist[next], next});
      }
    }
  }

  for(ll k = 1; k < n - 1; k++) {
    ll answer = INF;
    for(ll i = 1; i < m && k - i >= 0; i++) {
      ll now = k - i;
      for(ll next: e[now]) {
        if(next <= k) continue;
        answer = min(answer, dist[now] + inv_dist[next] + 1);
      }
    }
    if(answer == INF) {
      cout << -1 << ' ';
    } else {
      cout << answer << ' ';
    }
  }

  
  return 0;
}