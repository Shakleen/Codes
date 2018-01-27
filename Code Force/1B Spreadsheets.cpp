#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************MACROS******************************************
//*******************************************************************************

#define N                   100000000
#define M                   5761455
#define ll                  long long
#define ull                 unsigned long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define pii                 pair <int, int>
#define FOR(a,b,c,d)        for(ll a = b; a <= c; a+=d)
#define rFOR(a,b,c,d)       for(ll a = b; a >= c; a-=d)
#define all(v)              v.begin(),v.end()
#define SORT(v)             sort(all(v))
#define REV(v)              reverse(v.begin(),v.end())
#define setm(ar,m)          memset(ar,m,sizeof ar)
#define FF                  first
#define SS                  second
#define PB                  push_back
#define MP                  make_pair
#define nline               '\n'
#define TEST(t)             for(int cs = 1; cs <= t; cs++)

//*******************************************************************************
//*****************************FUNCTIONS*****************************************
//*******************************************************************************

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//bool num[N];
//int prime[M];
//
//int binarysearch(int lo, int hi, int x, int *arr){
//    int result = -1;
//
//    while (lo <= hi){
//        int mid = lo + (hi-lo)/2;
//
//        if (arr[mid] == x){
//            result = mid;
//        }
//        else if (arr[mid] < x){
//            lo = mid+1;
//        }
//        else{
//            hi = mid-1;
//        }
//    }
//
//    return result;
//}
//
//void sieve(){
//    for (int i = 4; i <= N; i += 2){
//        num [i] = 1;
//    }
//
//    for (int i = 3; i*i <= N; i += 2){
//        if ( !num[i] ){
//            for (int k = i*i; k <= N; k += 2*i){
//                num[k] = 1;
//            }
//        }
//    }
//
//    prime[0] = 2;
//    int j = 1;
//
//    for (int i = 3; i <= N; i += 2){
//        if (!num[i]){
//            prime[j++] = i;
//        }
//    }
//    return;
//}
//
//int factors (int n){
//    if (n < N){
//        if ( !num[n] ){
//            return 2;
//        }
//    }
//
//    int cnt = 1, s = 0, val = sqrt(n)+1;
//
//    for (int i = 0; prime[i] < val; i++){
//        if ( !(n%prime[i]) ){
//            s = 1;
//
//            while ( !(n%prime[i]) ){
//                n /= prime[i];
//                s++;
//            }
//
//            cnt *= s;
//        }
//    }
//
//    if ( n > 1 ){
//        cnt *= 2;
//    }
//
//    return cnt;
//}
//
//ll factor_sum (ll n){
//    ll sum = 1, p = 0, val = sqrt(n)+1, s = 0;
//
//    for (int i = 0; prime[i] < val; i++){
//        if ( !(n%prime[i]) ){
//            p = prime[i];
//
//            while ( !(n%prime[i]) ){
//                p *= prime[i];
//                n /= prime[i];
//            }
//
//            s = (p-1)/(prime[i]-1);
//            sum *= s;
//        }
//    }
//
//    if (n > 1){
//        sum *= (n*n-1)/(n-1);
//    }
//
//    return sum;
//}
//
//ll bigmod (ll base, ll pow, ll mod){
//    if (pow == 0){
//        return 1;
//    }
//    else if (pow%2){
//        return ((base%mod)*bigmod(base,pow-1,mod))%mod;
//    }
//    else{
//        ll y = bigmod(base,pow/2,mod);
//
//        return (y*y)%mod;
//    }
//}

string numToString(ll num){
    string no;

    while (num>0){
        no += ((num%10)+'0');
        num /=10;
    }

    reverse(no.begin(), no.end());

    return no;
}

ll stringToNum(string str){
    ll num = 0, len = str.size()-1;

    FOR(i,0,len,1){
        num += (str[i]-'0');

        if (i != len){
            num *= 10;
        }
    }

    return num;
}

void input(int n, int *arr){
    FOR(i,1,n,1){
        cin >> arr[i];
    }
}

int main(){
//    sieve();
//    FAST();

    int n = 0;

    cin >> n;

    TEST(n){
        string str, rowNo, colNo, ans;
        int posR = 0, posC = 0, length = 0, numC = 0, div = 0, num = 0;
        bool type = false;

        cin >> str;

        length = str.size() - 1;
        posR = str.find("R");
        posC = str.find("C");

        FOR(i,posR,posC,1){
            if (str[i]<'0' || str[i]>'9'){
                type = true;
                break;
            }
        }

        if (type && posR<str.size() && posC<str.size()){
            rowNo.append(str,posR+1,posC-posR-1);
//            cout << rowNo << nline;
            colNo.append(str,posC+1,length-posC);
//            cout << colNo << nline;

            numC = stringToNum(colNo);
//            cout << numC << nline;

            while (numC){
//cout << "EN NumC = " << numC << " R = " << r << " Ans = " << ans << nline;
                div = numC/26;
                numC /= r;

                ans += ('A'+r-1);
                if (numC<=26){
                    ans += ('A'+r-1);
                }
//cout << "EX NumC = " << numC << " R = " << r << " Ans = " << ans << nline << nline;
            }

            REV(ans);
            ans += rowNo;
        }
        else{
            ans += 'R';

            FOR(i,0,length,1){
                if (str[i]>='A' && str[i]<='Z'){
                    num += (str[i]-'A'+1);
                    num *= 26;
                }
                else{
                    ans += str[i];
                }
            }
//            cout << ans << nline;
            num /= 26;
            ans += 'C';
            ans += numToString(num);
        }
cout << "GIVEN = " << str << " Output = " << ans << nline;
//        cout << ans << nline;
    }

    return 0;
}
