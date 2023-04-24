#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, p;
vector<ll> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  a.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] == 1) {
      p = i;
    }
  }

  cout << (n - 1) / (k - 1) + ((n - 1) % (k - 1) ? 1 : 0) << '\n';
  
  return 0;
}