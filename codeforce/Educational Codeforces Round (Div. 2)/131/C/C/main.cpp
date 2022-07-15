#include <iostream>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

ll t, n, m, a;
ll worker[200200];

int compare(int a, int b) {
  return a > b;
}

void testcase() {
  ll max_hour = 0;
  ll lower_bound, upper_bound;
  cin >> n >> m;
  for(int i = 0; i <= n; i++) {
    worker[i] = 0;
  }
  for(int i = 0; i < m; i++) {
    cin >> a;
    worker[a]++;
  }
  for(int i = 1; i <= n; i++) {
    max_hour = max(max_hour, worker[i]);
  }
  lower_bound = 0;
  upper_bound = max_hour;
  sort(&worker[1], &worker[n+1], compare);
  while(lower_bound <= upper_bound) {
    ll mid = (lower_bound + upper_bound) / 2;
    ll left = 0;
    for(int i = 1; i <= n; i++) {
      if(worker[i] > mid) {
        left += (worker[i] - mid) * 2;
      } else if(worker[i] < mid) {
        left -= ((mid - worker[i]) / 2) * 2;
      }
    }
    if(left > 0) {
      lower_bound = mid + 1;
    } else {
      upper_bound = mid - 1;
    }
  }
  cout << lower_bound << '\n';
}


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> t;
  while(t--) {
    testcase();
  }
  
  return 0;
}
