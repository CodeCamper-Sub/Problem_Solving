#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

string s;
vector<ll> st;
ll answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '(') st.push_back(i);
    else {
      if(st.back() == i - 1) {
        st.pop_back();
        answer += st.size();
      } else {
        st.pop_back();
        answer += 1;
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}