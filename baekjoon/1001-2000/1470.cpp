#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Score {
  ll g, s, b;

  bool operator>(const Score& rhs) {
    if(g != rhs.g) return g > rhs.g;
    else if(s != rhs.s) return s > rhs.s;
    else return b > rhs.b;
  }
};

ll N, L;
Score first;
vector<Score> scores, candidates;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> L;
  scores.resize(N - 1);
  cin >> first.g >> first.s >> first.b;
  for(ll i = 0; i < N - 1; i++) {
    cin >> scores[i].g >> scores[i].s >> scores[i].b;
  }

  first.g += L;

  sort(scores.begin(), scores.end(), [](Score a, Score b) {
    return a > b;
  });

  ll answer = 1;
  for(Score s: scores) {
    if(s > first) answer++;
    else if(s.g == first.g) {
      candidates.push_back(s);
    } else {
      break;
    }
  }

  dp.assign(candidates.size() + 1, vector<ll>(L + 1, -1));
  dp[0][L] = L;
  for(ll i = 1; i <= candidates.size(); i++) {
    Score candidate = candidates[i - 1];
    bool is_possible = false;
    for(ll j = 0; j <= L; j++) {
      if(dp[i - 1][j] == -1) continue;
      // 은메달 더 주기
      if(j >= first.s - candidate.s + 1 && dp[i - 1][j] != -1) {
        is_possible = true;
        ll delta = first.s - candidate.s + 1;
        dp[i][j - delta] = max(dp[i][j - delta], dp[i - 1][j]);
      }
      // 은메달은 같게, 동메달 더 주기
      if(j >= first.s - candidate.s && dp[i-1][j] >= max(0ll, first.b - candidate.b + 1) && L >= first.s - candidate.s + max(0ll, first.b - candidate.b + 1)) {
        ll ds = first.s - candidate.s;
        ll db = max(0ll, first.b - candidate.b + 1);
        is_possible = true;
        dp[i][j - ds] = max(dp[i][j - ds], dp[i - 1][j] - db);
      }
    }
    if(is_possible) answer++;
    else break;
  }

  cout << answer << '\n';

  return 0;
}