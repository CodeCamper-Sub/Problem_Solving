#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  ll left = 1, right = n;
  while(left <= right) {
    ll mid = (left + right) / 2;
    cout << "? " << mid << '\n';
    cout.flush();
    cin >> r;
    if(r == 0) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << "! " << right << '\n';
  
  return 0;
}