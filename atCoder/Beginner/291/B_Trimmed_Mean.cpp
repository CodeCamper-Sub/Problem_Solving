#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  x.assign(5 * n, 0);
  for(ll& x: x) cin >> x;
  sort(x.begin(), x.end());
  ll sum = 0;
  for(auto iter = x.begin() + n; iter < x.begin() + 4 * n; iter++) {
    sum += *iter;
  }

  cout.precision(6);
  cout << fixed;
  cout << double(sum) / double(3 * n) << '\n';
  
  return 0;
}