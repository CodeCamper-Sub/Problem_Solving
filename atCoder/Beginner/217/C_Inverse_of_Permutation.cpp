#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<ll> cnt;
ll n,p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cnt.resize(n + 1);
  for(ll i = 0; i < n; i++) {
    cin >> p;
    cnt[p] = i + 1;
  }
  for(ll i = 1; i <= n; i++) {
    cout << cnt[i] << ' ';
  }
  
  return 0;
}