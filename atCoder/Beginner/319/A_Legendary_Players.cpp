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
  if(s == "tourist") cout << 3858;
  else if(s == "ksun48") cout << 3679;
  else if(s == "Benq") cout << 3658;
  else if(s == "Um_nik") cout << 3648;
  else if(s == "apiad") cout << 3638;
  else if(s == "Stonefeang") cout << 3630;
  else if(s == "ecnerwala") cout << 3613;
  else if(s == "mnbvmar") cout << 3555;
  else if(s == "newbiedmy") cout << 3516;
  else cout << 3481;
  
  return 0;
}