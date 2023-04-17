#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll d, dx, dy;
string _s;
vector<ll> s;

pair<ll, ll> as_coord(ll now, ll x_start, ll x_end, ll y_start, ll y_end) {
  if(now == s.size()) return {x_start, y_start};
  ll x_mid = (x_start + x_end) >> 1;
  ll y_mid = (y_start + y_end) >> 1;
  if(s[now] == 1) {
    return as_coord(now + 1, x_mid + 1, x_end, y_mid + 1, y_end);
  } else if(s[now] == 2) {
    return as_coord(now + 1, x_start, x_mid, y_mid + 1, y_end);
  } else if(s[now] == 3) {
    return as_coord(now + 1, x_start, x_mid, y_start, y_mid);
  } else {
    return as_coord(now + 1, x_mid + 1, x_end, y_start, y_mid);
  }
}

bool include(ll start, ll end, ll target) {
  return start <= target && target <= end;
}

string encode(ll ny, ll nx, ll x_start, ll x_end, ll y_start, ll y_end) {
  if(x_start == x_end || y_start == y_end) return "";
  ll x_mid = (x_start + x_end) >> 1;
  ll y_mid = (y_start + y_end) >> 1;
  if(include(x_mid + 1, x_end, nx) && include(y_mid + 1, y_end, ny)) {
    return "1" + encode(ny, nx, x_mid + 1, x_end, y_mid + 1, y_end);
  } else if(include(x_start, x_mid, nx) && include(y_mid + 1, y_end, ny)) {
    return "2" + encode(ny, nx, x_start, x_mid, y_mid + 1, y_end);
  } else if(include(x_start, x_mid, nx) && include(y_start, y_mid, ny)) {
    return "3" + encode(ny, nx, x_start, x_mid, y_start, y_mid);
  } else {
    return "4" + encode(ny, nx, x_mid + 1, x_end, y_start, y_mid);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> d;
  cin >> _s;
  for(ll i = 0; i < _s.size(); i++) s.push_back(_s[i] - '0');
  cin >> dx >> dy;

  auto [x, y] = as_coord(0, 0, (1ll << d) - 1, 0, (1ll << d) - 1);
  ll nx = x + dx;
  ll ny = y + dy;
  if(nx < 0 || nx >= (1ll << d) || ny < 0 || ny >= (1ll << d)) {
    cout << "-1\n";
    return 0;
  }
  cout << encode(ny, nx, 0, (1ll << d) - 1, 0, (1ll << d) - 1);
}