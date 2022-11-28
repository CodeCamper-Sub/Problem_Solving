#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, sum;
vector<ll> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(ll i = 1; i <= 5; i++) {
    cin >> n;
    sum += n;
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  cout << sum / 5 << '\n';
  cout << v[2] << '\n';

  return 0;
}