//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
#include <stack>
#include <climits>
typedef long long ll;
using namespace std;

ll n, k;
bool visited[400400];
ll from[400400];
queue<ll> q;
stack<ll> path;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  for(ll i = 0; i <= 400000; i++) from[i] = LONG_LONG_MIN;
  cin >> n >> k;
  visited[n] = true;
  q.push(n);
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    ll next = now - 1;
    if(next >= 0 && !visited[next]) {
      visited[next] = true;
      from[next] = now;
      q.push(next);
    }
    next = now + 1;
    if(next <= 400000 && !visited[next]) {
      visited[next] = true;
      from[next] = now;
      q.push(next);
    }
    next = now * 2;
    if(next <= 400000 && !visited[next]) {
      visited[next] = true;
      from[next] = now;
      q.push(next);
    }
    if(visited[k]) break;
  }
  
  ll now = k;
  path.push(now);
  while(from[now] != LONG_LONG_MIN) {
    ll next = from[now];
    path.push(next);
    now = next;
  }
  cout << path.size() - 1 << '\n';
  while(!path.empty()) {
    cout << path.top() << ' ';
    path.pop();
  }
  
  return 0;
}
