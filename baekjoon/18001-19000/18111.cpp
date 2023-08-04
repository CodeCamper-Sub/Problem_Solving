#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, b;
vector<vector<ll>> grid;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> b;
  grid.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) {
    cin >> grid[i][j];
  }
  
  pair<ll, ll> answer;
  answer.first = INF;
  for(ll i = 0; i <= 256; i++) {
    ll blocks = b;
    ll partial_answer = 0;
    for(ll j = 0; j < n; j++) for(ll k = 0; k < m; k++) {
      if(grid[j][k] > i) {
        blocks += grid[j][k] - i;
        partial_answer += (grid[j][k] - i) * 2;
      } else if(grid[j][k] < i) {
        blocks -= i - grid[j][k];
        partial_answer += i - grid[j][k];
      }
    }
    if(blocks < 0) continue;
    if(answer.first >= partial_answer) {
      answer.first = partial_answer;
      answer.second = i;
    }
  }

  cout << answer.first << ' ' << answer.second << '\n';
  
  return 0;
}