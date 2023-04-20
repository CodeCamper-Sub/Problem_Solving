#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n;
vector<ll> a, answer;
set<ll> s;

void init() {
  cin >> n;
  a.resize(n);
  s.clear();
  answer.clear();
  for(ll& a: a) cin >> a;
}

void solve() {
  for(ll i = 0; i < n; i++) {
    if(i == 0) {
      s.insert(a[i]);
      answer.push_back(a[i]);
    } else if(a[i] != a[i - 1]) {
      if(s.find(a[i]) != s.end()) {
        cout << "IMPOSSIBLE\n";
        return;
      }
      s.insert(a[i]);
      answer.push_back(a[i]);
    }
  }
  for(ll ans: answer) {
    cout << ans << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for(ll i = 1; i <= tt; i++) {
    cout << "Case #" << i << ": ";
    init();
    solve();
  }
  return 0;
}