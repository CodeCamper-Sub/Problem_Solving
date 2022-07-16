//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

ll n, k;
bool used[300300];
ll seq[300300];
priority_queue<ll, vector<ll>, greater<ll>> q;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  
  if(k > n / 2) {
    cout << -1 << '\n';
    return 0;
  }
  
  for(ll i = 1; i <= k; i++) {
    seq[i] = i + k;
    used[i+k] = true;
  }
  for(ll i = 0; k + i + 1 <= n - 2 * k; i++) {
    if((i / k) % 2 == 0) {
      seq[k + i + 1] = i + 1;
      used[i + 1] = true;
    } else {
      seq[k + i + 1] = (k + i + 1) + k;
      used[i+1+2*k] = true;
    }
  }
  for(ll i = 0; i < k; i++) {
    seq[n-k-i] = n-i;
    used[n-i] = true;
  }
  for(ll i = 1; i <= n; i++) {
    if(used[i] == false){
      q.push(i);
    }
  }
  for(ll i = 1; i <= n; i++) {
    if(seq[i] == 0) {
      seq[i] = q.top();
      q.pop();
    }
  }
  for(ll i = 1; i <= n; i++) {
    cout << seq[i] << ' ';
  }
  cout << '\n';
  
  
  return 0;
}

