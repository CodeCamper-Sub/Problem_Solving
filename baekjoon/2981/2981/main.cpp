//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
typedef long long ll;
using namespace std;

ll n, arr[110];
queue<ll> difference;
set<ll> factor;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for(ll i = 1; i < n; i++) {
    difference.push(arr[i] - arr[i-1]);
  }
  while(difference.size() > 1) {
    ll a = difference.front();
    difference.pop();
    ll b = difference.front();
    difference.pop();
    difference.push(gcd(a, b));
  }
  for(ll i = 1; i * i <= difference.front(); i++) {
    if(difference.front() % i == 0) {
      factor.insert(i);
      factor.insert(difference.front() / i);
    }
  }
  factor.erase(1);
  for(auto iter = factor.begin(); iter != factor.end(); iter++) {
    cout << *iter << ' ';
  }
  cout << '\n';
  
  return 0;
}

