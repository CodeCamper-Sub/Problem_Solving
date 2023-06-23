#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer;
map<string, ll> third;
map<string, map<string, ll>> second;  // 첫번째 key로 시작하는 문자열들 중에서, 두번째 key도 매칭되는 문자열의 수
map<string, ll> second_max;
vector<string> third_keys;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> s;
    third[s.substr(4, 2)]++;
    second[s.substr(4, 2)][s.substr(2, 2)]++;
  }

  for(auto [key, m]: second) {
    for(auto [_, value]: m) {
      second_max[key] = max(second_max[key], value);
    }
  }

  for(auto [key, _]: third) third_keys.push_back(key);

  answer = 300000;
  // 3등 당첨자를 1명 이상 뽑는 경우
  for(ll i = 0; i < third_keys.size(); i++) {
    for(ll j = i; j < third_keys.size(); j++) {
      for(ll k = j; k < third_keys.size(); k++) {
        ll cnt = third[third_keys[i]];
        if(i != j) {
          cnt += third[third_keys[j]];
        }
        if(j != k) {
          cnt += third[third_keys[k]];
        }
        answer = max(answer, cnt * 500);
        for(auto [key, value]: second_max) {
          if(key.compare(third_keys[i]) == 0 || key.compare(third_keys[j]) == 0 || key.compare(third_keys[k]) == 0) continue;
          if(cnt + third[key] < n) {
            answer = max(answer, cnt * 500 + value * 4000 + 300000);
          } else if(cnt < n) {
            answer = max(answer, cnt * 500 + value * 4000);
            answer = max(answer, cnt * 500 + 300000);
          }
        }
      }
    }
  }

  // 3등 당첨자를 한명도 뽑지 않는 경우
  for(auto [key, value]: second_max) {
    if(third[key] < n) {
      answer = max(answer, value * 4000 + 300000);
    } else {
      answer = max(answer, value * 4000);
    }
  }

  cout << answer << '\n';
  
  return 0;
}