#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a1, a0, c, n0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a1 >> a0;
  cin >> c;
  cin >> n0;
  
  if(c < a1) {
    cout << 0 << '\n';
  } else if(a1 * n0 + a0 <= c * n0) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }

  return 0;
}