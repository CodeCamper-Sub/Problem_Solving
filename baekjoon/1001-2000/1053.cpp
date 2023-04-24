#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string _s, s;
ll answer;
vector<ll> swapper;
vector<vector<ll>> memo;

ll make_palindrome(ll start, ll end) {
  if(memo[start][end] != -1) return memo[start][end];
  if(start == end) {
    return memo[start][end] = 0;
  } else if(start + 1 == end) {
    if(s[start] == s[end]) 
      return memo[start][end] = 0;
    else 
      return memo[start][end] = 1;
  } else {
    if(s[start] == s[end]) {
      ll cost = INF;
      cost = min(cost, make_palindrome(start + 1, end) + 1);
      cost = min(cost, make_palindrome(start, end - 1) + 1);
      cost = min(cost, make_palindrome(start + 1, end - 1));
      return memo[start][end] = cost;
    } else {
      ll cost = INF;
      cost = min(cost, make_palindrome(start + 1, end) + 1);
      cost = min(cost, make_palindrome(start, end - 1) + 1);
      cost = min(cost, make_palindrome(start + 1, end - 1) + 1);
      return memo[start][end] = cost;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> _s;
  if(_s.size() == 1) {
    cout << 0 << '\n';
    return 0;
  }
  s = _s;
  memo.assign(s.size(), vector<ll>(s.size(), -1));
  answer = make_palindrome(0, s.size() - 1);

  swapper.assign(s.size() - 2, 0);
  swapper.push_back(1);
  swapper.push_back(1);
  do {
    s = _s;
    vector<ll> indices;
    for(ll i = 0; i < s.size(); i++) {
      if(swapper[i] == 1) {
        indices.push_back(i);
      }
      if(indices.size() == 2) break;
    }
    if(s[indices[0]] == s[indices[1]]) continue;
    swap(s[indices[0]], s[indices[1]]);
    memo.assign(s.size(), vector<ll>(s.size(), -1));
    answer = min(answer, make_palindrome(0, s.size() - 1) + 1);
  } while(next_permutation(swapper.begin(), swapper.end()));

  cout << answer << '\n';
  
  return 0;
}