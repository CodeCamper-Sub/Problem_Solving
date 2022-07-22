//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
typedef long long ll;
using namespace std;

ll n, m, x, y, u, v;
ll visited[110];
vector<ll> ladder[110];
vector<ll> snake[110];
queue<ll> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  for(ll i = 0; i <= 100; i++) visited[i] = LONG_LONG_MAX;
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) {
    cin >> x >> y;
    ladder[x].push_back(y);
  }
  for(ll i = 1; i <= m; i++) {
    cin >> u >> v;
    snake[u].push_back(v);
  }
  visited[1] = 0;
  q.push(1);
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    for(ll i = 1; i <= 6; i++) {
      ll next = now + i;
      if(!ladder[next].empty()) {
        next = ladder[next][0];
      } else if (!snake[next].empty()) {
        next = snake[next][0];
      }
      if(visited[now] + 1 < visited[next]) {
        visited[next] = visited[now] + 1;
        q.push(next);
      }
    }
  }
  cout << visited[100] << '\n';
  
  return 0;
}

