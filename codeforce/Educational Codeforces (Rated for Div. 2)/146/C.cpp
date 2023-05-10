#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, s1, s2;
vector<ll> a, b;
vector<pair<ll, ll>> r;

void init() {
  cin >> n >> s1 >> s2;
  r.assign(n, {0, 0});
  for(ll i = 0; i < n; i++) {
    cin >> r[i].first;
    r[i].second = i + 1;
  }
  a.clear();
  b.clear();
}

void solve() {
  sort(r.begin(), r.end(), [](auto a, auto b) { return a > b; });
  for(auto [_, i]: r) {
    if((a.size() + 1) * s1 > (b.size() + 1) * s2) {
      b.push_back(i);
    } else {
      a.push_back(i);
    }
  }

  cout << a.size() << ' ';
  for(ll a: a) cout << a << ' ';
  cout << '\n';
  cout << b.size() << ' ';
  for(ll b: b) cout << b << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}