#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

unordered_map<string, ll> m;
ll n;
vector<string> v;

void init() {
  cin >> n;
  m.clear();
  v.assign(n, "");
  for(ll i = 0; i < n; i++) {
    cin >> v[i];
  }
}

void solve() {
  sort(v.begin(), v.end(), [](string& a, string& b) {
    return a.size() > b.size();
  });
  for(ll i = 0; i < n; i++) {
    if(m.count(v[i])) {
      cout << "NO\n";
      return;
    }
    for(ll j = 1; j <= v[i].size(); j++) {
      m[v[i].substr(0, j)]++;
    }
  }
  cout << "YES\n";
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