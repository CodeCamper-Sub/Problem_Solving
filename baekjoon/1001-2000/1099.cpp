#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

string s;
ll n;
vector<string> words;
vector<ll> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  cin >> n;
  words.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> words[i];
  }
  
  dp.assign(s.size(), INF);
  for(ll i = 0; i < s.size(); i++) {
    for(ll j = 0; j < n; j++) {
      if(i + 1 < words[j].size()) continue;
      map<char, ll> m;
      for(ll k = 0; k < words[j].size(); k++) {
        m[words[j][k]]++;
      }
      for(ll k = 0; k < words[j].size(); k++) {
        m[s[i - k]]--;
      }
      bool is_valid = true;
      for(auto [_, value]: m) {
        if(value != 0) {
          is_valid = false;
          break;
        }
      }
      if(!is_valid) continue;
      ll cost = 0;
      for(ll k = 0; k < words[j].size(); k++) {
        if(words[j][ll(words[j].size()) - 1 - k] != s[i - k]) cost++;
      }
      if(i - ll(words[j].size()) >= 0) {
        dp[i] = min(dp[i], dp[i - ll(words[j].size())] + cost);
      } else {
        dp[i] = min(dp[i], cost);
      }
    }
  }

  if(dp[ll(s.size()) - 1] != INF) {
    cout << dp[ll(s.size()) - 1] << '\n';
  } else {
    cout << -1 << '\n';
  }

  
  return 0;
}