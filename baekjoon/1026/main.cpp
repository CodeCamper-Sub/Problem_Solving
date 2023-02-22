#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N;
vector<ll> A, B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  A = vector<ll>(N);
  B = vector<ll>(N);
  for(ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(ll i = 0; i < N; i++) {
    cin >> B[i];
  }

  sort(A.begin(), A.end(), [](auto a, auto b) { return a > b; });
  sort(B.begin(), B.end());

  ll answer = 0;
  for(ll i = 0; i < N; i++) {
    answer += A[i] * B[i];
  }

  cout << answer << '\n';

  return 0;
}