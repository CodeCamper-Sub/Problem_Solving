#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
string s, t;

void init() {
  cin >> n >> m;
  cin >> s >> t;
}

bool is_beautiful(string s) {
  for(ll i = 1; i < s.size(); i++) {
    if(s[i] == s[i - 1]) return false;
  }
  return true;
}

void solve() {
  if(is_beautiful(s) && is_beautiful(t)) {
    cout << "YES\n";
    return;
  }

  if(is_beautiful(s)) swap(s, t);
  while(s[s.size() - 1] != s[s.size() - 2]) {
    t.push_back(s.back());
    s.pop_back();
  }
  t.push_back(s.back());
  s.pop_back();
  if(is_beautiful(s) && is_beautiful(t)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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