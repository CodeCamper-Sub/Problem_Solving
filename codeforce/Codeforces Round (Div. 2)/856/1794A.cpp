#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<string> a;
vector<char> answer;

void init() {
  cin >> n;
  a.resize(2 * n - 2);
  for(ll i = 0; i < 2 * n - 2; i++) {
    cin >> a[i];
  }
  answer.clear();
}

void solve() {
  sort(a.begin(), a.end(), [](string a, string b) {
    return a.size() < b.size();
  });
  for(ll i = 0; i < a.size(); i += 2) {
    for(ll j = 0; j < a[i].size(); j++) {
      if(a[i][j] != a[i + 1][a[i].size() - j - 1]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}