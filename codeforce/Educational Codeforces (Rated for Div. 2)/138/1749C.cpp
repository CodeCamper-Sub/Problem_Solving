#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
}

bool play(ll k) {
  vector<ll> alice, bob;
  deque<ll> all;
  for(ll a: a) {
    if(a > k) break;
    all.push_back(a);
  }
  while(all.size()) {
    while(all.size() && all.back() > k - alice.size()) all.pop_back();
    if(all.size()) {
      alice.push_back(all.back());
      all.pop_back();
    } else break;
    if(all.size()) {
      bob.push_back(all.front());
      all.pop_front();
    }
  }
  return alice.size() >= k;
}

void solve() {
  sort(a.begin(), a.end());
  for(ll k = (a.size() / 2) + 1; k >= 0; k--) {
    if(play(k)) {
      cout << k << '\n';
      return;
    }
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