#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll x, y;
vector<ll> answer;

void init() {
  cin >> x >> y;
  answer.clear();
}

void solve() {
  for(ll i = y; i < x; i++) answer.push_back(i);
  for(ll i = x; i > y; i--) answer.push_back(i);
  cout << answer.size() << '\n';
  for(ll i = 0; i < answer.size(); i++) {
    cout << answer[i] << ' ';
  }
  cout << '\n';
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