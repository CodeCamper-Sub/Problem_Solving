//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, origin, destination, cost, u, v, maximum;
vector<pair<ll, ll>> e[10010];
ll distances[10010];
queue<pair<ll, ll>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n - 1; i++) {
    cin >> origin >> destination >> cost;
    e[origin].push_back({destination, cost});
    e[destination].push_back({origin, cost});
  }
  for(ll i = 0; i <= n; i++) {
    distances[i] = LONG_LONG_MAX;
  }
  distances[1] = 0;
  q.push({1, 0});
  while(!q.empty()) {
    ll now = q.front().first;
    ll distance_from_root = q.front().second;
    q.pop();
    if(distance_from_root > distances[now]) continue;
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i].first;
      ll added_distance = e[now][i].second;
      if(distances[next] > distance_from_root + added_distance) {
        distances[next] = distance_from_root + added_distance;
        q.push({next, distance_from_root + added_distance});
      }
    }
  }
  maximum = LONG_LONG_MIN;
  for(ll i = 1; i <= n; i++) {
    if(distances[i] != LONG_LONG_MAX && maximum < distances[i]) {
      maximum = distances[i];
      u = i;
    }
  }
  for(ll i = 0; i <= n; i++) {
    distances[i] = LONG_LONG_MAX;
  }
  distances[u] = 0;
  q.push({u, 0});
  while(!q.empty()) {
    ll now = q.front().first;
    ll distance_from_root = q.front().second;
    q.pop();
    if(distance_from_root > distances[now]) continue;
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i].first;
      ll added_distance = e[now][i].second;
      if(distances[next] > distance_from_root + added_distance) {
        distances[next] = distance_from_root + added_distance;
        q.push({next, distance_from_root + added_distance});
      }
    }
  }
  maximum = LONG_LONG_MIN;
  for(ll i = 1; i <= n; i++) {
    if(distances[i] != LONG_LONG_MAX) {
      maximum = max(maximum, distances[i]);
    }
  }
  cout << maximum << '\n';
  
  
  return 0;
}

