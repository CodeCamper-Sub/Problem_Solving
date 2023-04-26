#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
priority_queue<ll, vector<ll>, greater<ll>> min_q;
priority_queue<ll> max_q;

void init() {
  cin >> n;
  a.resize(n);
  while(min_q.size()) min_q.pop();
  while(max_q.size()) max_q.pop();
  for(ll& a: a) cin >> a;
}

void solve() {
  min_q.push(a[0]);
  cout << 1 << ' ';
  for(ll i = 1; i < n; i++) {
    max_q.push(a[i]);
    while(max_q.size() && max_q.top() > min_q.top()) {
      max_q.push(min_q.top());
      min_q.push(max_q.top());
      max_q.pop();
      min_q.pop();
    }
    while(max_q.size() && max_q.top() >= min_q.size() + 1) {
      min_q.push(max_q.top());
      max_q.pop();
    }
    cout << min_q.size() << ' ';
  }
  cout << '\n';
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