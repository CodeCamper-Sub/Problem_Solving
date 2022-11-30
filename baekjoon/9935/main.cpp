#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string str, c4;
stack<char> start, dest;
queue<char> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> str >> c4;
  for(ll i = str.size() - 1; i >= 0; i--) {
    start.push(str[i]);
  }
  while(!start.empty()) {
    char now = start.top(); start.pop();
    if(now == c4[q.size()]) {
      q.push(now);
      if(q.size() == c4.size()) {
        while(!q.empty()) { q.pop(); }
        for(ll i = 0; i < c4.size(); i++) {
          if(dest.size() > 0) {
            start.push(dest.top());
            dest.pop();
          }
        }
      }
    } else {
      while(!q.empty()) {
        dest.push(q.front());
        q.pop(); 
      }
      if(now == c4[q.size()]) {
        q.push(now);
      } else {
        dest.push(now);
      }
    }
  }
  while(!q.empty()) {
    start.push(q.front());
    q.pop();
  }
  while(!dest.empty()) {
    start.push(dest.top());
    dest.pop();
  }

  if(start.size() > 0) {
    while(!start.empty()) {
      cout << start.top();
      start.pop();
    }
  } else {
    cout << "FRULA";
  }

  return 0;
}