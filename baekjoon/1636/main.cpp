#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n;
vector<ll> answers;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  answers.assign(n, 0);
  ll start, end, left, right;
  for(ll i = 0; i < n; i++) {
    cin >> left >> right;
    if(i == 0) {
      start = left;
      end = right;
      if(start == end) {
        answers[i] = start;
      }
    } else {
      if(start <= right && left <= end) {
        if(start == end) {
          answers[i] = start;
        }
        start = max(start, left);
        end = min(end, right);
      } else if(right < start) {
        if(answers[0] == 0) {
          for(ll j = 0; j < i; j++) {
            answers[j] = start;
          }
        }
        start = right;
        end = right;
        answers[i] = right;
      } else if(end < left) {
        if(answers[0] == 0) {
          for(ll j = 0; j < i; j++) {
            answers[j] = end;
          }
        }
        start = left;
        end = left;
        answers[i] = left;
      }
    }
  }
  if(answers[0] == 0) {
    for(ll i = 0; i < n; i++) {
      answers[i] = start;
    }
  }

  ll sum = 0;
  for(ll i = 0; i < n - 1; i++) {
    sum += abs(answers[i] - answers[i + 1]);
  }

  cout << sum << '\n';
  for(ll i = 0; i < n; i++) {
    cout << answers[i] << '\n';
  }

  return 0;
}