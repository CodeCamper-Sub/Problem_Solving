#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  vector<string> used;
  for(ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    used.push_back(s);
  }
  ll i;
  char start = '*', end = '*';
  for(i = 0; i < n; i++) {
    if(used[i] == "?") {
      break;
    }
  }
  if(i > 0) {
    start = used[i - 1].back();
  }
  if(i < n - 1) {
    end = used[i + 1][0];
  }
  used.erase(used.begin() + i);

  sort(used.begin(), used.end());
  used.erase(unique(used.begin(), used.end()), used.end());

  cin >> m;
  for(ll i = 0; i < m; i++) {
    string s;
    cin >> s;
    if((start == '*' || start == s[0]) && (end == '*' || end == s.back()) && (*lower_bound(used.begin(), used.end(), s) != s)) {
      cout << s << '\n';
      return 0;
    }
  }  

  
  return 0;
}