#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll l, r, x, y, cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> l >> r >> x >> y;
  if(l > r) {
    swap(l, r);
  }
  if(y < 0 || y >= abs(x)) {
    cout << "Unknwon Number\n";
    return 0;
  }
  x = abs(x);

  ll now = l;
  ll nowr = now % x;
  nowr = nowr < 0 ? nowr + x : nowr;
  if(nowr < y) {
    now += y - nowr;
    nowr = y;
  } else if(nowr > y) {
    now += x + y - nowr;
    nowr = y;
  }
  if(r < now) {
    cout << "Unknwon Number\n";
    return 0;
  } else {
    if(now + x <= r) {
      cout << "Unknwon Number\n";
      return 0;
    } else {
      cout << now << '\n';
      return 0;
    }
  }
  
  return 0;
}