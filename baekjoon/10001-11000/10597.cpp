#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;
vector<ll> answer;

bool backtracking(set<ll>& used, ll now, ll status, vector<ll>& partial_answer) {
  if(now == s.size()) {
    answer = vector<ll>(partial_answer);
    return true;
  }
  ll result = false;
  if(status) {
    ll num = s[now] - '0' + status;
    if(used.find(num) == used.end() && num <= n) {
      used.insert(num);
      partial_answer.push_back(num);
      result |= backtracking( used, now + 1, 0, partial_answer);
      if(!result) {
        used.erase(num);
        partial_answer.pop_back();
      }
    } else {
      return false;
    }
  } else {
    ll num = s[now] - '0';
    if(num == 0) return false;
    if(used.find(num) == used.end() && num <= n) {
      used.insert(num);
      partial_answer.push_back(num);
      result |= backtracking(used, now + 1, 0, partial_answer);
      if(!result) {
        used.erase(num);
        partial_answer.pop_back();
      }
    }
    if(!result && num * 10 <= n) {
      result |= backtracking(used, now + 1, num * 10, partial_answer);
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  ll cnt = 0;
  for(ll i = 1; i <= 50; i++) {
    cnt += to_string(i).size();
    if(cnt == s.size()) {
      n = i;
      break;
    }
  }

  set<ll> used;
  vector<ll> partial_answer;
  backtracking(used, 0, 0, partial_answer);

  for(ll a: answer) {
    cout << a << ' ';
  }
  
  return 0;
}