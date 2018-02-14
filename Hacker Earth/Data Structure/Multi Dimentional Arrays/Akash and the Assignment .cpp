#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-6
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define FORL(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            printf("Case %d:", z);
#define sz(a)               a.size()
#define all(x)              x.begin(),x.end()
#define SORT(a,n)           sort(a,a+n)
#define RSORT(a,n)          sort(a,a+n,greater<ll>())
#define VSORT(v)            sort(all(v))
#define VRSORT(v)           sort(all(v),greater<ll>())
#define pii                 pair <int, int>
#define pll                 pair <ll, ll>
#define pb                  push_back
#define pf                  push_front
#define pob                 pop_back()
#define pof                 pop_front()
#define ff                  first
#define ss                  second
#define mp                  make_pair
#define ms(x,n)             memset((x),n,sizeof(x))
#define fin                 freopen("in.txt", "r", stdin)
#define fout                freopen("out.txt", "w", stdout)
#define IT(it,x)            for(it=x.begin(); it != x.end(); it++)
#define sf1(x)              scanf("%d", &x)
#define sfl1(x)             scanf("%lld", &x)

//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int a[26][50001];

int main(){
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int n=0, q=0, l=0, r=0, k=0, temp=0;
    char ch;
    string str, ans;

    cin>>n>>q;
    cin>>str;

    REP(i,26){
        a[i][0] = 0;

        REP(j,str.size()){
            if(str[j]==('a'+i))     a[i][j+1]++;
            a[i][j+1] += a[i][j];
        }
    }

//    REP(i,26){
//        cout<<'a'+i<<' '<<a[i][str.size()]<<endl;
//    }

    for(int j=0; j<q; j++){
        ans.clear();

        cin>>l>>r>>k;

        if(k>(r-l+1)){
            ans = "Out of range";
        }
        else{
            REP(i,26){
                temp = a[i][r]-a[i][l-1];
//printf("left = %d right = %d TEMP = %d k = %d\n", a[i][l-1], a[i][r], temp, k);
                if(temp>=k && temp){
                    ch = 'a'+i;
                    ans += ch;
                    break;
                }
                else{
                    k -= temp;
                }
            }

        }

        cout<<ans<<'\n';
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


