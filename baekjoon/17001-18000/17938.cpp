#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, p, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> p >> t;
  ll now = 0;
  ll k = 1;
  bool increasing = true;
  for(ll i = 0; i < t - 1; i++) {
    now += k;
    now %= 2 * n;

    if(k == 2 * n) {
      increasing = false;
    }
    if(k == 1) {
      increasing = true;
    }
    if(increasing) k++;
    else k--;
  }

  set<ll> should_up;
  for(ll i = 0; i < k; i++) {
    should_up.insert((now + i) % (2 * n) / 2);
  }
  if(should_up.size() > 1 && should_up.find(p - 1) != should_up.end()) {
    cout << "Dehet YeonJwaJe ^~^";
  } else {
    cout << "Hing...NoJam";
  }
  
  return 0;
}