//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

ll tt, n, c, q, l, r, k;
string s;
ll sum[50];

ll binary_search_find(ll k) {
  ll lower_bound = 0;
  ll upper_bound = c;
  while(lower_bound <= upper_bound) {
    ll mid = (lower_bound + upper_bound) / 2;
    if(sum[mid] >= k) {
      upper_bound = mid - 1;
    } else {
      lower_bound = mid + 1;
    }
  }
  return lower_bound;
}

void testcase() {
  cin >> n >> c >> q;
  cin >> s;
  vector<pair<ll ,ll>> v(c+1);
  for(ll i = 0; i <= c; i++) {
    sum[i] = 0;
  }
  sum[0] = n;
  
  for(ll i = 1; i <= c; i++) {
    cin >> l >> r;
    sum[i] = sum[i-1] + r - l + 1;
    v[i] = {l , r};
  }
  for(ll i = 1; i <= q; i++) {
    cin >> k;
    ll index;
    while((index = binary_search_find(k)) > 0) {
      k = v[index].second -(sum[index] - k);
    }
    cout << s[k-1] << '\n';
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> tt;
  while(tt--) {
    testcase();
  }
  
  return 0;
}


