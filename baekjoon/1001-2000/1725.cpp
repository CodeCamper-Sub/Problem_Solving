#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, arr[100100], answer;
stack<tuple<ll, ll>> s; // {index, height}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
    if(s.empty()) {
      s.push({i, arr[i]});
    } else {
      if(get<1>(s.top()) < arr[i]) {
        s.push({i, arr[i]});
      } else if(get<1>(s.top()) > arr[i]) {
        ll last_i = get<0>(s.top());
        while(!s.empty() && get<1>(s.top()) > arr[i]) {
          ll partial_answer = (i - get<0>(s.top())) * (get<1>(s.top()));
          answer = max(answer, partial_answer);
          last_i = get<0>(s.top());
          s.pop();
        }
        if(s.empty() || get<1>(s.top()) < arr[i]) {
          s.push({last_i, arr[i]});
        }
      }
    }
  }

  while(!s.empty()) {
    ll partial_answer = (n - get<0>(s.top())) * (get<1>(s.top()));
    answer = max(answer, partial_answer);
    s.pop(); 
  }
  cout << answer;

  return 0;
}