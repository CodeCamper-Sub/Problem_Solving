#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Score {
  ll g, s, b;
  
  bool operator<(Score& rhs) {
    if(g != rhs.g) return g < rhs.g;
    else if(s != rhs.s) return s < rhs.s;
    else return b < rhs.b;
  }
};

ll N, L, answer;
Score first;
vector<Score> scores;
vector<pair<Score, ll>> candidates; // 현재 점수, 받은 추가 메달의 수

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> L;
  scores.resize(N - 1);
  for(ll i = 0; i < N; i++) {
    if(i == 0) {
      cin >> first.g >> first.s >> first.b;
    } else {
      cin >> scores[i].g >> scores[i].s >> scores[i].b;
    }
  }
  first.g += L;
  sort(scores.begin(), scores.end(), [](auto a, auto b) {
    return b < a;
  });
  answer = 0;
  
  for(ll i = 0; i < scores.size(); i++) {
    if(first < scores[i]) answer++;
    else if(first.g == scores[i].g) {
      candidates.push_back({scores[i], 0});
    } else {
      break;
    }
  }

  

  
  return 0;
}