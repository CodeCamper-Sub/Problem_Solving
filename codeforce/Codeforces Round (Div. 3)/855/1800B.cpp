#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;
string s;
vector<ll> cnt;

void init() {
  cin >> n >> k >> s;
  cnt.assign(52, 0);
}

void solve() {
  ll answer = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] >= 'a') {
      cnt[s[i] - 'a' + 26]++;
    } else {
      cnt[s[i] - 'A']++;
    }
  }

  for(ll i = 0; i < 26; i++) {
    ll delta = min(cnt[i], cnt[i + 26]);
    answer += delta;
    if(k == 0) continue;
    cnt[i] -= delta;
    cnt[i + 26] -= delta;
    delta = max(cnt[i], cnt[i + 26]);
    delta /= 2;
    delta = min(delta, k);
    answer += delta;
    k -= delta;
  }

  cout << answer << '\n';
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