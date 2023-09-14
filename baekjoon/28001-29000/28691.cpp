#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

char c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> c;
  if(c == 'M') cout << "MatKor";
  else if(c == 'W') cout << "WiCys";
  else if(c == 'C') cout << "CyKor";
  else if(c == 'A') cout << "AlKor";
  else cout << "$clear";
  
  return 0;
}