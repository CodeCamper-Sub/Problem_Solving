//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

void testcase();

ll tt, v, e, a, b;
bool visited[20200];
ll color[20200];

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
  cin >> v >> e;
  for(ll i = 0; i <= v; i++){
    visited[i] = false;
    color[i] = -1;
  }
  vector<ll> edges[20200];
  queue<ll> q;
  for(ll i = 1; i <= e; i++) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(ll i = 1; i <= v; i++) {
    if(!visited[i]) {
      visited[i] = true;
      color[i] = 0;
      q.push(i);
      while(!q.empty()) {
        ll now = q.front();
        q.pop();
        for(ll i = 0; i < edges[now].size(); i++) {
          ll next = edges[now][i];
          if(!visited[next]) {
            visited[next] = true;
            color[next] = color[now] == 0 ? 1 : 0;
            q.push(next);
          } else if(color[now] == color[next]){
            cout << "NO\n";
            return;
          }
        }
      }
    }
  }
  cout << "YES\n";
}
