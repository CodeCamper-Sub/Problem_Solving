#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);
  ll A, B;
  cin >> A >> B;
  ll right = 1000000000000000000;
  ll left = 0;
  while(left < right) {
    ll mid = (left + right) / 2;
    if(sqrt(mid) * mid >= double(A) / double(2 * B)) {
      right = mid-1;
    } else {
      left = mid+1;
    }
  }
  
  ll k = left;
  double answer = double(B) * k + double(A) / sqrt(1 + k);
  k--;
  answer = min(answer, double(B) * k + double(A) / sqrt(1 + k));
  cout << answer << '\n';

  return 0;
}