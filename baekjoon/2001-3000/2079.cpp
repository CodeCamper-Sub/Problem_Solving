#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;
vector<vector<ll>> is_palindrome;
vector<ll> dp;

void get_is_palindrome(ll start, ll end) {
  if(is_palindrome[start][end] != -1) return;
  if(end <= start) {
    is_palindrome[start][end] = true;
    return;
  } else {
    get_is_palindrome(start + 1, end);
    get_is_palindrome(start, end - 1);
    is_palindrome[start][end] = s[start] == s[end] && is_palindrome[start + 1][end - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  is_palindrome.assign(s.size(), vector<ll>(s.size(), -1));
  get_is_palindrome(0, s.size() - 1);
  dp.assign(s.size(), INF);
  dp[0] = 1;
  for(ll i = 1; i < s.size(); i++) {
    if(is_palindrome[0][i]) dp[i] = 1;
    for(ll j = 1; j <= i; j++) {
      if(!is_palindrome[j][i]) continue;
      dp[i] = min(dp[i], dp[j - 1] + 1);
    }
  }

  cout << dp[s.size() - 1] << '\n';

  
  return 0;
}