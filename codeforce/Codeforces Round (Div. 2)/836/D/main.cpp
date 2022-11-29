#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
ll k = 2;

ll calculate_lowerbound(ll n) {
  ll denominator = (n + k) * (n + k) - (n - 1) * (n + k) + (n - 1) * (n - 2) / 2;
  ll divider = n;
  if(denominator % divider == 0) {
    return denominator / divider;
  } else {
    return denominator / divider + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin >> T;
  while(T--) {
    cin >> n;
    ll a = calculate_lowerbound(n);
    ll b = a + n + k;
    vector<ll> ans;
    ll sum = 0;
    ans.push_back(a);
    sum += a;
    for(ll i = 1; i <= n - 2; i++) {
      ans.push_back(a + i);
      sum += a + i;
    }
    ans.push_back(b);
    sum += b;
    for(ll i = ans.size() - 2; i > 0; i--) {
      if((ans[i + 1] - 1 - ans[i]) <= (b - a) * (b - a) - sum) {
        ll delta = ans[i + 1] - 1 - ans[i];
        sum += delta;
        ans[i] += delta;
      } else {
        ll delta = (b - a) * (b - a) - sum;
        sum += delta;
        ans[i] += delta;
      }
      if((b - a) * (b - a) <= sum) {
        break;
      }
    }
    for(ll i = 0; i < ans.size(); i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}