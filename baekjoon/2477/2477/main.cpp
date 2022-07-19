//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

ll k, d, r;
ll used[10], big_area, small_area;
queue<pair<ll, ll>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> k;
  for(ll i = 1; i <= 6; i++ ){
    cin >> d >> r;
    used[d]++;
    q.push({d, r});
  }
  while(used[q.front().first] == 1) {
    q.push(q.front());
    q.pop();
  }
  while(used[q.front().first] != 1) {
    q.push(q.front());
    q.pop();
  }
  big_area = q.front().second;
  q.pop();
  big_area *= q.front().second;
  q.pop();
  q.pop();
  small_area = q.front().second;
  q.pop();
  small_area *= q.front().second;
  
  cout << (big_area - small_area)*k << '\n';
  
  return 0;
}

