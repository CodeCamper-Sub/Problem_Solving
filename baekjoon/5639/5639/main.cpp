//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll v;
vector<ll> preorder;

void print_postorder(ll left, ll right) {
  ll root = preorder[left];
  ll pivot = right + 1;
  for(ll i = left; i <= right; i++) {
    if(preorder[i] > root) {
      pivot = i;
      break;
    }
  }
  ll left_size = pivot - left - 1;
  ll right_size = right - pivot + 1;
  if(left_size == 1) {
    cout << preorder[left+1] << '\n';
  } else if(left_size > 0){
    print_postorder(left+1, pivot-1);
  }
  if(right_size == 1) {
    cout << preorder[pivot] << '\n';
  } else if(right_size > 0) {
    print_postorder(pivot, right);
  }
  cout << root << '\n';
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(!cin.eof()) {
    cin >> v;
    preorder.push_back(v);
  }
  preorder.pop_back();
  
  print_postorder(0, preorder.size()-1);
  
  return 0;
}
