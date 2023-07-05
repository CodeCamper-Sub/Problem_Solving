#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

string a, b;
vector<vector<ll>> psum_a, psum_b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b;
  psum_a.resize(26, vector<ll>(a.size()));
  psum_b.resize(26, vector<ll>(b.size()));
  for(ll i = 0; i < 26; i++) {
    for(ll j = 0; j < a.size(); j++) {
      psum_a[i][j] = j > 0 ? psum_a[i][j - 1] : 0;
      if(a[j] == 'a' + i) {
        psum_a[i][j] += 1;
      }
    }
    for(ll j = 0; j < b.size(); j++) {
      psum_b[i][j] = j > 0 ? psum_b[i][j - 1] : 0;
      if(b[j] == 'a' + i) {
        psum_b[i][j] += 1;
      }
    }
  }

  for(ll i = min(a.size(), b.size()); i > 0; i--) {
    set<vector<ll>> s;
    for(ll j = 0; j <= a.size() - i; j++) {
      vector<ll> cnt(26, 0);
      for(ll k = 0; k < 26; k++) {
        // 알파벳 k의 j부터 j+i-1까지의 개수
        cnt[k] = psum_a[k][j + i - 1] - (j > 0 ? psum_a[k][j - 1] : 0);
      }
      s.insert(cnt);
    }
    for(ll j = 0; j <= b.size() - i; j++) {
      vector<ll> cnt(26, 0);
      for(ll k = 0; k < 26; k++) {
        // 알파벳 k의 j부터 j+i-1까지의 개수
        cnt[k] = psum_b[k][j + i - 1] - (j > 0 ? psum_b[k][j - 1] : 0);
      }
      if(s.find(cnt) != s.end()) {
        cout << i << '\n';
        return 0;
      }
    }
  }

  cout << 0 << '\n';
  
  return 0;
}