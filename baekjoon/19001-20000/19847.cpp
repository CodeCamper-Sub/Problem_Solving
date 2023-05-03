#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> x, cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll _x;
    cin >> _x;
    if(i == 0 || x.back() > _x) x.push_back(_x);
  }
  reverse(x.begin(), x.end());
  cnt.resize(x.back());
  for(ll i = 0; i < x.size(); i++) {
    if(i == 0) {
      for(ll j = 0; j < x[i]; j++) {
        cnt[j] = j;
      }
    } else {
      for(ll j = x[i - 1]; j < x[i]; j++) {
        cnt[j] = cnt[j % x[i - 1]];
      }
    }
  }
  ll sum = 0;
  for(ll i = 0; i < cnt.size(); i++) {
    sum += cnt[i];
  }

  cout << fixed;
  cout.precision(12);

  cout << double(sum) / double(cnt.size()) << '\n';
  
  return 0;
}