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

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
//    FAST();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t, cnt, j, n, k, len;
    bool flag;
    vector<int>v[26];
    int str[100001];
    string s;

    cin>>t;

    while(t--){
        flag = false;
        cnt=j=k=0;

        cin>>s;
        n=s.size(),len=n/2;

        for(int i=0; i<=len; i++){
            if(s[i]!=s[n-i-1]){
                flag=true;
                break;
            }
        }

        if(flag){
            FOR(i,0,25) v[i].clear();
            REP(i,n)    v[s[i]-'a'].pb(i+1);

//            REP(i,26){
//                printf("%d -> ", i);
//                REP(j,v[i].size())
//                printf("%d ", v[i][j]);
//                printf("\n");
//            }

            REP(i,26)   if(v[i].size()%2)   cnt++, j=i;

            if(cnt>1)
                cout<<-1;
            else{
                ms(str,0);

                if(cnt){
                    str[len] = v[j][v[j].size()-1];
                    v[j].pop_back();
                    len--;
                }

                for(j=k=0; k<=len; ){
                    if(!v[j].size() && j<26)
                        j++;
                    else if (j>=26)
                        break;
                    else{
                        str[k]=v[j][v[j].size()-1];
                        v[j].pop_back();
                        str[n-k-1]=v[j][v[j].size()-1];
                        v[j].pop_back();
                        if(str[k]>str[n-k-1])   swap(str[k],str[n-k-1]);
                        k++;
                    }
                }
                REP(i,n)        cout<<str[i]<<' ';
            }
        }
        else
            REP(i,n)        cout<<i+1<<' ';

        cout<<'\n';
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


