#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string a, b;
string mok, namoji;
string temp = "";
string now;

int maxi(string a,string b) {		//오론쪽이 크다(1), 왼쪽이 크다(-1), 같댜(0)
    if (a.size() != b.size()) {
        return a.size() < b.size() ? 1 : -1;
    } else {
        for(ll i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                return a[i] < b[i] ? 1 : -1;
            }
        }
        return 0;
    }
}

string subst(string a, string b) {	//a-b를 수행
	int last = 0; int bidx = b.size() - 1;
	string ans = ""; char c;
	for (int i = a.size() - 1; i >= 0; i--) {
		int tempa = a[i] - '0'; int tempb = b[bidx] - '0'-last;
		if (tempa < tempb) {
			tempa += 10; last = -1;
		}
		c = tempa - tempb + '0';
		ans = c + ans;
		if (bidx == 0) {
			b = "0";
		}
		else bidx--;
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != '0') {
			ans = ans.substr(i); break;
		}
		if (i == ans.size() - 1)
			return "0";
	}
	return ans;
}

void divide(string a,string b) {	// a/b를 수행하는 함수
	
	for (int i = 0; i < a.size(); i++) {
		int moka = 0;
		now = temp + a[i];
		while (1) {
			int cirtic = maxi(b, now);
			if (cirtic == 1 || cirtic == 0) {
				now = subst(now, b); moka++;
			}
			else if (cirtic == -1) {
				temp = now; mok =  mok+to_string(moka); break;
			}
		}
	}
	for (int i = 0; i < mok.size(); i++) {
		if (mok[i] != '0') { mok = mok.substr(i); break; }
		if (i == mok.size() - 1)
			mok = "0";
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	divide(a, b);
	for (int i = 0; i < now.size(); i++) {
		if (now[i] != '0') {
			now = now.substr(i); break;
		}
		if (i == now.size() - 1)
			now = "0";
	}
	cout << mok << '\n' << now;
}