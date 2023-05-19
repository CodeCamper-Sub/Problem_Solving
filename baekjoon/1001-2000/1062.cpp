#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> know;
vector<string> words;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  words.resize(n);
  for(string& w: words) {
    cin >> w;
    w = w.substr(0, w.size() - 4).substr(4);
  }
  for(ll i = 0; i < 26; i++) {
    if(i < 26 - k) know.push_back(0);
    else know.push_back(1);
  }

  ll answer = 0;
  do {
    if(know['a' - 'a'] == 0 || know['n' - 'a'] == 0 || know['t' - 'a'] == 0 || know['i' - 'a'] == 0 || know['c' - 'a'] == 0) continue;
    ll partial_answer = 0;
    for(string w: words) {
      bool can_read = true;
      for(char c: w) {
        if(know[c - 'a'] == 0) {
          can_read = false;
          break;
        }
      }
      if(can_read) partial_answer++;
    }
    answer = max(answer, partial_answer);
  } while(next_permutation(know.begin(), know.end()));
  
  cout << answer << '\n';

  return 0;
}