//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
double e[110][110], x[110], y[110], answer;
priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> q;
bool visited[110];


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = i+1; j <= n; j++) {
      double distance = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      e[i][j] = distance;
      e[j][i] = distance;
    }
  }
  
  visited[1] = true;
  for(ll i = 2; i <= n; i++) {
    q.push({e[1][i], i});
  }
  while(!q.empty()) {
    double cost = q.top().first;
    ll now = q.top().second;
    q.pop();
    if(visited[now]) continue;
    answer += cost;
    visited[now] = true;
    for(ll i = 1; i <= n; i++) {
      if(!visited[i]) {
        q.push({e[now][i], i});
      }
    }
  }
  cout << answer << '\n';
  
  return 0;
}

