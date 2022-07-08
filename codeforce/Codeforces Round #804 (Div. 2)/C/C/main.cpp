//
//  main.cpp
//  C
//
//  Created by CodeCamper on 2022/07/07.
//

#include <iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int t, n;
int a[100100];
int left_bound, right_bound;
int spaces;
bool visited[100100];
ll dp[100100];

enum direction {
  LEFT,
  RIGHT
};

ll permutation(int n, int r) {
  ll result = 1;
  for(int i = n; i > n - r; i--) {
    result *= i;
    result %= MOD;
  }
  return result;
}

pair<int, int> find_next(int num) {
  int next_index = 0;
  direction direction = LEFT;
  for(int i = 1; i <= n; i++) {
    if(left_bound-i > 0 && a[left_bound-i] == num) {
      next_index = left_bound - i;
      direction = LEFT;
      break;
    } else if (right_bound+i <= n && a[right_bound+i] == num) {
      next_index = right_bound + i;
      direction = RIGHT;
      break;
    }
  }
  if(direction == LEFT) {
    for(int i = next_index; i <= left_bound; i++) {
      visited[a[i]] = true;
    }
    return {next_index, right_bound};
  } else {
    for(int i = right_bound; i <= next_index; i++) {
      visited[a[i]] = true;
    }
    return {left_bound, next_index};
  }
}

int numbers_of_should_be_placed(int start) {
  for(int i = start + 1; i <= n; i++) {
    if(visited[i] == false) {
      return i - start - 1;
    }
  }
  return n - start;
}

void testcase() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(a[i] == 0) {
      left_bound = i;
      right_bound = i;
    }
    visited[i] = false;
    dp[i] = 0;
  }
  spaces = 0;
  dp[0] = 1;
  visited[0] = true;
  
  for(int i = 1; i <= n; i++) {
    if(visited[i] == false) {
      pair<int, int> new_bound = find_next(i);
      if(i == 1) {
        spaces += new_bound.second - new_bound.first - 1;
      } else {
        spaces += (new_bound.second - new_bound.first - 1) - (right_bound - left_bound - 1) - 1;
      }
      int placed_numbers = numbers_of_should_be_placed(i);
      dp[i] = (dp[i-1] * permutation(spaces, placed_numbers)) % MOD;
      spaces -= placed_numbers;
      left_bound = new_bound.first;
      right_bound = new_bound.second;
    } else {
      dp[i] = dp[i-1];
    }
  }
  cout << dp[n] << '\n';
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
