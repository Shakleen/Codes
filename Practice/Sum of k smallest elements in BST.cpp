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
int k,sum;

struct node{// Tree structure
    int key;
    struct node *left, *right;
};

struct node* newNode(int keyValue){// Creating new node at leaf
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    // Assign values and set left and right pointer to null
    temp->key = keyValue;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int keyValue){// Inserting values
    // Leaf node reached
    if(root == NULL)    return newNode(keyValue);
    // keyValue is less than current node key value, go left
    else if (keyValue < root->key)  root->left = insert(root->left, keyValue);
    // keyValue is greater than current node key value, go right
    else if (keyValue > root->key)  root->right =insert(root->right, keyValue);

    return root;
}


void inorder(struct node *root){// A utility function to do in order traversal of BST
    if (root != NULL){
        inorder(root->left);
        if(k)   sum += root->key,   k--;
//        printf("key = %d sum = %d k=%d\n", root->key, sum,k);
        if(k)   inorder(root->right);
    }
}
void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0, n=0, a=0;
    struct node* root = NULL;

    cin >> t;

    FOR(tc,1,t){
        root = NULL;
        sum = k = a = n = 0;

        cin >> n;

        FOR(i,1,n){
            cin >> a;
            root = insert(root, a);
        }

        cin >> k;

        inorder(root);

        cout << sum << '\n';
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


