//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <deque>
typedef long long ll;
using namespace std;

ll n, m, k;
deque<ll> d;
ll answer;

ll find(deque<ll> d, ll num) {
  ll i;
  for(i = 0; i < d.size(); i++) {
    if(num == d[i]) {
      return i;
    }
  }
  return i;
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) {
    d.push_back(i);
  }
  for(ll i = 1; i <= m; i++) {
    cin >> k;
    ll index = find(d, k);
    if(index <= d.size() / 2) {
      while(d.front() != k) {
        d.push_back(d.front());
        d.pop_front();
        answer++;
      }
    } else {
      while(d.front() != k) {
        d.push_front(d.back());
        d.pop_back();
        answer++;
      }
    }
    d.pop_front();
  }
  cout << answer << '\n';
  
  return 0;
}

