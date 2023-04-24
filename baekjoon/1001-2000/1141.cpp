#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<string> s;
set<string> used;

bool is_substring(string l, string s) {
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] != l[i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  s.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> s[i];
  }
  
  sort(s.begin(), s.end(), [](string a, string b) {
    return a.size() > b.size();
  });

  ll answer = 0;
  for(ll i = 0; i < s.size(); i++) {
    bool is_valid = true;
    for(string l: used) {
      if(is_substring(l, s[i])) {
        is_valid = false;
        break;
      }
    }
    if(is_valid) {
      answer++;
      used.insert(s[i]);
    }
  }
  
  cout << answer << '\n';
  
  return 0;
}