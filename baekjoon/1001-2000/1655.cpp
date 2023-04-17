#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;
priority_queue<ll> max_q;
priority_queue<ll, vector<ll>, greater<ll>> min_q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  while(n--) {
    cin >> k;
    if(min_q.size() && min_q.top() < k) {
      min_q.push(k);
    } else {
      max_q.push(k);
    }
    while(max_q.size() > min_q.size() + 1) {
      min_q.push(max_q.top());
      max_q.pop();
    }
    while(min_q.size() > max_q.size()) {
      max_q.push(min_q.top());
      min_q.pop();
    }
    cout << max_q.top() << '\n';
  }
  
  return 0;
}