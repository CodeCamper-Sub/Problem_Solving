#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;

ll is_palindrome(ll a, ll b) {
  if(a >= b) return 1;
  if(s[a] == s[b]) {
    return is_palindrome(a + 1, b - 1);
  } else {
    return 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;

  cout << is_palindrome(0, s.size() - 1);

  return 0;
}