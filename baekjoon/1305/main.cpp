#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll L;
string s;
ll pi[1001000];

void get_pi() {
  ll j = 0;
  for(ll i = 1; i < s.size(); i++) {
    while(j > 0 && s[i] != s[j]) {
      j = pi[j-1];
    }
    if(s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> L >> s;

  get_pi();

  cout << L - pi[L-1] << '\n';

  return 0;
}