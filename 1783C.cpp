#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> a;

void init() {
  cin >> n >> m;
  a.resize(n);
  for(ll& a: a) cin >> a;
}

void solve() {
  priority_queue<ll, vector<ll>, greater<ll>> q;
  for(ll a: a) q.push(a);
  ll k = 0, sum = 0;
  while(q.size() && q.top() + sum <= m) {
    k++;
    sum += q.top(); q.pop();
  }
  if(k == n) {
    cout << 1 << '\n';
    return;
  }
  while(q.size()) q.pop();
  for(ll i = 0; i < a.size(); i++) {
    if(i == k) continue;
    q.push(a[i]);
  }
  if(m < a[k]) {
    cout << n - k + 1 << '\n';
    return;
  }
  ll k2 = 1;
  sum = a[k];
  while(q.size() && q.top() + sum <= m) {
    k2++;
    sum += q.top(); q.pop();
  }
  if(k == k2) {
    cout << n - k << '\n';
  } else {
    cout << n - k + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}