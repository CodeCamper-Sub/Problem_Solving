#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, s, p;

bool is_facing(ll a, ll b) {
  if(b == 5 - a) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(6);
  for(ll& a: a) cin >> a;

  if(n == 1) {
    ll sum = 0;
    for(ll a: a) sum += a;
    sum -= *max_element(a.begin(), a.end());
    cout << sum << '\n';
    return 0;
  }

  for(ll i = 0; i < 6; i++) {
    for(ll j = i + 1; j < 6; j++) {
      if(is_facing(i, j)) continue;
      s.push_back(a[i] + a[j]);
    }
  }

  p.push_back(a[0] + a[1] + a[2]);
  p.push_back(a[0] + a[2] + a[4]);
  p.push_back(a[0] + a[4] + a[3]);
  p.push_back(a[0] + a[3] + a[1]);
  p.push_back(a[5] + a[1] + a[2]);
  p.push_back(a[5] + a[2] + a[4]);
  p.push_back(a[5] + a[4] + a[3]);
  p.push_back(a[5] + a[3] + a[1]);

  ll answer = 0;
  answer += 4 * *min_element(p.begin(), p.end());
  answer += 4 * (2 * n - 3) * *min_element(s.begin(), s.end());
  answer += (n - 2) * (5 * n - 6) * *min_element(a.begin(), a.end());

  cout << answer << '\n';
  
  return 0;
}