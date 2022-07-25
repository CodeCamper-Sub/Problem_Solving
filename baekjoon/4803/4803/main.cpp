//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, m, u, v;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  tt = 0;
  while(++tt) {
    cin >> n >> m;
    if(n == 0 && m == 0) {
      break;
    }
    cout << "Case " << tt << ": ";
    testcase();
    cout << '\n';
  }
  return 0;
}

void testcase() {
  vector<ll> e[550];
  bool visited[550];
  queue<pair<ll, ll>> q;
  ll trees = 0;
  bool is_tree;
  
  for(ll i = 0; i <= n; i++) {
    visited[i] = false;
  }
  for(ll i = 1; i <= m; i++) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(ll i = 1; i <= n; i++) {
    if(!visited[i]) {
      is_tree = true;
      visited[i] = true;
      q.push({0, i});
      while(!q.empty()) {
        ll origin = q.front().first;
        ll now = q.front().second;
        q.pop();
        for(ll j = 0; j < e[now].size(); j++) {
          ll next = e[now][j];
          if(visited[next] && next != origin) {
            is_tree = false;
          }
          if(!visited[next]) {
            visited[next] = true;
            q.push({now, next});
          }
        }
      }
      if(is_tree) {
        trees++;
      }
    }
  }
  if(trees > 2) {
    cout << "A forest of " << trees << " trees.";
  } else if(trees == 1) {
    cout << "There is one tree.";
  } else if(trees == 0) {
    cout << "No trees.";
  }
}

