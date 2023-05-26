#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

unordered_map<string, ll> colors[1001], nicks[1001];
ll c, n, q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> c >> n;
  for(ll i = 0; i < c; i++) {
    string s;
    cin >> s;
    colors[s.size()][s]++;
  }
  for(ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    nicks[s.size()][s]++;
  }

  cin >> q;
  while(q--) {
    string s;
    cin >> s;
    bool answer = false;
    string pcolor = "";
    string pnick = s;
    reverse(pnick.begin(), pnick.end());
    for(ll i = 0; i < s.size(); i++) {
      pcolor.push_back(s[i]);
      pnick.pop_back();
      if(pcolor.size() > 1000 || pnick.size() > 1000 || colors[pcolor.size()].size() == 0 || nicks[pnick.size()].size() == 0) continue;
      if(colors[pcolor.size()].count(pcolor) && nicks[pnick.size()].count(pnick)) {
        answer = true;
        break;
      }
    }
    if(answer) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  
  return 0;
}