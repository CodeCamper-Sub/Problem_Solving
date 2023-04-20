#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, digit;
vector<vector<bool>> visited;
queue<pair<ll, ll>> q;

ll exchange(ll n, ll i, ll j) {
  vector<ll> v;
  while(n) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  swap(v[i], v[j]);
  ll result = 0, k = 1;
  for(ll i = v.size() - 1; i >= 0; i--) {
    result += v[i] * k;
    k *= 10;
  }
  return result;
}

ll get_digit(ll n) {
  ll result = 0;
  while(n) {
    result++;
    n /= 10;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  visited.assign(11, vector<bool>(1000010, false));

  digit = get_digit(n);

  visited[0][n] = true;
  q.push({0, n});
  while(q.size()) {
    auto [nk, now] = q.front();
    q.pop();
    for(ll i = 0; i < digit; i++) {
      for(ll j = i + 1; j < digit; j++) {
        ll next = exchange(now, i, j);
        if(!visited[nk + 1][next] && digit == get_digit(next)) {
          visited[nk + 1][next] = true;
          if(nk + 1 < k) {
            q.push({nk + 1, next});
          }
        }
      }
    }
  }

  ll answer = -INF;
  for(ll i = 0; i <= 1000000; i++) {
    if(visited[k][i]) answer = max(answer, i);
  }

  if(answer == -INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}