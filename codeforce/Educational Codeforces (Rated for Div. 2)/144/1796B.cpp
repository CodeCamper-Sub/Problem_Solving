#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
string a, b;

void init() {
  cin >> a >> b;
}

void solve() {
  if(a[0] == b[0]) {
    cout << "YES\n";
    cout << a[0] << "*\n";
  } else if(a.back() == b.back()) {
    cout << "YES\n";
    cout << "*" << a.back() << '\n';
  } else if(a.size() < 2 || b.size() < 2) {
    cout << "NO\n";
  } else {
    for(ll i = 0; i < a.size() - 1; i++) {
      for(ll j = 0; j < b.size() - 1; j++) {
        if(a[i] == b[j] && a[i + 1] == b[j + 1]) {
          cout << "YES\n";
          cout << "*" << a[i] << a[i+1] << "*\n";
          return;
        }
      }
    }
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}