#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, left_cnt, right_cnt, x;
vector<ll> reserved;
set<ll> used;

void init() {
  cin >> n >> m;
  left_cnt = 0;
  right_cnt = 0;
  reserved.clear();
  used.clear();
  for(ll i = 0; i < n; i++) {
    cin >> x;
    if(x == -1) {
      left_cnt++;
    } else if(x == -2) {
      right_cnt++;
    } else {
      if(used.find(x) == used.end()) {
        reserved.push_back(x);
        used.insert(x);
      }
    }
  }
}

void solve() {
  sort(reserved.begin(), reserved.end());
  ll answer = 0;
  ll t = reserved.size();
  answer = max(answer, min(m - t, right_cnt) + t);
  answer = max(answer, min(m - t, left_cnt) + t);
  for(ll i = 0; i < reserved.size(); i++) {
    ll left_ward = min(reserved[i] - 1 - i, left_cnt) + i;
    ll right_ward = min(m - reserved[i] - (ll(reserved.size()) - i - 1), right_cnt) + (reserved.size() - i - 1);
    answer = max(answer, left_ward + right_ward + 1);
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