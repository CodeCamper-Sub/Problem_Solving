#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

vector<ll> num, multiplier;
ll n;
vector<string> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  s.resize(n);
  multiplier.assign(10, 0);
  vector<bool> cant_be_zero(10, false);
  for(string& s: s) {
    cin >> s;
    reverse(s.begin(), s.end());
    cant_be_zero[s.back() - 'A'] = true;
    ll k = 1;
    for(ll i = 0; i < s.size(); i++) {
      multiplier[s[i] - 'A'] += k;
      k *= 10;
    }
  }
  
  num.resize(10);
  iota(num.begin(), num.end(), 0);

  

  ll answer = 0;
  do {
    bool is_valid = true;
    ll partial_answer = 0;
    for(ll i = 0; i < 10; i++) {
      partial_answer += multiplier[i] * num[i];
      if(num[i] == 0 && cant_be_zero[i]) {
        is_valid = false;
      }
    }
    if(!is_valid) continue;
    answer = max(answer, partial_answer);
  } while(next_permutation(num.begin(), num.end()));

  cout << answer << '\n';
  
  return 0;
}