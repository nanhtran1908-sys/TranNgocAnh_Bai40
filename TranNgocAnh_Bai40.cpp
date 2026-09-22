#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    int maSV;
    string tenSV;
    string lop;
    float diemTK;
    string hanhKiem;
};

typedef SinhVien Data;

struct Node
{
    Data data;
    Node *left;
    Node *right;
};

typedef Node* NodePtr;

struct BinaryTree
{
    NodePtr root;
};

void initialize(BinaryTree &T)
{
    T.root = NULL;
}


// 2. Tao moi mot nut
NodePtr createNode(Data data)
{
    NodePtr newNode = new Node;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Data NhapData()
{
    Data data;

    cout << "Nhap ma sinh vien: ";
    cin >> data.maSV;
    cin.ignore();

    cout << "Nhap ten sinh vien: ";
    getline(cin, data.tenSV);

    cout << "Nhap lop: ";
    getline(cin, data.lop);

    cout << "Nhap diem tong ket: ";
    cin >> data.diemTK;
    cin.ignore();

    cout << "Nhap hanh kiem: ";
    getline(cin, data.hanhKiem);

    return data;
}

void PrintNode(NodePtr T)
{
    cout << "Ma sinh vien: " << T->data.maSV << endl;
    cout << "Ten sinh vien: " << T->data.tenSV << endl;
    cout << "Lop: " << T->data.lop << endl;
    cout << "Diem tong ket: " << T->data.diemTK << endl;
    cout << "Hanh kiem: " << T->data.hanhKiem << endl;
    cout << "-----------------------------" << endl;
}

void insertToTree(BinaryTree &T, Data data)
{
    if (T.root == NULL)
    {
        T.root = createNode(data);
    }
    else if (data.maSV < T.root->data.maSV)
    {
        if (T.root->left == NULL)
        {
            T.root->left = createNode(data);
        }
        else
        {
            BinaryTree leftTree;
            leftTree.root = T.root->left;

            insertToTree(leftTree, data);

            T.root->left = leftTree.root;
        }
    }
    else if (data.maSV > T.root->data.maSV)
    {
        if (T.root->right == NULL)
        {
            T.root->right = createNode(data);
        }
        else
        {
            BinaryTree rightTree;
            rightTree.root = T.root->right;

            insertToTree(rightTree, data);

            T.root->right = rightTree.root;
        }
    }
    else
    {
        cout << "Ma sinh vien da ton tai!" << endl;
    }
}

NodePtr search(int maSV, BinaryTree T)
{
    NodePtr p = T.root;

    if (p != NULL)
    {
        if (maSV < p->data.maSV)
        {
            BinaryTree leftTree;
            leftTree.root = p->left;

            return search(maSV, leftTree);
        }
        else if (maSV > p->data.maSV)
        {
            BinaryTree rightTree;
            rightTree.root = p->right;

            return search(maSV, rightTree);
        }
        else
        {
            return p;
        }
    }

    return NULL;
}

void inOrder(BinaryTree T)
{
    if (T.root != NULL)
    {
        BinaryTree leftTree;
        leftTree.root = T.root->left;

        inOrder(leftTree);

        PrintNode(T.root);

        BinaryTree rightTree;
        rightTree.root = T.root->right;

        inOrder(rightTree);
    }
}

int main()
{
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    BinaryTree T;
    initialize(T);

    for (int i = 0; i < n; i++)
    {
        cout << "\n===== Nhap thong tin sinh vien "
             << i + 1 << " =====" << endl;

        Data data = NhapData();

        insertToTree(T, data);
    }

    cout << "\nDanh sach sinh vien trong cay la: " << endl;

    inOrder(T);

    int maSV;

    cout << "\nNhap ma sinh vien can tim: ";
    cin >> maSV;

    NodePtr found = search(maSV, T);

    if (found != NULL)
    {
        cout << "\nThong tin sinh vien: " << endl;
        PrintNode(found);
    }
    else
    {
        cout << "Khong co sinh vien trong cay!" << endl;
    }

    return 0;
}
