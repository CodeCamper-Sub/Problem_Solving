#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
queue<ll> a, b;
vector<ll> answer_a, answer_b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 0; i < n; i++) {
    ll aa;
    cin >> aa;
    a.push(aa);
  }
  for(ll i = 0; i < m; i++) {
    ll bb;
    cin >> bb;
    b.push(bb);
  }

  ll cnt = 1;
  while(a.size() && b.size()) {
    if(a.front() < b.front()) {
      answer_a.push_back(cnt++);
      a.pop();
    } else {
      answer_b.push_back(cnt++);
      b.pop();
    }
  }

  while(a.size()) {
    answer_a.push_back(cnt++);
    a.pop();
  }

  while(b.size()) {
    answer_b.push_back(cnt++);
    b.pop();
  }

  for(ll answer: answer_a) {
    cout << answer << ' ';
  }
  cout << '\n';
  for(ll answer: answer_b) {
    cout << answer << ' ';
  }
  
  return 0;
}