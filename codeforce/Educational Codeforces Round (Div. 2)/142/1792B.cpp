#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a1, a2, a3, a4;

void init() {
  cin >> a1 >> a2 >> a3 >> a4;
}

void solve() {
  ll answer = a1;

  if(answer == 0) {
    cout << 1 << '\n';
    return;
  }

  ll delta = min(a2, a3);
  answer += delta * 2;
  a2 -= delta;
  a3 -= delta;
  if(a2) {
    delta = min(a1 + 1, a2);
    answer += delta;
    a1 -= delta;
    a2 -= delta;
  }
  if(a3) {
    delta = min(a1 + 1, a3);
    answer += delta;
    a1 -= delta;
    a3 -= delta;
  }
  delta = min(a1 + 1, a4);
  answer += delta;
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