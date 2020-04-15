/*
 * https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2014/contest3_solutions
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 500
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll n ;
string A , B ;
int a[50009] , b[50009] ;
ll NUM[50009][2][2][2][2];
ll dp [50009][2][2][2][2];
inline int yes ( int pos , int x , int up , int dn ) {
	if ( up && dn ) return 1 ;
	if ( up ) return ( x <= b[pos] ) ;
	if ( dn ) return ( x >= a[pos] ) ;
	return ( a[pos] <= x && x <= b[pos] ) ;
}
ll num ( int pos , int up1 , int dn1 , int up2 ,int dn2 ) {
	if ( pos == n ) return 1ll ;
	ll &ret = NUM[pos][up1][dn1][up2][dn2] ;
	if ( ret != -1 ) return ret ;
	ret = 0 ;
	for ( int i = 0 ; i <= 9 ; i ++ ) {
		for ( int j = 0 ; j <= 9 ; j ++ ) {
			if ( ! yes ( pos , i , up1 , dn1 ) || ! yes ( pos , j , up2 , dn2 ) ) C ;
			ret += num ( pos+1 , max ( up1 , (int)(i > a[pos] ) ), max ( dn1 , (int)(i < b[pos] ) ), 
					     max ( up2 , (int)(j > a[pos] ) ), max ( dn2 , (int)(j < b[pos] ) ) 
				   ) ;
			ret %= mod ;
		}
	}
	return ret ; 
}
ll bt ( int pos , int up1 , int dn1 , int up2 ,int dn2 ) {
	if ( pos == n ) return 0ll ;
	ll &ret = dp[pos][up1][dn1][up2][dn2] ;
	if ( ret != -1 ) return ret ;
	ret = 0 ;
	for ( int i = 0 ; i <= 9 ; i ++ ) {
		for ( int j = 0 ; j <= 9 ; j ++ ) {
			if ( ! yes ( pos , i , up1 , dn1 ) || ! yes ( pos , j , up2 , dn2 ) ) C ;
			ll cost = num ( pos+1 , max ( up1 , (int)(i > a[pos] ) ) , max ( dn1 , (int)(i < b[pos] ) ) ,
                                                 max ( up2 , (int)(j > a[pos] ) ) , max ( dn2 , (int)(j < b[pos] ) ) )
						 * abs ( i - j ) ;
			ret += 	   bt  ( pos+1 , max ( up1 , (int)(i > a[pos] ) ) , max ( dn1 , (int)(i < b[pos] ) ) ,
                                                 max ( up2 , (int)(j > a[pos] ) ) , max ( dn2 , (int)(j < b[pos] ) ) )
						 + cost ;
			ret %= mod ;
		}
	}
	return ret ; 
}
int main () {
	mem ( NUM , -1 ) ;
	mem ( dp  , -1 ) ;
	cin >> A >> B ;
	n = B.size() ;
	while ( A.size() < B.size() ) A = '0' + A ;
	for ( int i = 0 ; i < n ; i ++ ) {
		a[i] = A[i]-'0';
		b[i] = B[i]-'0';
	}
	cout << bt ( 0 , 0 , 0 , 0 , 0 ) << endl ; 
}
