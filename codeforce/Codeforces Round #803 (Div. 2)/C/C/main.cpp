//
//  main.cpp
//  C
//
//  Created by CodeCamper on 2022/07/08.
//

#include <iostream>
#include <vector>
using namespace std;

int t, n, a;

bool contains(vector<int> v, int num) {
  for(int i = 0; i < v.size(); i++) {
    if(v[i] == num) {
      return true;
    }
  }
  return false;
}

bool brute_force(vector<int> v) {
  for(int i = 0; i < v.size() - 2; i++) {
    for(int j = i + 1; j < v.size() - 1; j++) {
      for(int k = j + 1; k < v.size(); k++) {
        if(!contains(v, v[i] + v[j] + v[k])) {
          return false;
        }
      }
    }
  }
  return true;
}

bool testcase() {
  vector<int> v;
  int zero_count = 0;
  int negative_count = 0;
  int positive_count = 0;
  
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> a;
    
    if(a > 0) {
      v.push_back(a);
      positive_count++;
    } else if(a < 0) {
      v.push_back(a);
      negative_count++;
    } else if(zero_count++ < 2) {
      v.push_back(0);
    }
  }
  
  if(positive_count > 2 || negative_count > 2) {
    return false;
  }
  
  return brute_force(v);
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--) {
    if(testcase()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
