#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll s, f;
vector<ll> cnt;

void init() {
  cin >> s >> f;
  cnt.assign(63, 0);
}


void solve() {
  ll k = 1;
  while(k < (1e18)) {
    cnt[log2(k)] += (f - k + 1) / (k * 2) * (k * 2) / 2;
    cnt[log2(k)] += max(0ll, min((f - k + 1) % (k * 2), k));
    k *= 2;
  }

  k = 1;
  s -= 1;
  while(k < (1e18)) {
    cnt[log2(k)] -= (s - k + 1) / (k * 2) * (k * 2) / 2;
    cnt[log2(k)] -= max(0ll, min((s - k + 1) % (k * 2), k));
    k *= 2;
  }

  ll answer = 0;
  k = 1;
  while(k < (1e18)) {
    if(cnt[log2(k)] % 2) answer += k;
    k *= 2;
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