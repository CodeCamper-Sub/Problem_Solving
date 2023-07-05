#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<ll> x;

ll get_sum(ll k) {
  ll result = 0;
  for(ll i = 0; i < n; i++) {
    result += abs(x[i] - k * i);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  x.resize(n);

  for(ll i = 0; i < n; i++) cin >> x[i];
  ll left = 0;
  ll right = x[n - 1];
  while(left + 10 <= right) {
    ll p = (left * 2 + right) / 3;
    ll q = (left + right * 2) / 3;
    if(get_sum(p) < get_sum(q)) {
      right = q;
    } else {
      left = p;
    }
  }

  ll answer = INF;
  for(ll k = left; k <= right; k++) {
    answer = min(answer, get_sum(k));
  }

  cout << answer << '\n';
  
  return 0;
}