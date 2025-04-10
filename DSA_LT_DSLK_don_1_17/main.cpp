#include <iostream>

using namespace std;

struct Node
{
    int value;
    struct Node *Next;
};

struct List
{
    Node *Head;
    Node *Tail;
};

Node* createNode(int x)
{
    Node *p;
    p=new Node;
    p->value=x;
    p->Next=NULL;
    return p;
}
void createList(List &l)
{
    l.Head=NULL;
    l.Tail=NULL;
}
void AddHead(List &l, Node *p)
{
    if(l.Head==NULL)
    {
        l.Head=p;
        l.Tail=l.Head;
    }
    else
    {
        p->Next=l.Head;
        l.Head=p;
    }
}
void AddTail(List &l, Node *p)
{
    if(l.Head==NULL)
    {
        l.Head=p;
        l.Tail=l.Head;
    }
    else
    {
        l.Tail->Next=p;
        l.Tail=p;
    }
}
void NhapDS(List &l) //Câu 1
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0) return;
        Node *p=createNode(n);
        AddTail(l,p);
    }
}

void XuatDS(const List &l)// Câu 2
{
    Node *p;
    p=l.Head;
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        p=p->Next;
    }
    cout<<endl;
}

void DeleteList(List &l)//Câu 12
{
    Node *p;
    p=l.Head;
    while(p!=NULL)
    {
        Node *temp=p;
        p=p->Next;
        delete temp;
    }
    l.Head=NULL;
    l.Tail=NULL;
}

void Dem_pt(const List &l)//Câu 3
{
    Node *p;
    p=l.Head;
    int dem=0;
    while(p!=NULL)
    {
        dem++;
        p=p->Next;
    }
    cout<<dem<<endl;
}
void value_of_index(const List &l)//Câu 4
{
    int n;
    cout<<"Nhap chi so n muon kiem tra gia tri: ";
    cin>>n;
    Node *p;
    p=l.Head;
    int dem=0;
    while(p!=NULL)
    {
        if(dem==n)
        {
            cout<<"Gia tri cua phan tu thu "<<n<<" la ";
            cout<<p->value<<endl;
            return;
        }
        dem++;
        p=p->Next;
    }
}

void check_ton_tai(const List &l)//Câu 5
{
    int x;
    cout<<"Nhap so nguyen x muon kiem tra ton tai: ";
    cin>>x;
    Node *p=l.Head;
    while(p!=NULL)
    {
        if(x==p->value)
        {
            cout<<"1"<<endl;
            return;
        }
        p=p->Next;
    }
    cout<<"0"<<endl;
}

void AddAfter(List &l, Node *p, Node *q)//Thêm q vào sau p
{
    if(p->Next==NULL)
    {
        AddTail(l,q);
    }
    else
    {
        q->Next=p->Next;
        p->Next=q;
    }

}
void InsertAfter( List &l, int k, int x)//Câu 6
{
    Node *p=l.Head;
    while(p!=NULL)
    {
        if(p->value==k)
        {
            Node *px= createNode(x);
            AddAfter(l,p,px);
        }
        p=p->Next;
    }
}

void Insert_inIndex(List &l)//Câu 7
{
    int n,x;
    cout<<"Nhap vi tri muon them gia tri x: ";
    cin>>n;
    cout<<"Nhap gia tri x: ";
    cin>>x;
    Node*p=l.Head;
    Node *prev=NULL;
    int index=0;
    while(p!=NULL)
    {
        if(index==n)
        {
            Node *px=createNode(x);
            if(prev==NULL)
            {
                AddHead(l,px);
            }
            else
            {
                AddAfter(l,prev,px);
            }
            return;
        }
        prev=p;
        p=p->Next;
        index+=1;
    }
}

void Copy_nguoc(const List &l, List &l_nguoc)// Câu 8
{
    Node *p=l.Head;
    while(p!=NULL)
    {
        Node *newNode= createNode(p->value);
        AddHead(l_nguoc,newNode);
        p=p->Next;
    }
}

void RemoveHead(List &l)//Câu 10
{
    Node *p=l.Head;
    l.Head=p->Next;
    delete p;
}
void RemoveAfter(List &l, Node *p)//Xoá node sau p
{
    if (p == NULL || p->Next == NULL) return;
    Node *hold=p->Next;
    p->Next=hold->Next;
    delete hold;
}
void RemoveTail(List &l)//Câu 11
{
    if(l.Head==NULL) return;
    if(l.Head->Next==NULL)
    {
        RemoveHead(l);
        return;
    }
    Node *p=l.Head;
    Node *prev=NULL;
    while(p->Next!=NULL)
    {
        prev=p;
        p=p->Next;
    }
    RemoveAfter(l,prev);
}

