//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
typedef long long ll;
using namespace std;

ll n, m, a, b;
ll origin, destination, cost;
vector<pair<ll, ll>> e[1010];
ll shortest_distance[1010];
ll from[1010];
queue<pair<ll, ll>> q;
vector<ll> path;


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(ll i = 1; i <= m; i++) {
    cin >> origin >> destination >> cost;
    e[origin].push_back({destination, cost});
  }
  for(ll i = 0; i <= n; i++) {
    shortest_distance[i] = LONG_LONG_MAX;
  }
  cin >> a >> b;
  shortest_distance[a] = 0;
  q.push({a, 0});
  while(!q.empty()) {
    ll now = q.front().first;
    ll distance_from_a = q.front().second;
    q.pop();
    if(distance_from_a > shortest_distance[now]) continue;
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i].first;
      ll added_cost = e[now][i].second;
      if(shortest_distance[next] > distance_from_a + added_cost) {
        from[next] = now;
        shortest_distance[next] = distance_from_a + added_cost;
        q.push({next, distance_from_a + added_cost});
      }
    }
  }
  
  cout << shortest_distance[b] << '\n';
  
  ll now = b;
  path.push_back(now);
  while(from[now] != 0) {
    now = from[now];
    path.push_back(now);
  }
  
  cout << path.size() << '\n';
  while(!path.empty()) {
    cout << path.back() << ' ';
    path.pop_back();
  }
  cout << '\n';
  
  
  return 0;
}

