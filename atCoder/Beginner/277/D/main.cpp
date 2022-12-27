#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define INT_INF (__INT_MAX__ / 3)
typedef long long ll;
using namespace std;

ll N, M, A, sum, answer;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  sum = 0;
  for(ll i = 0; i < N; i++) {
    cin >> A;
    arr.push_back(A);
    sum += A;
  }

  sort(arr.begin(), arr.end());

  ll left = 0, right = 0;
  ll partial_sum = arr[0];
  ll answer = INF;
  while(right + 1 < arr.size()) {
    ll now = arr[right];
    ll next = arr[right+1];
    if(now == next || now + 1 == next) {
      right += 1;
      partial_sum += arr[right];
    } else {
      answer = min(sum - partial_sum, answer);
      left = right + 1;
      right = left;
      partial_sum = arr[right];
    }
  }

  answer = min(sum - partial_sum, answer);

  if(left != 0 && arr[right] == M - 1 && arr[0] == 0) {
    right = 0;
    partial_sum += arr[0];
    while(right + 1 < arr.size()) {
      ll now = arr[right];
      ll next = arr[right+1];
      if(now == next || now + 1 == next) {
        right += 1;
        partial_sum += arr[right];
      } else {
        answer = min(sum - partial_sum, answer);
        break;
      }
    }
  }
  answer = min(sum - partial_sum, answer);

  cout << answer << '\n';

  return 0;
}