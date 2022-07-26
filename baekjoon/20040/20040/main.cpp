//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, u, v, answer;
ll parent[500500];

ll Find(ll node) {
  if (parent[node] == node) return node;
  return parent[node] = Find(parent[node]);
}

void Union(ll nodeA, ll nodeB) {
  nodeA = Find(nodeA);
  nodeB = Find(nodeB);
  if(nodeA != nodeB) {
    parent[nodeB] = nodeA;
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(ll i = 0; i <= n; i++) {
    parent[i] = i;
  }
  
  for(ll i = 1; i <= m; i++) {
    cin >> u >> v;
    ll ancestorU = Find(u);
    ll ancestorV = Find(v);
    if(ancestorU == ancestorV && answer == 0) {
      answer = i;
    }
    if(ancestorU != ancestorV) {
      Union(ancestorU, ancestorV);
    }
  }
  
  cout << answer << '\n';
  
  return 0;
}

