#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll x, n, a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> n;
  for(ll i = 0; i < n; i++) {
    cin >> a >> b;
    x -= a * b;
  }
  if(x == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
