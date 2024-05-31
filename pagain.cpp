#include <bits/stdc++.h>

using namespace std;

#define el '\n'
#define sp ' '
#define int unsigned long long
#define fu(i,a,b) for(int i=a;i<=b;++i)
 
#define CAZRALO_BO signed main(signed argc, char *argv[])

int power(int x, int y, int p) {
	int res=1;
	x%=p;
	while (y) {
		if (y&1) {
			res=(res*x)%p;
		}
		y>>=1;
		x=(x*x)%p;
	}
	return res;
}

bool rabinMiller(int n,int d) {
	int a=2+rand()%(n-4);
	int x=power(a,d,n);
	if (x==1 || x==n-1) return true;
	while (d!=n-1) {
		x=(x*x)%n;
		d<<=1;
		if (x==1) return false;
		if (x==n-1) return true;
	}
	return false;
}

bool isPrime(int n,int k) {
	if (n<2 || n==4) return false;
	if (n<=3) return true;
	int d=n-1;
	while (d%2==0) { d>>=1; }
	fu(i,1,k) {
		if (!rabinMiller(n,d)) return false;
	}
	return true;

}

CAZRALO_BO {
    cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	int testcase;
	cin>>testcase;
	while (testcase--) {
		int n;
		cin>>n;
		n--;
		while (1) {
			if (isPrime(n,2)) break;
			--n;
		}
		cout<<n<<el;
	}
    return 0;
}
