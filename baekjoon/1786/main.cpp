#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

void make_pi();
void kmp();

string t, p;
ll pi[1001000];
vector<ll> answer;

void make_pi() {
  ll j = 0;
  for(ll i = 1; i < p.size(); i++) {
    while(j > 0 && p[j] != p[i]) {
      j = pi[j-1];
    }
    if(p[i] == p[j]) {
      pi[i] = ++j;
    }
  }
}

void kmp() {
  ll j = 0;
  for(ll i = 0; i < t.size(); i++) {
    while(j > 0 && t[i] != p[j]) {
      j = pi[j-1];
    }
    if(t[i] == p[j]) {
      if(j == p.size() - 1) {
        answer.push_back(i - p.size() + 1);
        j = pi[j];
      } else {
        j++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  getline(cin, t);
  getline(cin, p);

  make_pi();
  kmp();

  cout << answer.size() << '\n';
  for(ll location: answer) {
    cout << location+1 << '\n';
  }

  return 0;
}