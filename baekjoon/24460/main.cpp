#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
ll grid[2020][2020];

ll divide_conquer(ll y1, ll x1, ll y2, ll x2) {
  vector<ll> v;
  if(y2 - y1 == 1 && x2 - x1 == 1) {
    v.push_back(grid[y1][x1]);
    v.push_back(grid[y1][x2]);
    v.push_back(grid[y2][x1]);
    v.push_back(grid[y2][x2]);
  } else {
    ll center_y = (y1 + y2) / 2;
    ll center_x = (x1 + x2) / 2;

    v.push_back(divide_conquer(y1, x1, center_y, center_x));
    v.push_back(divide_conquer(y1, center_x + 1, center_y, x2));
    v.push_back(divide_conquer(center_y + 1, x1, y2, center_x));
    v.push_back(divide_conquer(center_y + 1, center_x + 1, y2, x2));
  }
  sort(v.begin(), v.end());
  return v[1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  if(n == 1) {
    cout << grid[0][0] << '\n';
    return 0;
  } else {
    cout << divide_conquer(0, 0, n-1, n-1) << '\n';;
  }



  return 0;
}