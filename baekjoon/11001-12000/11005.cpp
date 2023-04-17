#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> b;
  if(n == 0) cout << 0 << '\n';

  string answer = "";
  
  ll k = 1;
  while(n >= k) k *= b;
  k /= b;
  while(k) {
    if((n / k) <= 9) answer += '0' + (n / k);
    else answer += 'A' + (n / k) - 10;
    n %= k;
    k /= b;
  }

  cout << answer << '\n';

  return 0;
}