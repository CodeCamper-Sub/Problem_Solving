#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

map<string, ll> team;
string s, u;
vector<double> answer;
vector<tuple<ll, ll, double, double, double>> games;
ll fact[5] = {1, 1, 2, 6, 24};

double combination(ll n, ll r) {
  return double(fact[n]) / double(fact[n - r]) / double(fact[r]);
}

void backtracking(ll now, vector<ll>& path) {
  if(now == 6) {
    // 순위 계산
    vector<pair<ll, ll>> scoreboard;
    double p = 1;
    for(ll i = 0; i < 4; i++) scoreboard.push_back({0, i});
    for(ll i = 0; i < games.size(); i++) {
      ll a = get<0>(games[i]);
      ll b = get<1>(games[i]);
      if(path[i] == 0) {
        scoreboard[a].first += 3;
        p *= get<2>(games[i]);
      } else if(path[i] == 1) {
        scoreboard[a].first += 1;
        scoreboard[b].first += 1;
        p *= get<3>(games[i]);
      } else {
        scoreboard[b].first += 3;
        p *= get<4>(games[i]);
      }
    }
    if(p == 0) return;
    sort(scoreboard.begin(), scoreboard.end(), greater<>());
    ll i = 0;
    vector<ll> first_teams, second_teams;
    while(i < 4) {
      first_teams.push_back(scoreboard[i].second);
      i++;
      if(i < 4 && scoreboard[i - 1].first != scoreboard[i].first) break;
    }
    while(i < 4) {
      second_teams.push_back(scoreboard[i].second);
      i++;
      if(i < 4 && scoreboard[i - 1].first != scoreboard[i].first) break;
    }

    if(first_teams.size() >= 2) {
      // 공동 1등이 2명 이상
      for(ll i = 0; i < first_teams.size(); i++) {
        answer[first_teams[i]] += p * combination(first_teams.size() - 1, 1) / combination(first_teams.size(), 2);
      }
    } else if(second_teams.size() >= 2) {
      // 공동 2등이 2명 이상
      answer[first_teams[0]] += p;
      for(ll i = 0; i < second_teams.size(); i++) {
        answer[second_teams[i]] += p / double(second_teams.size()); 
      }
    } else {
      answer[first_teams[0]] += p;
      answer[second_teams[0]] += p;
    }
  } else {
    for(ll i = 0; i < 3; i++) {
      path.push_back(i);
      backtracking(now + 1, path);
      path.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  answer.assign(4, 0);
  for(ll i = 0; i < 4; i++) {
    cin >> s;
    team[s] = i;
  }

  games.resize(6);
  for(auto &[a, b, w, d, l]: games) {
    cin >> s >> u >> w >> d >> l;
    a = team[s];
    b = team[u];
  }

  vector<ll> path;
  backtracking(0, path);

  cout.precision(10);
  cout << fixed;
  for(ll i = 0; i < 4; i++) {
    cout << answer[i] << '\n';
  }
  
  return 0;
}