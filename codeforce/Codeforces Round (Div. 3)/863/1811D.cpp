#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, y, x;
vector<ll> fibo;

void init() {
  cin >> n >> y >> x;
}

bool is_possible(ll now, ll y, ll x) {
  if(now == 1) return true;
  if((n - now) % 2 == 0) {
    // x 방향 확인
    if(x > fibo[now]) {
      return is_possible(now - 1, y, x - fibo[now]);
    } else if(x <= fibo[now - 1]) {
      return is_possible(now - 1, y, x);
    } else {
      return false;
    }
  } else {
    if(y > fibo[now]) {
      return is_possible(now - 1, y - fibo[now], x);
    } else if(y <= fibo[now - 1]) {
      return is_possible(now - 1, y, x);
    } else {
      return false;
    }
  }
}

void solve() {
  if(is_possible(n, y, x)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fibo.push_back(1);
  fibo.push_back(1);
  while(fibo.back() < ll(1e18)) {
    fibo.push_back(fibo[fibo.size() - 2] + fibo[fibo.size() - 1]);
  }
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}