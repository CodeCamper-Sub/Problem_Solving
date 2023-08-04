#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<vector<char>> grid;
vector<ll> psum;

bool backtracking(ll now, vector<ll>& answer) {
  if(now > n) return true;
  bool result = false;
  for(ll i = -10; i <= 10; i++) {
    bool is_valid = true;
    for(ll j = 1; j <= now; j++) {
      ll sum = psum[now - 1] - psum[j - 1];
      if((grid[j][now] == '0' && sum + i != 0) || (grid[j][now] == '+' && sum + i <= 0) || (grid[j][now] == '-' && sum + i >= 0)) {
        is_valid = false;
        break;
      }
    }
    if(!is_valid) continue;
    psum[now] = psum[now - 1] + i;
    answer.push_back(i);
    result |= backtracking(now + 1, answer);
    if(result) break;
    else answer.pop_back();
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  psum.assign(n + 1, 0);
  grid.assign(n + 1, vector<char>(n + 1));
  for(ll i = 1; i <= n; i++) {
    for(ll j = i; j <= n; j++) {
      cin >> grid[i][j];
    }
  }

  vector<ll> answer;
  backtracking(1, answer);
  for(ll& a: answer) {
    cout << a << ' ';
  }
  
  return 0;
}