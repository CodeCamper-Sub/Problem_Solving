//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

ll n, m, r, u, v, cnt;
vector<ll> e[100100];
ll visited[100100];
queue<ll> q;

bool compare(ll a, ll b) {
  return a > b;
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> r;
  for(ll i = 1; i <= m; i++) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(ll i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end(), compare);
  }
  cnt = 1;
  visited[r] = cnt;
  q.push(r);
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i];
      if(!visited[next]) {
        visited[next] = ++cnt;
        q.push(next);
      }
    }
  }
  for(ll i = 1; i <= n; i++) {
    cout << visited[i] << '\n';
  }
  return 0;
}


