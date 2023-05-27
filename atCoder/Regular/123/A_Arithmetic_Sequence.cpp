#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll a, b, c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b >> c;
  ll answer = INF;
  if(2 * b < a + c) {
    if((a + c - 2 * b) % 2 == 0) {
      answer = (a + c - 2 * b) / 2;
    } else {
      answer = (a + c + 1 - 2 * b) / 2 + 1;
    }
  } else {
    answer = 2 * b - a - c;
  }

  cout << answer << '\n';

  return 0;
}