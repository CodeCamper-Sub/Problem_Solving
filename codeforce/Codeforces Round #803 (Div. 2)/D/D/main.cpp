//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

void testcase();
bool contains(set<int>, int);
bool inbound(int, int, int);

ll tt, n, a, left_bound, right_bound, mid, left_count;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    testcase();
  }
  return 0;
}

void testcase() {
  cin >> n;
  left_bound = 1;
  right_bound = n;
  while(left_bound <= right_bound) {
    mid = (left_bound + right_bound) / 2;
    left_count = 0;
    cout << "? " << left_bound << ' ' << mid << '\n';
    cout.flush();
    for(int i = 1; i <= mid - left_bound + 1; i++) {
      cin >> a;
      if(inbound(left_bound, mid, a)) {
        left_count++;
      }
    }
    if(left_count % 2 == 0) {
      left_bound = mid + 1;
    } else {
      right_bound = mid - 1;
    }
  }
  cout << "! " << left_bound << '\n';
  cout.flush();
}

bool inbound(int left_bound, int right_bound, int num) {
  if(left_bound <= num && num <= right_bound) {
    return true;
  }
  return false;
}
