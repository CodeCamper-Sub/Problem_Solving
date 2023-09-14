#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define lcm3(x, y, z) lcm(x, lcm(y, z))
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, p;
vector<ll> pre, after;
ll a, b, c;
ll d, e, f;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> p;
  pre.resize(n);
  after.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> after[i];
  }

  ll divider = 100;
  while(p > 0 && p--) divider *= 10;

  ll answer_0 = 1;
  for(ll i = 0; i < n; i++) {
    answer_0 = lcm(answer_0, divider / gcd(pre[i], divider));
  }

  for(ll i = 0; i < n; i++) {
    pre[i] = pre[i] * answer_0 / divider;
  }

  ll answer_1_lcm = 1;
  for(ll i = 0; i < n; i++) {
    answer_1_lcm = lcm(answer_1_lcm, divider / gcd(after[i], divider));
  }

  for(ll i = 1; true; i++) {
    ll answer_1 = answer_1_lcm * i;
    if(answer_0 > answer_1) continue;
    bool is_valid = true;
    for(ll j = 0; j < n; j++) {
      if(pre[j] > after[j] * answer_1 / divider) {
        is_valid = false;
        break;
      }
    }
    if(!is_valid) continue;
    cout << answer_0 << ' ' << answer_1 << '\n';
    return 0;
  }
  
  return 0;
}