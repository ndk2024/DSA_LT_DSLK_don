#include <iostream>
#include <conio.h>
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
void AddHead(List &l, int n)
{
    Node *p=createNode(n);
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
void AddTail(List &l, int n)
{
    Node *p=createNode(n);
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
void NhapDS(List &l)
{
    char ch;
    do
    {
        ch=getch();
        cout << ch;
        if(ch=='\r') break;
        AddHead(l,ch-'0');
    }while(true);
    cout<<endl;
}
void XuatDS(const List &l)
{
    Node *p;
    p=l.Head;
    while(p!=NULL)
    {
        cout<<p->value;
        p=p->Next;
    }
    cout<<endl;
}
List Tong (List l1, List l2)
{
    List l3;
    createList(l3);
    Node *p,*q;
    p=l1.Head;
    q=l2.Head;
    int memo=0;
    while(p!=NULL||q!=NULL||memo>0)
    {
        int sum=memo;
        if(p!=NULL)
        {
            sum+=p->value;
            p=p->Next;
        }
        if(q!=NULL)
        {
            sum+=q->value;
            q=q->Next;
        }
        AddHead(l3,sum%10);
        memo=sum/10;
    }
    return l3;
}
List copy_nguoc(List l)
{
    List l_nguoc;
    createList(l_nguoc);
    Node*p=l.Head;
    while(p!=NULL)
    {
        AddHead(l_nguoc, p->value);
        p=p->Next;
    }
    return l_nguoc;
}
bool check_greater_or_equal(List l1,List l2)
{
    Node *p=l1.Head;
    Node *q=l2.Head;
    int dem_l1=1,dem_l2=1;
    while(p->Next!=NULL)
    {
        dem_l1++;
        p=p->Next;
    }
    while (q->Next!=NULL)
    {
        dem_l2++;
        q=q->Next;
    }
    if(dem_l1>dem_l2)
        return true;
    else if(dem_l1<dem_l2)
        return false;
    else
    {
        List l1_nguoc,l2_nguoc;
        createList(l1_nguoc);
        createList(l2_nguoc);
        l1_nguoc=copy_nguoc(l1);
        l2_nguoc=copy_nguoc(l2);
        p=l1_nguoc.Head;
        q=l2_nguoc.Head;
        while (p != NULL && q != NULL)
        {
        if (p->value > q->value) return true;
        if (p->value < q->value) return false;
        p = p->Next;
        q = q->Next;
        }
    }
}
void RemoveHead(List &l)
{
    Node*p=l.Head;
    l.Head=p->Next;
    delete p;
}
List Hieu(List l1, List l2)
{
    bool check=0;
    List l3;
    createList(l3);
    Node *p,*q;
    if(check_greater_or_equal(l1,l2)==true)
    {
        p=l1.Head;
        q=l2.Head;
        check=1;
    }
    else
    {
        p=l2.Head;
        q=l1.Head;
        check=0;
    }
    int borrow=0;
    while(p!=NULL||q!=NULL)
    {
        int val1=(p!=NULL)?p->value:0;
        int val2=(q!=NULL)?q->value:0;
        int diff=val1-val2-borrow;
        if(diff<0)
        {
            borrow=1;
            diff+=10;
        }
        else
            borrow=0;
        AddHead(l3,diff);
        if(p!=NULL) p=p->Next;
        if(q!=NULL)q=q->Next;

    }
    if(l3.Head->value==0)
    {
        RemoveHead(l3);
    }
    if(check==0)
    {
        l3.Head->value=l3.Head->value*(-1);
    }
    return l3;

}
int main()
{
    List l1,l2;
    createList(l1);
    createList(l2);
    NhapDS(l1);
    NhapDS(l2);

    List l3;
    cout<<"Tong hai so nguyen la: ";
    l3=Tong(l1,l2);
    XuatDS(l3);

    List l4;
    cout<<"Hieu hai so nguyen la: ";
    l4=Hieu(l1,l2);
    XuatDS(l4);
    return 0;
}
