#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, m;
vector<ll> cnt[300300];

void init() {
  cin >> n >> m;
  for(ll i = 0; i < m; i++) {
    cnt[i].clear();
    cnt[i].resize(n);
  }
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) cin >> cnt[j][i];
  }
  for(ll i = 0; i < m; i++) {
    sort(cnt[i].begin(), cnt[i].end());
  }
}

void solve() {
  ll answer = 0;
  for(ll i = 0; i < m; i++) {
    ll partial_answer = 0;
    ll partial_sum = 0;
    for(ll j = 0; j < n; j++) {
      partial_answer += cnt[i][j] * j - partial_sum;
      partial_sum += cnt[i][j];
    }
    answer += partial_answer;
  }
  cout << answer << '\n';
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