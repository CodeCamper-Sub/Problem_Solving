#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
  sort(a.begin(), a.end());

  ll excluded = n * 15 / 100 + (n * 15 % 100 >= 50);
  ll sum = 0, cnt = 0;
  for(ll i = excluded; i < n - excluded; i++) {
    sum += a[i];
    cnt++;
  }

  if(cnt == 0) {
    cout << 0 << '\n';
    return 0;
  }

  ll answer;
  if(cnt % 2) answer = sum / cnt + (sum % cnt > cnt / 2);
  else answer = sum / cnt + (sum % cnt >= cnt / 2);

  cout << answer << '\n';
  
  return 0;
}