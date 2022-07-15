//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, l, r, left_bound, right_bound;
vector<pair<ll, ll>> interval;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> l >> r;
    interval.push_back({l, r});
  }
  sort(interval.begin(), interval.end());
  left_bound = interval[0].first;
  right_bound = interval[0].second;
  for(ll i = 1; i < interval.size(); i++) {
    if(right_bound < interval[i].first) {
      cout << left_bound << ' ' << right_bound << '\n';
      left_bound = interval[i].first;
      right_bound = interval[i].second;
    } else {
      right_bound = interval[i].second;
    }
  }
  cout << left_bound << ' ' << right_bound << '\n';
  
  return 0;
}

