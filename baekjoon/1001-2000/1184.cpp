#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer;
vector<vector<ll>> grid, psum;

ll get_sum(ll sy, ll sx, ll ey, ll ex) {
  ll sum = psum[ey][ex];
  if(sy > 0) {
    sum -= psum[sy - 1][ex];
  }
  if(sx > 0) {
    sum -= psum[ey][sx - 1];
  }
  if(sy > 0 && sx > 0) {
    sum += psum[sy - 1][sx - 1];
  }
  return sum;
}

ll check(ll y, ll x) {
  map<ll, ll> cnt;
  ll result = 0;
  for(ll i = 0; i <= y; i++) {
    for(ll j = 0; j <= x; j++) {
      cnt[get_sum(i, j, y, x)]++;
    }
  }
  for(ll i = y + 1; i < n; i++) {
    for(ll j = x + 1; j < n; j++) {
      result += cnt[get_sum(y + 1, x + 1, i, j)];
    }
  }
  cnt.clear();
  for(ll i = 0; i <= y; i++) {
    for(ll j = x; j < n; j++) {
      cnt[get_sum(i, x, y, j)]++;
    }
  }
  for(ll i = y + 1; i < n; i++) {
    for(ll j = 0; j < x; j++) {
      result += cnt[get_sum(y + 1, j, i, x - 1)];
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  grid.assign(n, vector<ll>(n));
  psum.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
      psum[i][j] = grid[i][j] + (j > 0 ? psum[i][j - 1] : 0);
    }
    for(ll j = 0; j < n; j++) {
      psum[i][j] += (i > 0 ? psum[i - 1][j] : 0);
    }
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      answer += check(i, j);
    }
  }

  cout << answer << '\n';
  
  return 0;
}