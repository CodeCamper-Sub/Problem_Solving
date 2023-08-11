#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<string> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  for(string& s: v) cin >> s;
  sort(v.begin(), v.end(), [](string a, string b) {
    if(a == b) return false;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size() && b.size()) {
      if(isalpha(a.back()) && isalpha(b.back())) {
        if(a.back() != b.back()) {
          ll delta_a = a.back() - (islower(a.back()) ? 'a' : 'A');
          ll delta_b = b.back() - (islower(b.back()) ? 'a' : 'A');
          return delta_a != delta_b ? delta_a < delta_b : bool(isupper(a.back()));
        } else {
          a.pop_back(); b.pop_back();
          continue;
        }
      } else if (isalpha(a.back()) || isalpha(b.back())) {
        return isdigit(a.back()) != 0;
      } else {
        ll number_of_leading_zero_a = 0, number_of_leading_zero_b = 0;
        while(a.size() && isdigit(a.back()) && a.back() == '0') {
          number_of_leading_zero_a++;
          a.pop_back();
        }
        while(b.size() && isdigit(b.back()) && b.back() == '0') {
          number_of_leading_zero_b++;
          b.pop_back();
        }
        vector<ll> num_a, num_b;
        while(a.size() && isdigit(a.back())) {
          num_a.push_back(a.back() - '0');
          a.pop_back();
        }
        while(b.size() && isdigit(b.back())) {
          num_b.push_back(b.back() - '0');
          b.pop_back();
        }
        if(num_a.size() != num_b.size()) 
          return num_a.size() < num_b.size();
        for(ll i = 0; i < num_a.size(); i++) {
          if(num_a[i] != num_b[i]) 
            return num_a[i] < num_b[i];
        }
        if(number_of_leading_zero_a != number_of_leading_zero_b) 
          return number_of_leading_zero_a < number_of_leading_zero_b;
        else 
          continue;
      }
    }
    return a.size() == 0;
  });

  for(string s: v) {
    cout << s << '\n';
  }
  
  return 0;
}