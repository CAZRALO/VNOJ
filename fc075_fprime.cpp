#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <queue>
#include <deque>
#include <iomanip>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <climits>
#include <sstream>
#include <complex>
#include <chrono>
#include <random>

using namespace std;

#define tcT template <class T
#define tcTU tcT, class U

tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;

#define el '\n'
#define sp ' '

#define int long long

//pair
#define st first
#define nd second
#define mp(a,b) make_pair(a,b)

// vector , data structure
#define bg(x) begin(x)
#define eb(x) emplace_back(x);
#define pb(x) push_back(x);
#define pf(x) push_front(x);
#define ph(x) push(x);
#define PB pop_back();
#define PF pop_front();
#define all(a) bg(a),end(a)
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int) a.size()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define mty empty()
#define ms(a,val) memset(a,val,sizeof(a))

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b) { return (int)(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return (int)(ub(all(a), b) - bg(a)); }
// loops
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define FU(i,a,b,x) for (int i=a;i<=b;i+=x)
#define FD(i,a,b,x) for (int i=a;i>=b;i-=x)
#define trav(a, x) for (auto &a : x)
#define fos(it,s) for(set<int> :: iterator it=s.begin(); it!=s.end();++it)
 
#define CAZRALO_BO signed main(signed argc, char *argv[])


# pragma GCC target("avx")
# pragma GCC target("avx2")
# pragma GCC target("fma")
# pragma GCC optimize("Os")
# pragma GCC optimize("Ofast")
# pragma GCC optimization ("03")
# pragma GCC optimization ("unroll-loops")

//datatypes
//using ll  = long long;
using str = string;
using db  = double;
using ldb = long double;
using ull = unsigned long long;
// pair , vector
using pii  = pair<int,int>;
using pd   = pair<db,db>;
using mii  = map<int,int>;
using vpi  = vector<pii>;
using vpd  = vector<pd>;
using vi   = vector<int>;
using vd   = vector<db>;
using vs   = vector<str>;
using vvi  = vector<vi>;
using vvd  = vector<vd>;

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); cout.tie(0); }
void setIO(str s) {
	unsyncIO();
}

bool isPrime[10000005];

void Sieve_of_Eratosthenes(int k) {
    ms(isPrime,true);
    isPrime[0]=false; isPrime[1]=false;
    fu(i,2,k)
        if (isPrime[i]) {
            FU(j,i*2,k,i)
                isPrime[j]=false;
        }
}

CAZRALO_BO {
    setIO(FNAME);
	Sieve_of_Eratosthenes(10000000);
	int k;
	cin>>k;
	while (k--) {
		int x;
		cin>>x;
		if (isPrime[x]) {
			cout<<"YES"<<el;
		} else cout<<"NO"<<el;
	}
    return 0;
}
