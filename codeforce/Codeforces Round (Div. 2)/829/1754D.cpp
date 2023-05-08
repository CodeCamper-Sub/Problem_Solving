#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, x;
vector<ll> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> x;
  cnt.resize(x + 1);
  for(ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    cnt[a]++;
  }
  for(ll i = 1; i < x; i++) {
    cnt[i + 1] += cnt[i] / (i + 1);
    if(cnt[i] % (i + 1)) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  
  return 0;
}