#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, k, root;
vector<vector<ll>> e;

ll traverse(ll now) {
  ll number_of_childs = 0;
  ll result = 0;
  for(ll next: e[now]) {
    if(next == k) continue;
    number_of_childs++;
    result += traverse(next);
  }
  if(number_of_childs == 0) result++;
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n);
  for(ll i = 0; i < n; i++) {
    ll p;
    cin >> p;
    if(p == -1) {
      root = i;
    } else {
      e[p].push_back(i);
    }
  }

  cin >> k;

  if(root == k) {
    cout << 0 << '\n';
  } else {
    cout << traverse(root) << '\n';
  }

  return 0;
}