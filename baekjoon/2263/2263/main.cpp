//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
vector<ll> inorder, postorder;

void print_preorder(ll inorder_left, ll inorder_right, ll postorder_left, ll postorder_right) {
  ll root = postorder[postorder_right];
  ll root_index = 0;
  for(ll i = inorder_left; i <= inorder_right; i++) {
    if(inorder[i] == root) {
      root_index = i;
    }
  }
  ll left_size = root_index - inorder_left;
  ll right_size = inorder_right - root_index;
  cout << root << ' ';
  if(left_size > 0) {
    print_preorder(inorder_left, root_index-1, postorder_left, postorder_left + left_size - 1);
  }
  if(right_size > 0) {
    print_preorder(root_index + 1, inorder_right, postorder_left + left_size, postorder_right - 1);
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  inorder = vector<ll>(n);
  postorder = vector<ll>(n);
  for(ll i = 0; i < n; i++) {
    cin >> inorder[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> postorder[i];
  }
  print_preorder(0, n-1, 0, n-1);
  
  return 0;
}
