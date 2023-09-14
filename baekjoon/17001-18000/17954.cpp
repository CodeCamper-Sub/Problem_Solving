#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

deque<ll> q1, q2;
ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  if(n == 1) {
    cout << 2 << '\n';
    cout << 1 << '\n';
    cout << 2 << '\n';
    return 0;
  }

  q1.push_back(2 * n);
  q2.push_back(2 * n - 2);


  for(ll i = 1; i <= n - 2; i++) {
    q1.push_back(i);
  }

  for(ll i = n - 1; i <= 2 * n - 4; i++) {
    q2.push_back(i);
  }

  q1.push_back(2 * n - 1);
  q2.push_back(2 * n - 3);

  ll answer = 0;
  deque<ll> q3 = q1, q4 = q2;

  ll sum = 2 * n * (2 * n + 1) / 2;
  for(ll i = 0; i < 2 * n; i++) {
    answer += sum * i;
    ll a1 = INF, a2 = INF, a3 = INF, a4 = INF;
    if(q1.size()) {
      a1 = q1.front();
      a2 = q1.back();
    }
    if(q2.size()) {
      a3 = q2.front();
      a4 = q2.back();
    }
    ll mini = min(a1, min(a2, min(a3, a4)));

    if(mini == a1) {
      q1.pop_front();
      sum -= a1; 
    } else if(mini == a2) {
      q1.pop_back();
      sum -= a2;
    } else if(mini == a3) {
      q2.pop_front();
      sum -= a3;
    } else {
      q2.pop_back();
      sum -= a4;
    }
  }

  cout << answer << '\n';
  while(q3.size()) {
    cout << q3.front() << ' ';
    q3.pop_front();
  }
  cout << '\n';
  while(q4.size()) {
    cout << q4.front() << ' ';
    q4.pop_front();
  }
  
  return 0;
}