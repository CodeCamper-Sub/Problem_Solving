#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  vector<ll> divisers;
  for(ll i = 1; i <= 9; i++) {
    if(n % i == 0) divisers.push_back(i);
  }

  for(ll i = 0; i <= n; i++) {
    bool found = false;
    for(ll diviser: divisers) {
      if(i % (n / diviser) == 0) {
        cout << diviser;
        found = true;
        break;
      }
    }
    if(!found) {
      cout << '-';
    }
  }
  
  return 0;
}