void RemoveXvalue(List &l)
{
    int x;
    cout<<"Nhap gia tri x muon xoa: ";
    cin>>x;
    Node *p=l.Head;
    Node *prev=NULL;
    while(p!=NULL && p->value!=x)
    {
        prev=p;
        p=p->Next;
    }
    if(p==NULL)
    {
        cout<<"0"<<endl;
        return;
    }
    cout<<"1"<<endl;
    if(prev==NULL)
    {
        RemoveHead(l);
    }
    else
        RemoveAfter(l,prev);
}

void Add_a(List &l, int a)
{
    Node *p=l.Head;
    Node *pa=createNode(a);
    Node *prev=NULL;
    while(p!=NULL && p->value<=a)
    {
        prev=p;
        p=p->Next;
    }
    if(p==NULL)
        AddAfter(l,prev,pa);
    else
    {
        if(prev==NULL)
            AddHead(l,pa);
        else
            AddAfter(l,prev,pa);
    }
}
void NoiDS(List &A, List &B)//Câu 14
{
    if(B.Head==NULL) return;
    if(A.Head==NULL)
    {
        A.Head=B.Head;
        A.Tail=B.Tail;
        return;
    }
    Node *p=A.Tail;
    p->Next=B.Head;
    A.Tail=B.Tail;
}

void TachList_dis(List l, List &B, List &C)//Câu 15
{
    Node *p = l.Head;
    int dem=0;
    while(p!=NULL)
    {
        dem++;
        p=p->Next;
    }
    p=l.Head;
    int mid=(dem+1)/2;
    for(int i=0; i<mid; i++)
    {
        Node *newNode=createNode(p->value);
        AddTail(B,newNode);
        p=p->Next;
    }
    for(int i=mid; i<dem; i++)
    {
        Node *newNode=createNode(p->value);
        AddTail(C,newNode);
        p=p->Next;
    }
}
void TachList_chanle(List l, List &B, List &C)// Câu 16
{
    Node *p = l.Head;
    while(p!=NULL)
    {
        Node *moi=createNode(p->value);
        if(p->value%2==0)
            AddTail(B,moi);
        else
            AddTail(C,moi);
        p=p->Next;
    }
}

void Ghep_tang(List &A, List &B)// Câu 17
{
    Node *q=B.Head;
    while( q!=NULL)
    {
        Add_a(A,q->value);
        q=q->Next;
    }
}
int main()
{
    List l;
    createList(l);
    //Câu 1
    NhapDS(l);
    //Câu 2
    XuatDS(l);
    //Câu 3
    Dem_pt(l);
    //Câu 4
    value_of_index(l);
    //Câu 5
    check_ton_tai(l);
    //Câu 6
    int x,k;
    cout<<"Nhap gia tri k va x: ";
    cin>>k>>x;
    InsertAfter(l,k,x);
    XuatDS(l);
    //Câu 7
    Insert_inIndex(l);
    XuatDS(l);
    //Câu 8
    List l_nguoc;
    createList(l_nguoc);
    Copy_nguoc(l,l_nguoc);
    XuatDS(l_nguoc);
    DeleteList(l_nguoc);
    //Câu 9
    RemoveXvalue(l);
    XuatDS(l);
    //Câu 10
    RemoveHead(l);
    XuatDS(l);
    //Câu 11
    RemoveTail(l);
    XuatDS(l);
    //Câu 12
    DeleteList(l);

    //Câu 13
    List l_tang;
    createList(l_tang);
    cout<<"Nhap danh sach sap xep tang dan: ";
    NhapDS(l_tang);
    int a;
    cout<<"Nhap a: ";
    cin>>a;
    Add_a(l_tang, a);
    XuatDS(l_tang);
    DeleteList(l_tang);

    //Câu 14
    cout<<"Cau 14: "<<endl;
    List A,B;
    createList(A);
    createList(B);
    NhapDS(A);
    NhapDS(B);
    NoiDS(A,B);
    XuatDS(A);
    DeleteList(B);
    DeleteList(A);

    //Câu 15
    cout<<"Cau 15"<<endl;
    List A15,C15,B15;
    createList(C15);
    createList(A15);
    createList(B15);
    NhapDS(A15);
    TachList_dis(A15,B15,C15);
    XuatDS(B15);
    XuatDS(C15);
    DeleteList(A15);
    DeleteList(B15);
    DeleteList(C15);

    //Câu 16
    cout<<"Cau 16"<<endl;
    List A16,B16,C16;
    createList(C16);
    createList(A16);
    createList(B16);
    NhapDS(A16);
    TachList_chanle(A16,B16,C16);
    XuatDS(B16);
    XuatDS(C16);
    DeleteList (A16);
    DeleteList(B16);
    DeleteList(C16);

    //Câu 17
    List A17,B17;
    createList(A17);
    createList(B17);
    cout<<"Nhap hai danh sach da duoc sap xep tang: "<<endl;
    NhapDS(A17);
    NhapDS(B17);
    Ghep_tang(A17,B17);
    XuatDS(A17);
    DeleteList(B17);
    return 0;
}
