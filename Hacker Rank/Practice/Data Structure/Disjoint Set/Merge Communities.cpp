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

struct Node
{
    int value, rank, size;
    Node *parent;
};

class DisjointSet
{
public:
    void MakeSet(int value);
    void Union(int value1, int value2);
    int FindSize(int value);
private:
    map <int, Node*> Storage;
    map <int, Node*>::iterator itr1, itr2;
    Node *Node1, *Node2;
    Node* FindParent(Node* node);
};

void DisjointSet::MakeSet(int value)
{
    Node *NewNode = new Node;
    NewNode->parent = NewNode;
    NewNode->rank = 0;
    NewNode->size = 1;
    NewNode->value = value;
    Storage[value] = NewNode;
    return;
}

Node* DisjointSet::FindParent(Node *node)
{
   Node *Parent = node->parent;

   if (Parent->value == node->value)
        return Parent;
   else
        Parent = node->parent = FindParent(Parent);

   return Parent;
}

void DisjointSet::Union(int value1, int value2)
{
    itr1 = Storage.find(value1);
    Node1 = FindParent(itr1->second);

    itr2 = Storage.find(value2);
    Node2 = FindParent(itr2->second);

    if (Node1->value == Node2->value)
        return;
    else if (Node1->rank > Node2->rank)
    {
        Node2->parent = Node1->parent;
        Node1->size += Node2->size;
    }
    else if (Node2->rank > Node1->rank)
    {
        Node1->parent = Node2->parent;
        Node2->size += Node1->size;
    }
    else
    {
        Node2->parent = Node1->parent;
        Node1->rank++;
        Node1->size += Node2->size;
    }

    return;
}

int DisjointSet::FindSize(int value)
{
    itr1 = Storage.find(value);

    if (itr1 != Storage.end())
    {
        return (FindParent(itr1->second))->size;
    }

    return -1;
}

int main()
{
    //FAST();
    int n=0, q=0, x=0, y=0;
    char ch;
    DisjointSet Dobj;

    cin >> n >> q;

    FOR(i, 1, n)
    {
        Dobj.MakeSet(i);
        // cout << Dobj.FindParent(i) << '\n';
    }

    FOR(i, 1, q)
    {
        cin >> ch;

        if (ch == 'Q')
        {
            cin >> x;

            cout << Dobj.FindSize(x) << "\n";
        }
        else
        {
            cin >> x >> y;

            Dobj.Union(x, y);
        }
    }

    return 0;
}
