//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, grid[200][200];

bool isSame(pair<ll, ll> a, pair<ll, ll> b) {
  return a.first == b.first && a.second == b.second;
}

pair<ll, ll> divide_conquer(pair<ll, ll> start, pair<ll, ll> end) {
  if(start.first == end.first && start.second == end.second) {
    if(grid[start.first][start.second] == 0) {
      return {1, 0};
    } else {
      return {0, 1};
    }
  }
  pair<ll, ll> result[4];
  ll width = end.second - start.second + 1;
  ll height = end.first - start.first + 1;
  result[0] = divide_conquer(start, {end.first - height / 2, end.second - width / 2});
  result[1] = divide_conquer({start.first, start.second + width / 2}, {end.first - height / 2, end.second});
  result[2] = divide_conquer({start.first + height / 2, start.second}, {end.first, end.second - width / 2});
  result[3] = divide_conquer({start.first + height / 2, start.second + width / 2}, end);
  
  bool same_flag = true;
  for(ll i = 1; i <= 3; i++) {
    if(!isSame(result[i], result[i-1])) {
      same_flag = false;
    }
  }
  if(!isSame(result[0], {0, 1}) && !isSame(result[0], {1, 0})) {
    same_flag = false;
  }
  if(same_flag) {
    return result[0];
  } else {
    pair<ll, ll> ret = {0, 0};
    for(ll i = 0; i <= 3; i++){
      ret.first += result[i].first;
      ret.second += result[i].second;
    }
    return ret;
  }
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
  
  pair<ll, ll> answer = divide_conquer({1, 1}, {n, n});
  cout << answer.first << ' ' << answer.second << '\n';
  
  return 0;
}

