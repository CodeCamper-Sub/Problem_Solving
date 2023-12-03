#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
vector<string> v;
map<pair<string, string>, ll> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (ll i = 0; i < N; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end());

  for (ll i = 0; i < v.size(); i++) {
    for (ll j = i + 1; j < v.size(); j++) {
      string a = v[i];
      string b = v[j];
      vector<ll> dif;
      if (a.size() != b.size()) {
        continue;
      }
      for (ll k = 0; k < a.size(); k++) {
        if (a[k] != b[k])
          dif.push_back(k);
      }
      if (dif.size() != 2)
        continue;
      if (dif[0] + 1 != dif[1])
        continue;
      string tmpp;
      string tmpp2;
      tmpp += a[dif[0]];
      tmpp += a[dif[1]];
      tmpp2 += b[dif[0]];
      tmpp2 += b[dif[1]];
      m[{tmpp, tmpp2}]++;
      m[{tmpp2, tmpp}]++;
    }
  }
  ll ans = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second == 1) {
      ans += it->second;
    }
  }
  cout << ans / 2 << "\n";

  return 0;
}
