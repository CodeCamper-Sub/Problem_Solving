#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;


struct Product {
  ll price;
  set<ll> functions;
};

ll n, m;
vector<Product> products;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  products.resize(n);
  for(ll i = 0; i < n; i++) {
    ll c;
    cin >> products[i].price >> c;
    for(ll j = 0; j < c; j++) {
      ll f;
      cin >> f;
      products[i].functions.insert(f);
    }
  }

  sort(products.begin(), products.end(), [](Product& a, Product& b) {
    return a.price < b.price;
  });

  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      if(products[i].functions.size() < products[j].functions.size()) continue;
      auto iter1 = products[i].functions.begin();
      auto iter2 = products[j].functions.begin();
      bool is_better = true;
      while(iter1 != products[i].functions.end() && iter2 != products[j].functions.end()) {
        while(iter1 != products[i].functions.end() && *iter1 < *iter2) iter1++;
        if(iter1 == products[i].functions.end() || *iter1 != *iter2) {
          is_better = false;
          break;
        }
        iter1++; iter2++;
      }
      if(!is_better || (products[i].price == products[j].price && products[i].functions.size() == products[j].functions.size())) continue;
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";
  
  return 0;
}