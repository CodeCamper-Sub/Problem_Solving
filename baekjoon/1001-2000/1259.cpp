#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

string s;

bool is_palindrome(ll left, ll right) {
  if(left > right) return true;
  if(s[left] == s[right]) return is_palindrome(left + 1, right - 1);
  else return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(true) {
    cin >> s;
    if(s == "0") break;
    cout << (is_palindrome(0, s.size() - 1) ? "yes" : "no") << '\n';
  }
  
  return 0;
}