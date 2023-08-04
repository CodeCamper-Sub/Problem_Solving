#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<vector<char>> grid;
ll n;

void brute_force(ll now, ll& answer, vector<bool>& flipped) {
  if(now == n) {
    vector<ll> t_cnt(n, 0);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        if((flipped[i] && grid[i][j] == 'H') || (!flipped[i] && grid[i][j] == 'T')) t_cnt[j]++;
      }
    }
    ll partial_answer = 0;
    for(ll i = 0; i < n; i++) {
      partial_answer += min(t_cnt[i], n - t_cnt[i]);
    }
    answer = min(answer, partial_answer);
  } else {
    flipped.push_back(true);
    brute_force(now + 1, answer, flipped);
    flipped.pop_back();
    flipped.push_back(false);
    brute_force(now + 1, answer, flipped);
    flipped.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  grid.resize(n, vector<char>(n));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  ll answer = INF;
  vector<bool> flipped;
  brute_force(0, answer, flipped);

  cout << answer << '\n';
  
  return 0;
}