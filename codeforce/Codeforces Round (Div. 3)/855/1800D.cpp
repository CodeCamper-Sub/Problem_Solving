#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

void init() {
  cin >> n >> s;
}
void solve() {
  ll answer = 1;
  for(ll i = 1; i < n - 1; i++) {
    if(s[i - 1] == s[i + 1]) continue;
    else answer++;
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