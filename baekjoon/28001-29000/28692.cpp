#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll Sx, Sy, Sxx, Sxy;
ll n;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  Sx = 0;
  Sy = 0;
  Sxx = 0;
  Sxy = 0;
  for(auto& [x, y]: v) {
    cin >> x >> y;
    Sx += x;
    Sy += y;
    Sxx += x * x;
    Sxy += x * y;
  }

  if(Sx * Sx % Sxx) {
    ll a_divdend = n * Sxy - Sx * Sy;
    ll a_divider = n * Sxx - Sx * Sx;
    double a = double(a_divdend) / double(a_divider);

    double b = double(double(Sy) - a * double(Sx)) / double(n);

    cout << fixed;
    cout.precision(10);
    cout << a << ' ' << b;
  } else {
    cout << "EZPZ";
  }
  
  return 0;
}