//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n;
vector<ll> x, sorted_x;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  x = vector<ll>(n);
  sorted_x = vector<ll>(n);
  for(ll i = 0; i < n; i++) {
    cin >> x[i];
    sorted_x[i] = x[i];
  }
  sort(sorted_x.begin(), sorted_x.end());
  sorted_x.erase(unique(sorted_x.begin(), sorted_x.end()), sorted_x.end());
  for(ll i = 0; i < x.size(); i++) {
    auto iter = lower_bound(sorted_x.begin(), sorted_x.end(), x[i]);
    cout << distance(sorted_x.begin(), iter) << ' ';
  }
  cout << '\n';
  
  return 0;
}

