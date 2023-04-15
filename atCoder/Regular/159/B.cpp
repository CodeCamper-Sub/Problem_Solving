#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll A, B;
ll prime[1001000];
vector<ll> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	ll cnt = 0;

	for (ll i = 2; i <= 1000010; i++) {
		if (prime[i] == 0) {
			for (ll j = i + i; j <= 1000010; j += i) {
				prime[j] = 1;
			}
		}
	}
	if (A < B) swap(A, B);
	for (ll i = 2; i <= 1000010; i++) {
		if (prime[i] == 0) {
			v.push_back(i);

		}
	}
	while (A > 0 && B > 0) {
		ll tmp = min(A,B);
		ll tmpn = 0;
		if (A == B) {
			cnt++;
			break;
		}
		
		for (ll i = 0; i < v.size(); i++) {
			if (v[i] >= B) break;
			ll aa = (A / v[i])*v[i];
			ll bb = (B / v[i])*v[i];
			if (A - aa == B - bb) {
				if (tmp > B - bb) {
					tmp = B - bb;
					tmpn = v[i];
				}
			}
			
		}
		ll ccc = abs(A - B);
		ll aaa = (A / ccc)*ccc;
		ll bbb = (B / ccc)*ccc;
		//cout << "(" << A - aa << " " << B - bb << ")";
		if (A - aaa == B - bbb) {
			if (tmp > B - bbb) {
				tmp = B - bbb;
				tmpn = ccc;
			}
		}
		//cout << " <" << tmp<< " " << tmpn << " " << A << " " << B << ">"; 
		cnt += tmp;
		A -= tmp;
		B -= tmp;
		ll c = gcd(A, B);
		if (A <= 0 || B <= 0) break;
		A = A / c;
		B = B / c;
		A--;
		B--;
		cnt++;
	}
	cout << cnt;
	return 0;
}