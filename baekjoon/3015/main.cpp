#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, arr[500500], answer;
stack<pair<ll, ll>> s; // {height, count}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
    if(s.empty()) {
      s.push({arr[i], 1});
    } else {
      if(s.top().first > arr[i]) {
        s.push({arr[i], 1});
        answer++;
      } else if (s.top().first == arr[i]) {
        if(s.size() == 1) {
          answer += s.top().second;
        } else {
          answer += s.top().second + 1;
        }
        s.top().second++;
      } else {
        while(!s.empty() && s.top().first < arr[i]) {
          answer += s.top().second;
          s.pop();
        }
        if(s.empty()) {
          s.push({arr[i], 1});
          continue;
        } else if (s.top().first == arr[i]) {
          if(s.size() == 1) {
            answer += s.top().second;
          } else {
            answer += s.top().second + 1;
          }
          s.top().second++;
        } else {
          s.push({arr[i], 1});
          answer++;
        }
      }
    }
  }
  cout << answer;

  return 0;
}