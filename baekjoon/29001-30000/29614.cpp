#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  reverse(s.begin(), s.end());
  ll cnt = 0;
  double sum = 0;
  while(s.size()) {
    string now = "";
    now += s.back(); s.pop_back();
    if(s.size() && s.back() == '+') {
      now += s.back();
      s.pop_back();
    }
    if(now == "A+") {
      sum += 4.5;
    } else if(now == "A") {
      sum += 4.0;
    } else if(now == "B+") {
      sum += 3.5;
    } else if(now == "B") {
      sum += 3.0;
    } else if(now == "C+") {
      sum += 2.5;
    } else if(now == "C") {
      sum += 2.0;
    } else if(now == "D+") {
      sum += 1.5;
    } else if(now == "D") {
      sum += 1.0;
    }
    cnt++;
  }

  cout << fixed;
  cout.precision(5);
  cout << sum / double(cnt) << '\n';
  
  return 0;
}