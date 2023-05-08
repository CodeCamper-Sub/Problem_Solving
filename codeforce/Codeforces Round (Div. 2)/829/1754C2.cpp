#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, sum;
vector<ll> a;
vector<pair<ll, ll>> even_one, even_minus, odd_one, odd_minus, leading_zero, zero, all;

void init() {
  cin >> n;
  a.resize(n);
  sum = 0;
  for(ll& a: a) {
    cin >> a;
    sum += a;
  }
  even_one.clear();
  even_minus.clear();
  odd_one.clear();
  odd_minus.clear();
  leading_zero.clear();
  zero.clear();
  all.clear();
}

void solve() {
  if(sum % 2) {
    cout << -1 << '\n';
    return;
  }
  ll previous = 0;
  bool is_leading_zero = false;
  ll cnt = 1;
  for(ll i = 1; i <= n; i++) {
    if(i == n || a[i] != a[i - 1]) {
      if(a[i - 1] == 1) {
        if(cnt % 2) {
          if(is_leading_zero) {
            leading_zero.push_back({previous, i - 1});
          } else {
            odd_one.push_back({previous, i - 1});
          }
        } else {
          if(is_leading_zero) {
            zero.push_back({previous, previous});
            previous++;
          }
          even_one.push_back({previous, i - 1});
        }
        is_leading_zero = false;
        previous = i;
      } else if(a[i - 1] == -1) {
        if(cnt % 2) {
          if(is_leading_zero) {
            leading_zero.push_back({previous, i - 1});
          } else {
            odd_minus.push_back({previous, i - 1});
          }
        } else {
          if(is_leading_zero) {
            zero.push_back({previous, previous});
            previous++;
          }
          even_minus.push_back({previous, i - 1});
        }
        is_leading_zero = false;
        previous = i;
      } else {
        if(i == n) {
          zero.push_back({previous, i - 1});
        } else if(cnt > 1) {
          zero.push_back({previous, i - 2});
        }
        is_leading_zero = true;
        previous = i - 1;
      }
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if(odd_one.size() == odd_minus.size()) {
    
  } else if(odd_one.size() < odd_minus.size()) {
    // even_one을 쪼개서 odd_one.size를 늘리기
    while(even_one.size() && odd_one.size() < odd_minus.size() - 1) {
      auto [start, end] = even_one.back();
      even_one.pop_back();
      odd_one.push_back({end - 1, end - 1});
      odd_one.push_back({end, end});
      if(start + 1 < end) {
        even_one.push_back({start, end - 2});
      }
    }
    // leading_zero를 odd_one으로 만들기
    while(leading_zero.size() && odd_one.size() < odd_minus.size()) {
      auto [start, end] = leading_zero.back();
      leading_zero.pop_back();
      if(a[end] == 1) {
        odd_one.push_back({start + 1, end});
        zero.push_back({start, start});
      } else {
        odd_one.push_back({start, end});
      }
    }
  } else if(odd_one.size() > odd_minus.size()) {
    // even_minus를 쪼개서 odd_minus를 늘리기
    while(even_minus.size() && odd_one.size() - 1 > odd_minus.size()) {
      auto [start, end] = even_minus.back();
      even_minus.pop_back();
      odd_minus.push_back({end - 1, end - 1});
      odd_minus.push_back({end, end});
      if(start + 1 < end) {
        even_minus.push_back({start, end - 2});
      }
    }
    // leading_zero를 odd_minus로 만들기
    while(leading_zero.size() && odd_one.size() > odd_minus.size()) {
      auto [start, end] = leading_zero.back();
      leading_zero.pop_back();
      if(a[end] == 1) {
        odd_minus.push_back({start, end});
      } else {
        odd_minus.push_back({start + 1, end});
        zero.push_back({start, start});
      }
    }
  }

  // 남은 leading_zero 처리
  bool to_one = true;
  while(leading_zero.size()) {
    auto [start, end] = leading_zero.back();
    leading_zero.pop_back();
    if(to_one) {
      if(a[end] == 1) {
        odd_one.push_back({start + 1, end});
        zero.push_back({start, start});
      } else {
        odd_one.push_back({start, end});
      }
    } else {
      if(a[end] == 1) {
        odd_minus.push_back({start, end});
      } else {
        odd_minus.push_back({start + 1, end});
        zero.push_back({start, start});
      }
    }
    to_one = !to_one;
  }

  for(ll i = 0; i < even_one.size(); i++) {
    all.push_back(even_one[i]);
  }
  for(ll i = 0; i < even_minus.size(); i++) {
    all.push_back(even_minus[i]);
  }
  for(ll i = 0; i < odd_one.size(); i++) {
    all.push_back(odd_one[i]);
  }
  for(ll i = 0; i < odd_minus.size(); i++) { 
    all.push_back(odd_minus[i]);
  }
  for(ll i = 0; i < leading_zero.size(); i++) {
    all.push_back(leading_zero[i]);
  }
  for(ll i = 0; i < zero.size(); i++) {
    all.push_back(zero[i]);
  }
  sort(all.begin(), all.end());

  if(odd_one.size() == odd_minus.size()) {
    cout << all.size() << '\n';
    for(auto [start, end]: all) {
      cout << start + 1 << ' ' << end + 1 << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
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