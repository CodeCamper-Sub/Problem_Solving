#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Node {
  string name;
  vector<Node*> childs;
  
  bool operator<(Node another) {
    return name < another.name;
  }

  bool operator<=(Node another) {
    return name <= another.name;
  }
};

ll N, K;
vector<Node*> root;
vector<string> path;

bool compare(Node* a, Node* b) {
  return (*a).name < (*b).name;
}

void print(Node* node, ll depth) {
  for(ll i = 0; i < depth; i++) {
    cout << "--";
  }
  cout << (*node).name << '\n';
  for(ll i = 0; i < (*node).childs.size(); i++) {
    print((*node).childs[i], depth+1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> K;
    path = vector<string>(K);
    Node* now;
    for(ll j = 0; j < K; j++) {
      cin >> path[j];
      Node* next = new Node;
      (*next).name = path[j];
      if(j == 0) {
        auto iter = lower_bound(root.begin(), root.end(), next, compare);
        if(iter == root.end() || (*(*iter)).name != (*next).name) {
          root.push_back(next);
          sort(root.begin(), root.end(), compare);
          now = next;
        } else {
          now = *iter;
        }
      } else {
        auto iter = lower_bound((*now).childs.begin(), (*now).childs.end(), next, compare);
        if(iter == (*now).childs.end() || (*(*iter)).name != (*next).name) {
          (*now).childs.push_back(next);
          sort((*now).childs.begin(), (*now).childs.end(), compare);
          now = next;
        } else {
          now = *iter;
        }
      }
    }
  }
  for(ll i = 0; i < root.size(); i++) {
    print(root[i], 0);
  }

  return 0;
}