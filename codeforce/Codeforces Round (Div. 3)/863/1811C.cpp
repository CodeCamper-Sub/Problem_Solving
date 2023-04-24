#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> b, a;

void init() {
  cin >> n;
  b.resize(n - 1);
  a.clear();
  for(ll i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
}

void solve() {
  bool shifted = false;
  for(ll i = 0; i < b.size() - 1; i++) {
    if(shifted) {
      if(b[i] <= b[i + 1]) {
        a.push_back(b[i]);
      } else {
        shifted = false;
      }
    } else {
      if(b[i] >= b[i + 1]) {
        a.push_back(b[i]);
      } else {
        shifted = true;
        a.push_back(b[i]);
        a.push_back(b[i]);
      }
    }
  }
  a.push_back(b.back());
  if(a.size() != b.size() + 1) {
    a.push_back(b.back());
  }
  for(ll& a: a) {
    cout << a << ' ';
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