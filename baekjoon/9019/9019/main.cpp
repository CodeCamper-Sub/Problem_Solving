//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

void testcase();

enum transaction {
  UNDEFINED,
  D,
  S,
  L,
  R
};

ll tt, a, b;
bool visited[10010];
ll from[10010];
transaction transactions[10010];
queue<ll> q;
stack<transaction> path;

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
  cin >> a >> b;
  for(ll i = 0; i <= 10000; i++){
    visited[i] = false;
    from[i] = LONG_LONG_MIN;
    transactions[i] = UNDEFINED;
  }
  visited[a] = true;
  q.push(a);
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    ll next = (now * 2) % 10000;
    if(!visited[next]) {
      visited[next] = true;
      from[next] = now;
      transactions[next] = D;
      q.push(next);
    }
    next = now - 1;
    next = next < 0 ? next + 10000 : next;
    if(!visited[next]) {
      visited[next] = true;
      from[next] = now;
      transactions[next] = S;
      q.push(next);
    }
    next = (now%1000) * 10 + (now / 1000);
    if(!visited[next]) {
      visited[next] = true;
      from[next] = now;
      transactions[next] = L;
      q.push(next);
    }
    next = (now % 10) * 1000 + (now / 10);
    if(!visited[next]) {
      visited[next] = true;
      from[next] = now;
      transactions[next] = R;
      q.push(next);
    }
  }
  ll now = b;
  while(from[now] != LONG_LONG_MIN) {
    path.push(transactions[now]);
    now = from[now];
  }
  while(!path.empty()) {
    if(path.top() == D) {
      cout << "D";
    } else if(path.top() == S) {
      cout << "S";
    } else if(path.top() == L) {
      cout << "L";
    } else if(path.top() == R) {
      cout << "R";
    }
    path.pop();
  }
  cout << '\n';
}

