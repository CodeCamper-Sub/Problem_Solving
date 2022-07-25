//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
#include <climits>
typedef long long ll;
using namespace std;

ll n, k;
ll visited[400400];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  for(ll i = 0; i <= 400000; i++) {
    visited[i] = LONG_LONG_MAX;
  }
  visited[n] = 0;
  q.push({0, n});
  while(!q.empty()) {
    ll now = q.top().second;
    ll distance = q.top().first;
    q.pop();
    if(distance > visited[now]) {
      continue;
    }
    ll next = now + 1;
    if(next <= 400000 && distance + 1 < visited[next]) {
      visited[next] = distance + 1;
      q.push({distance + 1, next});
    }
    next = now - 1;
    if(next >= 0 && distance + 1 < visited[next]) {
      visited[next] = distance + 1;
      q.push({distance + 1, next});
    }
    next = now * 2;
    if(next <= 400000 && distance < visited[next]) {
      visited[next] = distance;
      q.push({distance, next});
    }
    if(visited[k] != LONG_LONG_MAX) break;
  }
  cout << visited[k] << '\n';
  
  return 0;
}
