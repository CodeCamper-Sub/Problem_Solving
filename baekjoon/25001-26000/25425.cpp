#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, a, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> a >> k;
  cout << min(n - 1, a - k) + 1 << ' ';
  cout << (a - k) / m + ((a - k) % m ? 1 : 0) + 1 << '\n';
  
  return 0;
}