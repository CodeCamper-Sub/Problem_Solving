#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> a, answers;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  set<ll> left, right;
  for(ll& a: a) {
    cin >> a;
    right.insert(a);
  }
  for(ll i = 0; i < n; i++) {
    right.erase(a[i]);
    ll left_max = 0;
    ll right_min = INF;
    if(left.size()) {
      left_max = *left.rbegin();
    }
    if(right.size()) {
      right_min = *right.begin();
    }

    if(left_max < a[i] && a[i] < right_min) answers.push_back(a[i]);
    left.insert(a[i]);
  }
  
  cout << answers.size() << ' ';
  for(ll i = 0; i < min(ll(answers.size()), ll(100)); i++) {
    cout << answers[i] << ' ';
  }
  
  return 0;
}