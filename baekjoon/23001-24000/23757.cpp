#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
ll c[100100], w[100100];
priority_queue<ll> q;
bool flag;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  flag = true;
  for(ll i = 0; i < n; i++) {
    cin >> c[i];
    q.push(c[i]);
  }
  for(ll i = 0; i < m; i++) {
    cin >> w[i];
  }
  for(ll i = 0; i < m; i++) {
    ll now = q.top(); q.pop();
    if(now >= w[i]) {
      now -= w[i];
      q.push(now);
    } else {
      flag = false;
      break;
    }
  }
  if(flag) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }

  return 0;
}