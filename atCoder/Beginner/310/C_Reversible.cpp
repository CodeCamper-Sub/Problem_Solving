#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, p_cnt;
set<string> nst, st;

bool is_palin(string s) {
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    if(!is_palin(s)) {
      st.insert(s);
      reverse(s.begin(), s.end());
      st.insert(s);
    } else {
      nst.insert(s);
    }
  }

  cout << st.size() / 2 + nst.size() << '\n';
  
  
  return 0;
}