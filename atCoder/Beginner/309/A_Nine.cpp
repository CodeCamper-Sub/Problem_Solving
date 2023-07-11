#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b;
  if((a % 3 != 0 && a + 1 == b)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return 0;
}