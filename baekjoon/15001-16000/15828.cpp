#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, p;
queue<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  while(true) {
    cin >> p;
    if(p == -1) break;
    if(p == 0) {
      q.pop();
    } else if(q.size() < n) {
      q.push(p);
    }
  }

  if(q.empty()) {
    cout << "empty" << '\n';
  } else {
    while(!q.empty()) {
      cout << q.front() << ' ';
      q.pop();
    }
  }

  return 0;
}