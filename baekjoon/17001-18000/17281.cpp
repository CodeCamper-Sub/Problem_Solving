#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, answer;
vector<vector<ll>> players, other_players;

pair<ll, ll> get_score(ll status, ll shift) {
  ll next_status = (status << shift) % (1ll << 4);
  next_status |= (1ll << shift);
  ll score = 0;
  ll k = (status << shift) / (1ll << 4);
  while(k) {
    score += k % 2;
    k >>= 1;
  }
  return {score, next_status};
}

ll go(vector<vector<ll>>& players, ll now, ll status, ll inning, ll out) {
  if(inning == n) return 0;
  ll next = (now + 1) % 9;
  if(players[now][inning] == 0) {
    if(out == 2) {
      return go(players, next, 0, inning + 1, 0);
    } else {
      return go(players, next, status, inning, out + 1);
    }
  } else if(players[now][inning] == 4) {
    auto [score, next_status] = get_score(status, 4);
    return score + 1 + go(players, next, 0, inning, out);
  } else {
    auto [score, next_status] = get_score(status, players[now][inning]);
    return score + go(players, next, next_status, inning, out);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  players.resize(9, vector<ll>(n));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < 9; j++) {
      cin >> players[j][i];
    }
  }

  for(ll i = 1; i < 9; i++) {
    other_players.push_back(players[i]);
  }

  sort(other_players.begin(), other_players.end());
  answer = 0;
  do {
    vector<vector<ll>> playing_players; // 실제 타순
    for(ll i = 0; i < 3; i++) {
      playing_players.push_back(other_players[i]);
    }
    playing_players.push_back(players[0]);
    for(ll i = 3; i < 8; i++) {
      playing_players.push_back(other_players[i]);
    }
    answer = max(answer, go(playing_players, 0, 0, 0, 0));
    
  } while(next_permutation(other_players.begin(), other_players.end()));

  cout << answer << '\n';
  
  return 0;
}