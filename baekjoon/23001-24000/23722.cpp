#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<ll> a(4);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(true) {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    if(!a[0] && !a[1] && !a[2] && !a[3]) break;

    while(true) {
      ll zero_cnt = 0;
      ll mini = INF;
      ll idx = -1;
      for(ll i = 0; i < 4; i++) {
        if(!a[i]) zero_cnt++;
        if(a[i] && mini > a[i]) {
          mini = a[i];
          idx = i;
        }
      }

      if(zero_cnt == 3) {
        cout << mini << '\n';
        break;
      }

      for(ll i = 0; i < 4; i++) {
        if(!a[i] || idx == i) continue;
        a[i] -= mini;
      }
    }
  }

  
  return 0;
}