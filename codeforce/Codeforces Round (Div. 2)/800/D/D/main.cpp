//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, answer, carrier, next_carrier;
ll p[200200];
ll indegree[200200];
ll l[200200];
ll r[200200];
ll lazy_r[200200];
queue<ll> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    testcase();
  }
  return 0;
}

void testcase() {
  answer = 0;
  cin >> n;
  for(ll i = 2; i <= n; i++) {
    cin >> p[i];
    indegree[p[i]]++;
  }
  for(ll i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    if(indegree[i] == 0) {
      q.push(i);
    }
    lazy_r[i] = 0;
  }
  while(!q.empty()) {
    ll leaf = q.front();
    q.pop();
    if(l[leaf] > 0) {
      answer++;
      carrier = r[leaf];
    } else if(lazy_r[leaf] > 0) {
      carrier = min(r[leaf], lazy_r[leaf]);
    }
    ll parent = p[leaf];
    l[parent] = max(l[parent] - carrier, 0ll);
    lazy_r[parent] += carrier;
    indegree[parent]--;
    if(indegree[parent] == 0){
      q.push(parent);
    }
  }
  cout << answer << '\n';
}

