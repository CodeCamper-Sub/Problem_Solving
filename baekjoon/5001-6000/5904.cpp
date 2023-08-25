#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> l;

char recursion(ll now, ll n) {
  if(now == 0) {
    return "moo"[n - 1];
  }
  if(n <= l[now - 1]) {
    return recursion(now - 1, n);
  } else if(n <= l[now - 1] + now + 3) {
    if(n == l[now - 1] + 1) return 'm';
    else return 'o';
  } else {
    return recursion(now - 1, n - (l[now - 1] + now + 3));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  l.push_back(3);
  while(l.back() < ll(1e10)) {
    l.push_back(2 * l.back() + ll(l.size()) + 3);
  }
  
  cout << recursion(ll(l.size()) - 1, n);
  
  return 0;
}