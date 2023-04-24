#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;

void init() {
  cin >> n;
}

void solve() {
  n -= 4;
  ll answer = n * n + 10 * n + 26;
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