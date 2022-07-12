//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

void testcase();

ll tt, n, answer;
char s;
queue<pair<char, int>> q;

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
  answer = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> s;
    if(q.empty()) {
      q.push({s, 1});
    } else if(q.back().first == s) {
      q.back().second++;
    } else {
      q.push({s, 1});
    }
  }
  while(!q.empty()) {
    answer += q.front().second * (q.size());
    q.pop();
  }
  cout << answer << '\n';
}
