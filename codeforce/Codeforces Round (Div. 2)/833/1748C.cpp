#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  answer = 0;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
}

void solve() {
  ll sum = 0;
  for(ll i = 0; i < n; i++) {
    if(a[i] == 0) {
      map<ll, ll> m;
      ll maxi = -INF;
      ll j;
      ll k = -INF;
      ll pre_sum = sum;
      for(j = i + 1; j < n; j++) {
        if(a[j] == 0) break;
        sum += a[j];
        m[sum]++;
        if(maxi < m[sum]) {
          maxi = max(maxi, m[sum]);
          k = sum;
        }
      }
      if(maxi == m[pre_sum] || maxi < 2) {
        // 합을 0으로 만들기
        answer += 1;
        answer += m[pre_sum];
        sum -= pre_sum;
      } else if(maxi >= 2) {
        answer += maxi;
        sum -= k;
      }
      i = j - 1;
    } else {
      sum += a[i];
      if(sum == 0) answer++;
    }
  }

  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}