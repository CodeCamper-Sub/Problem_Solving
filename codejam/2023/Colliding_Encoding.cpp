#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n;
set<string> enc;
vector<ll> mp(26);
vector<string> s;

void init() {
  enc.clear();
  for(ll i = 0; i < 26; i++) cin >> mp[i];
  cin >> n;
  s.resize(n);
  cin.ignore();
  for(ll i = 0; i < n; i++) cin >> s[i];
}

void solve() {
  for(ll i = 0; i < n; i++) {
    string encoded;
    for(ll j = 0; j < s[i].size(); j++) {
      encoded += char(mp[s[i][j] - 'A'] + '0');
    }
    if(enc.find(encoded) != enc.end()) {
      cout << "YES\n";
      return;
    }
    enc.insert(encoded);
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for(ll i = 1; i <= tt; i++) {
    cout << "Case #" << i << ": ";
    init();
    solve();
  }
  return 0;
}