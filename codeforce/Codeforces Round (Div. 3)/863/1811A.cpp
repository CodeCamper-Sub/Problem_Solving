#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, d;
string s;

void init() {
  cin >> n >> d;
  cin >> s;
}
void solve() {
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] - '0' < d) {
      s = s.substr(0, i) + to_string(d) + s.substr(i);
      break;
    }
  }
  if(s.size() == n) {
    s = s + to_string(d);
  }
  cout << s << '\n';
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