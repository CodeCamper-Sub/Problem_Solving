//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, m, t, s, g, h;
ll a, b, d;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    testcase();
  }
  return 0;
}

void testcase() {
  cin >> n >> m >> t;
  cin >> s >> g >> h;
  vector<pair<ll, ll>> e[2020];
  vector<ll> destinations(t);
  ll distance_from_start[2020];
  ll distance_from_h[2020];
  ll h_distance;
  for(ll i = 0; i <= n; i++) {
    distance_from_start[i] = LONG_LONG_MAX;
    distance_from_h[i] = LONG_LONG_MAX;
  }
  
  for(ll i = 1; i <= m; i++) {
    cin >> a >> b >> d;
    e[a].push_back({b, d});
    e[b].push_back({a, d});
  }
  for(ll i = 0; i < t; i++) {
    cin >> destinations[i];
  }
  
  distance_from_start[s] = 0;
  q.push({0, s});
  while(!q.empty()) {
    ll now = q.top().second;
    ll distance = q.top().first;
    q.pop();
    if(distance > distance_from_start[now]) continue;
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i].first;
      ll length = e[now][i].second;
      if(distance + length < distance_from_start[next]) {
        distance_from_start[next] = distance + length;
        q.push({distance + length, next});
      }
    }
  }
  
  if(distance_from_start[g] > distance_from_start[h]) {
    swap(g, h);
  }
  
  distance_from_h[h] = 0;
  q.push({0, h});
  while(!q.empty()) {
    ll now = q.top().second;
    ll distance = q.top().first;
    q.pop();
    if(distance > distance_from_h[now]) continue;
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i].first;
      ll length = e[now][i].second;
      if(distance + length < distance_from_h[next]) {
        distance_from_h[next] = distance + length;
        q.push({distance + length, next});
      }
    }
  }
  
  for(ll i = 0; i < e[g].size(); i++) {
    if(e[g][i].first == h) {
      h_distance = e[g][i].second + distance_from_start[g];
      break;
    }
  }
  
  sort(destinations.begin(), destinations.end());
  for(ll i = 0; i < destinations.size(); i++) {
    ll destination = destinations[i];
    if(distance_from_start[destination] == h_distance + distance_from_h[destination]) {
      cout << destination << ' ';
    }
  }
  cout << '\n';
}

