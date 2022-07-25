//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <tuple>
typedef long long ll;
using namespace std;

ll n, grid[3030][3030];
ll start_dy[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
ll start_dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
ll end_dy[9] = {-2, -2, -2, -1, -1, -1, 0, 0, 0};
ll end_dx[9] = {-2, -1 ,0, -2, -1, 0, -2, -1, 0};

bool is_same_color(pair<ll, ll> start, pair<ll, ll> end) {
  for(ll i = start.first; i <= end.first; i++) {
    for(ll j = start.second; j <= end.second; j++) {
      if(grid[i][j] != grid[start.first][start.second])
        return false;
    }
  }
  return true;
}

tuple<ll, ll, ll> divide_conquer(pair<ll, ll> start, pair<ll, ll> end) {
  if(is_same_color(start, end)) {
    if(grid[start.first][start.second] == -1) {
      return {1, 0, 0};
    } else if(grid[start.first][start.second] == 0) {
      return {0, 1, 0};
    } else {
      return {0, 0, 1};
    }
  }
  tuple<ll, ll, ll> result[9];
  ll difference = (end.first - start.first + 1) / 3;
  for(ll i = 0; i < 9; i++){
    ll start_y = start.first + difference * start_dy[i];
    ll start_x = start.second + difference * start_dx[i];
    ll end_y = end.first + difference * end_dy[i];
    ll end_x = end.second + difference * end_dx[i];
    result[i] = divide_conquer({start_y, start_x}, {end_y, end_x});
  }
  tuple<ll, ll, ll> ret = {0, 0, 0};
  for(ll i = 0; i < 9; i++) {
    get<0>(ret) += get<0>(result[i]);
    get<1>(ret) += get<1>(result[i]);
    get<2>(ret) += get<2>(result[i]);
  }
  return ret;
}


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }
  
  tuple<ll, ll, ll> answer = divide_conquer({1, 1}, {n, n});
  
  cout << get<0>(answer) << ' ' << get<1>(answer) << ' ' << get<2>(answer) << '\n';
  
  return 0;
}

