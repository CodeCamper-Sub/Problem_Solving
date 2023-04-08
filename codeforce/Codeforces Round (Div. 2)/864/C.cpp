#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, m, a1, a2, a3, r, c;

void init() {
  cin >> n >> m;
}

void solve() {
  cout << "? 1 1\n";
  cout.flush();

  cin >> a1;
  
  if(a1 == 0) {
    cout << "! 1 1\n";
    cout.flush();
    return;
  }

  // 답은 a1 + 1열이거나 a1 + 1행임
  if(a1 + 1 > n) {
    // a1 + 1열이 답
    c = a1 + 1;
    cout << "? " << 1 << " " << c << '\n';
    cout.flush();
    cin >> a2;
    r = a2 + 1;
  } else if(a1 + 1 > m) {
    // a1 + 1행이 답
    r = a1 + 1;
    cout << "? " << r << " " << 1 << '\n';
    cout.flush();
    cin >> a2;
    c = a2 + 1;
  } else {
    cout << "? " << a1 + 1 << " " << a1 + 1 << '\n';
    cout.flush();
    cin >> a2;

    if(a2 == 0) {
      r = a1 + 1;
      c = a1 + 1;
    } else {
      cout << "? " << a1 << " " << a1 + 1 << '\n';
      cout.flush();
      cin >> a3;
      // a2 > a3 이면 열이 a1 + 1;
      // a2 < a3 같은 행 즉, 행이 a1 + 1
      if(a2 > a3) {
        c = a1 + 1;
        r = a1 - a3;
      } else {
        r = a1 + 1;
        c = a1 + 1 - a3;
      }
    }
  }
  cout << "! " << r << " " << c << '\n';
  cout.flush();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}