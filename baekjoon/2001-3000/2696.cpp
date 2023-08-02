#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<ll> answers;
priority_queue<ll> max_heap;
priority_queue<ll, vector<ll>, greater<ll>> min_heap;

void init() {
  cin >> n;
  answers.clear();
  while(max_heap.size()) max_heap.pop();
  while(min_heap.size()) min_heap.pop();
}

void solve() {
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    min_heap.push(x);
    if(min_heap.size() >= max_heap.size() + 2) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
    if(max_heap.size() && min_heap.top() < max_heap.top()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    if(i % 2 == 0) {
      answers.push_back(min_heap.top());
    }
  }
  cout << answers.size() << '\n';
  for(ll answer: answers) {
    cout << answer << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}