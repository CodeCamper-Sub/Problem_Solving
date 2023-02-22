#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  ll sum = 0;
  for(ll i = 1; i <= n-1; i++) for(ll j = i + 1; j <= n; j++) sum++;
  cout << sum << '\n';
  cout << 2 << '\n';

  return 0;
}