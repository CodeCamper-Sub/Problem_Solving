#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;
bool is_palindrome(ll left, ll right) {
  if(right <= left) return true;
  if(s[left] == s[right]) {
    return is_palindrome(left + 1, right - 1);
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  bool is_all_same = true;
  for(ll i = 0; i < s.size() - 1; i++) {
    if(s[i] != s[i + 1]) {
      is_all_same = false;
      break;
    }
  }
  if(is_all_same) {
    cout << -1 << '\n';
  } else if(!is_palindrome(0, s.size() - 1)) {
    cout << s.size() << '\n';
  } else {
    cout << s.size() - 1 << '\n';
  }

  
  return 0;
}