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

ll n;
ll origin, destination, parent[100100];
vector<ll> e[100100];
queue<ll> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i < n; i++) {
    cin >> origin >> destination;
    e[origin].push_back(destination);
    e[destination].push_back(origin);
  }
  
  q.push(1);
  parent[1] = 1;
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    for(ll i = 0; i < e[now].size(); i++) {
      ll next = e[now][i];
      if(parent[next] == 0){
        parent[next] = now;
        q.push(next);
      }
    }
  }
  for(ll i = 2; i <= n; i++) {
    cout << parent[i] << '\n';
  }
  
  return 0;
}

