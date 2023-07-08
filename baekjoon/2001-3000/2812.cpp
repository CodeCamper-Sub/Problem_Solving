#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
string s;
deque<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    ll now = s[i] - '0';
    while(q.size() && q.back() < now && q.size() + s.size() - i - 1 >= n - k) q.pop_back();
    q.push_back(now);
  }

  ll cnt = n - k;
  while(cnt--) {
    cout << q.front();
    q.pop_front();
  }
  
  return 0;
}