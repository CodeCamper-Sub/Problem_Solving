#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m;
string a;
set<char> used_chars;
unordered_map<char, ll> comp;
vector<ll> cnt;

bool init() {
  used_chars.clear();
  comp.clear();
  cin >> m;
  if(m == 0) return false;
  cin.ignore();
  getline(cin, a);
  return true;
}

void solve() {
  ll answer = 0, left = 0;
  for(ll i = 0; i < a.size(); i++) used_chars.insert(a[i]);
  ll id = 0;
  for(char c: used_chars) {
    comp[c] = id++;
  }
  cnt.assign(id + 1, 0);

  ll used_cnt = 0;
  for(ll i = 0; i < a.size(); i++) {
    if(cnt[comp[a[i]]] == 0) {
      while(used_cnt == m) {
        if(--cnt[comp[a[left]]] == 0) {
          used_cnt--;
        }
        left++;
      }
      used_cnt++;
    }
    cnt[comp[a[i]]]++;
    answer = max(answer, i - left + 1);
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(true) {
    if(!init()) break;
    solve();
  }
  return 0;
}