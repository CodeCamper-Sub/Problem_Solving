#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
string s;
vector<ll> cnt;

void init() {
  cin >> n;
  cin >> s;
}

void solve() {
  ll answer = 0;
  for(ll i = 1; i <= min(101ll, n); i++) {
    cnt.assign(10, 0);
    ll maxi = -INF;
    ll dis_cnt = 0;
    for(ll j = 0; j < i; j++) {
      if(cnt[s[j] - '0'] == 0) dis_cnt++;
      cnt[s[j] - '0']++;
    }
    maxi = *max_element(cnt.begin(), cnt.end());
    if(maxi <= dis_cnt) answer++;
    for(ll j = i; j < n; j++) {
      if(cnt[s[j - i] - '0'] == 1) dis_cnt--;
      cnt[s[j - i] - '0']--;
      if(cnt[s[j] - '0'] == 0) dis_cnt++;
      cnt[s[j] - '0']++;
      maxi = *max_element(cnt.begin(), cnt.end());
      if(maxi <= dis_cnt) answer++;
    }
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