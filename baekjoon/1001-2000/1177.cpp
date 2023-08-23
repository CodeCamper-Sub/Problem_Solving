#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, R, b_x, b_y, b_v_x, b_v_y;
map<ll, ll> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> R >> b_x >> b_y >> b_v_x >> b_v_y;
  for(ll i = 0; i < n; i++) {
    ll s_x, s_y, s_v_x, s_v_y;
    cin >> s_x >> s_y >> s_v_x >> s_v_y;
    ll delta_x = (b_x - s_x);
    ll delta_y = (b_y - s_y);
    ll delta_v_x = (b_v_x - s_v_x);
    ll delta_v_y = (b_v_y - s_v_y);

    ll a = delta_v_x * delta_v_x + delta_v_y * delta_v_y;
    ll b = 2 * (delta_x * delta_v_x + delta_y * delta_v_y);
    ll c = delta_x * delta_x + delta_y * delta_y;

    ll r = R * R;
    if(a != 0) {
      if(b * b - 4 * a * (c - r) >= 0) {
        double _alpha = (double(-b) - sqrt(double(b * b) - double(4 * a * (c - r)))) / double(2 * a);
        double _beta = (double(-b) + sqrt(double(b * b) - double(4 * a * (c - r)))) / double(2 * a);

        ll alpha = _alpha * 100000;
        ll beta = _beta * 100000;

        if(alpha > 0) {
          v[alpha]++;
          v[beta]--;
        } else if(beta > 0) {
          v[0]++;
          v[beta]--;
        }
      }
    } else if(a == 0 && b != 0) {
      if(b > 0) {
        double _beta = double(r - c) / double(b);
        ll beta = _beta * 100000;
        if(beta > 0) {
          v[0]++;
          v[beta]--;
        }
      } else { // b < 0
        double _alpha = double(r- c) / double(b);
        ll alpha = _alpha * 100000;
        if(alpha >= 0) {
          v[alpha]++;
        } else {
          v[0]++;
        }
      }
    } else if(a == 0 && b == 0) {
      if(c <= r) {
        v[0]++;
      }
    }
  }

  ll answer = 0;
  ll now = 0;
  for(auto [_, delta]: v) {
    now += delta;
    answer = max(answer, now);
  }

  cout << answer << '\n';

  
  return 0;
}