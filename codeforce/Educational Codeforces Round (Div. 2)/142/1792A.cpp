#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> cnt;

void init() {
  cin >> n;
  cnt.assign(101, 0);
}

void solve() {
  ll h;
  for(ll i = 0; i < n; i++) {
    cin >> h;
    cnt[h]++;
  }  
  ll answer = 0;
  answer += (cnt[1] + 1) / 2;
  for(ll i = 2; i < 101; i++) {
    answer += cnt[i];
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