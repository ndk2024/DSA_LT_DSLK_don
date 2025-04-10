#include <iostream>

using namespace std;

struct Node
{
    int row,col;
    int value;
    Node *Next;
};
Node* createNode(int x, int i, int j)// i la so hang, j la so cot
{
    Node*p=new Node;
    p->value=x;
    p->row=i;
    p->col=j;
    p->Next=NULL;
    return p;
}
struct Matrix
{
    int rows,cols;//Tong so hang va so cot
    Node *Head;
    Node *Tail;
};
void createMatrix(Matrix &M)
{
    M.Head=NULL;
    M.Tail=NULL;
}
void AddTail(Matrix &M, Node *p)
{
    if(M.Head==NULL)
    {
        M.Head=p;
        M.Tail=M.Head;
    }
    else
    {
        M.Tail->Next=p;
        M.Tail=p;
    }
}
void NhapMatrix(Matrix &M)
{
    cout<<"Nhap so hang: ";
    cin>>M.rows;
    cout<<"Nhap so cot: ";
    cin>>M.cols;
    for(int i=0; i<M.rows; i++)
    {
        for(int j=0; j<M.cols; j++)
        {
            int x;
            cin>>x;
            Node *p=createNode(x,i,j);
            AddTail(M,p);
        }
    }
}
void XuatMatrix(Matrix M)
{
    Node *p=M.Head;
    for(int i=0; i<M.rows; i++)
    {
        for(int j=0; j<M.cols; j++)
        {
            cout<<p->value<<" ";
            p=p->Next;
        }
        cout<<endl;
    }
}
Matrix Sum(Matrix A, Matrix B)
{
    Matrix C;
    createMatrix(C);
    if(A.rows!=B.rows||A.cols!=B.cols)
    {
        cout<<"Khong cong duoc!"<<endl;
        return C;
    }
    // khi hang va cot cua A va B bang nhau
    C.cols=A.cols;
    C.rows=A.rows;
    Node*a=A.Head;
    Node*b=B.Head;
    for(int i=0; i<C.rows; i++)
    {
        for(int j=0; j<C.cols; j++)
        {
            int val=a->value+b->value;
            a=a->Next;
            b=b->Next;
            Node*p=createNode(val,i,j);
            AddTail(C,p);
        }
    }
    return C;
}

Matrix TinhTich(Matrix A, Matrix B)
{
    Matrix C;
    createMatrix(C);
    C.rows=A.rows;
    C.cols=B.cols;
    if (A.cols != B.rows)
    {
        cout << "Khong the nhan hai ma tran: so cot A != so hang B" << endl;
        return C;
    }
    for(int i=0; i<C.rows; i++)
    {
        for(int j=0; j<C.cols; j++)
        {
            int val=0;
            for(int k=0; k<A.cols; k++)
            {
                Node* pa=A.Head;
                while(pa!=NULL &&!(pa->row==i && pa->col==k))
                    pa=pa->Next;

                Node *pb=B.Head;
                while(pb!=NULL &&!(pb->row==k && pb->col==j))
                    pb=pb->Next;
                int val_a=(pa!=NULL)?pa->value:0;
                int val_b=(pb!=NULL)?pb->value:0;
                val+=val_a*val_b;
            }
            Node*p=createNode(val,i,j);
            AddTail(C,p);
        }
    }
    return C;
}
int main()
{
    Matrix A, B;
    createMatrix(A);
    createMatrix(B);
    NhapMatrix(A);
    NhapMatrix(B);
    XuatMatrix(A);
    XuatMatrix(B);

    Matrix Tong, Tich;
    createMatrix(Tong);
    createMatrix(Tich);
    cout<<"Tong cua hai ma tran A, B: "<<endl;
    Tong=Sum(A,B);
    if(Tong.Head!=NULL)
        XuatMatrix(Tong);

    cout<<"Tich cua hai ma tran A,B: "<<endl;
    Tich=TinhTich(A,B);
    if(Tich.Head!=NULL)
        XuatMatrix(Tich);
    return 0;
}
