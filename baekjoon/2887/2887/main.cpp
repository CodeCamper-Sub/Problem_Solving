//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, x, y, z, answer;
vector<pair<ll, ll>> sortedOrder[3];
vector<pair<ll, ll>> e[100100];
bool visited[100100];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    sortedOrder[0].push_back({x, i});
    sortedOrder[1].push_back({y, i});
    sortedOrder[2].push_back({z, i});
  }
  sort(sortedOrder[0].begin(), sortedOrder[0].end());
  sort(sortedOrder[1].begin(), sortedOrder[1].end());
  sort(sortedOrder[2].begin(), sortedOrder[2].end());
  for(ll i = 0; i < n; i++) {
    if(i != 0) {
      for(ll k = 0; k < 3; k++) {
        ll origin = sortedOrder[k][i].second;
        ll originLocation = sortedOrder[k][i].first;
        ll dest = sortedOrder[k][i-1].second;
        ll destLocation = sortedOrder[k][i-1].first;
        e[origin].push_back({dest, abs(destLocation - originLocation)});
      }
    }
    if(i != n-1) {
      for(ll k = 0; k < 3; k++) {
        ll origin = sortedOrder[k][i].second;
        ll originLocation = sortedOrder[k][i].first;
        ll dest = sortedOrder[k][i+1].second;
        ll destLocation = sortedOrder[k][i+1].first;
        e[origin].push_back({dest, abs(destLocation - originLocation)});
      }
    }
  }
  visited[1] = true;
  for(ll i = 0; i < e[1].size(); i++) {
    ll next = e[1][i].first;
    ll distance = e[1][i].second;
    q.push({distance, next});
  }
  
  while(!q.empty()) {
    ll now = q.top().second;
    ll cost = q.top().first;
    q.pop();
    if(visited[now]) continue;
    visited[now] = true;
    answer += cost;
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i].first;
      ll cost = e[now][i].second;
      if(!visited[next]) {
        q.push({cost, next});
      }
    }
  }
  cout << answer << '\n';
  
  return 0;
}
