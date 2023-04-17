#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
typedef long double ld;
using namespace std;

ll tt, n;

void init() {
  cin >> n;
}

void solve() {
  if(n == 1) {
    cout << 0 << '\n';
    return;
  }
  ll root = sqrt(ld(n));
  if(root * root == n) {
    cout << root - 1 << '\n';
  } else {
    cout << root << '\n';
  }
  // cout << root - 1 << '\n';
  // if(root * root == n) {
    // cout << root - 1 << '\n';
  // }
  // cout << ll(sqrt(ld(n)) * sqrt(ld(n))) << '\n';
  // cout << ll(ceil(sqrt(ld(n)) - 1)) << '\n';
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