
#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<string> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  v.resize(3);
  for(ll i = 0; i < 3; i++) {
    cin >> v[i];
  }

  for(ll i = 0; i < 3; i++) {
    if(v[i][0] != 'F' && v[i][0] != 'B') {
      ll s = stoi(v[i]);
      ll to = 3 - i + s;
      if(to % 3 == 0 && to % 5 == 0) {
        cout << "FizzBuzz";
      } else if(to % 3 == 0) {
        cout << "Fizz";
      } else if(to % 5 == 0) {
        cout << "Buzz";
      } else {
        cout << to;
      }
      return 0;
    }
  }
  
  return 0;
}