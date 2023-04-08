#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b;
  ll answer = 0;
  while(a > 0 && b > 0) {
    ll g = gcd(a, b);
    a -= g;
    b -= g;
    answer++;
  }
  cout << answer << '\n';
  
  return 0;
}