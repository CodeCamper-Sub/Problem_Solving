#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

void init() {
  cin >> n;
}

void solve() {
  if(n == 1) {
    cout << 1 << '\n';
    return;
  } else if(n % 2) {
    cout << -1 << '\n';
    return;
  }
  vector<ll> answer;
  for(ll i = 1; i < n; i++) {
    if(i % 2) {
      answer.push_back(i);
    } else {
      answer.push_back(n - i);
    }
  }
  answer.push_back(n);
  while(answer.size()) {
    cout << answer.back() << ' ';
    answer.pop_back();
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