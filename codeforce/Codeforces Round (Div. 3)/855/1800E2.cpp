#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;
string s, t;
vector<ll> s_cnt, t_cnt;

void init() {
  cin >> n >> k >> s >> t;
  s_cnt.assign(26, 0);
  t_cnt.assign(26, 0);
}

void solve() {
  for(ll i = n - k; i < k; i++) {
    if(i < 0 || i >= n) continue;
    if(s[i] != t[i]) {
      cout << "NO\n";
      return;
    }
  }
  for(ll i = 0; i < n; i++) {
    s_cnt[s[i] - 'a']++;
    t_cnt[t[i] - 'a']++;
  }
  for(ll i = 0; i < 26; i++) {
    if(s_cnt[i] != t_cnt[i]) {
      cout << "NO\n";
      return;
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