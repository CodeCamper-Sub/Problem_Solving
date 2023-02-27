#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;
ll dp[3000], is_palindrome[3000][3000];

bool get_is_palindrome(ll start, ll end) {
  if(is_palindrome[start][end] != -1) {
    return is_palindrome[start][end];
  }
  if(start == end) { 
    return is_palindrome[start][end] = 1;
  } else if (s[start] == s[end]) {
    if(start + 1 == end) {
      return is_palindrome[start][end] = 1;
    } else {
      return is_palindrome[start][end] = get_is_palindrome(start + 1, end - 1);
    }
  } else {
    return is_palindrome[start][end] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fill(dp, dp + 3000, INF);
  fill(&is_palindrome[0][0], &is_palindrome[2999][3000], -1);

  cin >> s;

  for(ll i = 0; i < s.size(); i++) {
    for(ll j = i; j < s.size(); j++) {
      get_is_palindrome(i, j);
    }
  }

  dp[0] = 1;
  for(ll i = 0; i < s.size(); i++) {
    for(ll j = i; j < s.size(); j++) {
      if(is_palindrome[i][j]) {
        if(i > 0) {
          dp[j] = min(dp[j], dp[i-1] + 1);
        } else {
          dp[j] = 1;
        }
      }
    }
  }

  cout << dp[s.size() - 1] << '\n';
  
  return 0;
}