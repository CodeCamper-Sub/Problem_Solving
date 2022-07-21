//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll n;
char grid[100][100];

bool is_same_color(pair<ll, ll> start, pair<ll, ll> end) {
  for(ll i = start.first; i <= end.first; i++) {
    for(ll j = start.second; j <= end.second; j++) {
      if(grid[i][j] != grid[start.first][start.second]) {
        return false;
      }
    }
  }
  return true;
}

string divide_conquer(pair<ll, ll> start, pair<ll, ll> end) {
  string ret = "";
  if(is_same_color(start, end)) {
    ret = ret + grid[start.first][start.second];
  } else {
    ret += "(";
    ll difference = (end.first - start.first + 1) / 2;
    ret += divide_conquer(start, {end.first - difference, end.second - difference});
    ret += divide_conquer({start.first, start.second + difference}, {end.first - difference, end.second});
    ret += divide_conquer({start.first + difference, start.second}, {end.first, end.second - difference});
    ret += divide_conquer({start.first + difference, start.second + difference}, end);
    ret += ")";
  }
  return ret;
}


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++){
      cin >> grid[i][j];
    }
  }
  
  cout << divide_conquer({1, 1}, {n, n});
  
  return 0;
}

