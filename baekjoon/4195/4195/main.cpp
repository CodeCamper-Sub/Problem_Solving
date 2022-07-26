//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void testcase();

ll tt, f;
string a, b;
ll id, parent[200200], netSize[200200];
map<string, ll> m;

ll Find(ll node) {
  if(parent[node] == node) {
    return node;
  } else {
    return parent[node] = Find(parent[node]);
  }
}

void Union(ll nodeA, ll nodeB) {
  nodeA = Find(nodeA);
  nodeB = Find(nodeB);
  
  if(nodeA != nodeB) {
    parent[nodeB] = nodeA;
    netSize[nodeA] += netSize[nodeB];
    netSize[nodeB] = 0;
  }
}

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
  id = 0;
  m.clear();
  cin >> f;
  for(ll i = 0; i <= 2*f; i++) {
    parent[i] = i;
    netSize[i] = 1;
  }
  for(ll i = 1; i <= f; i++) {
    cin >> a >> b;
    if(m.find(a) == m.end()) {
      m[a] = id++;
    }
    if(m.find(b) == m.end()) {
      m[b] = id++;
    }
    ll ancestorA = Find(m[a]);
    ll ancestorB = Find(m[b]);
    if(ancestorA != ancestorB) {
      Union(ancestorA, ancestorB);
    }
    cout << netSize[ancestorA] << '\n';
  }
}
