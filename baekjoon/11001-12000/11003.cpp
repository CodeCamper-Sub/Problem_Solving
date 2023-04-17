#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, l, a;
deque<pair<ll, ll>> q;  // {value, index}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> l;
  for(ll i = 0; i < n; i++) {
    while(!q.empty() && i - q.front().second >= l) {
      q.pop_front();
    }
    cin >> a;
    while(!q.empty() && q.back().first >= a) {
      q.pop_back();
    }
    q.push_back({a, i});
    cout << q.front().first << ' ';
  }
  
  return 0;
}