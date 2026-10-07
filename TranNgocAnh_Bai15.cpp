#include <iostream>
#include <string>
using namespace std;

struct KhachHang
{
    int makh;
    string tenkh;
    string sdt;
    float tongtien;
};

void nhap(KhachHang *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin khach hang thu " << i + 1 << endl;

        cout << " - Ma khach hang: ";
        cin >> a[i].makh;

        cout << " - Ten khach hang: ";
        fflush(stdin);
        getline(cin, a[i].tenkh);

        cout << " - So dien thoai: ";
        fflush(stdin);
        getline(cin, a[i].sdt);

        cout << " - Tong tien thanh toan: ";
        cin >> a[i].tongtien;
    }
}

void hienThi(KhachHang *a, int n)
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Ma KH\tTen KH\t\tSo dien thoai\tTong tien" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i].makh << "\t"
             << a[i].tenkh << "\t\t"
             << a[i].sdt << "\t"
             << a[i].tongtien << endl;
    }

    cout << "------------------------------------------------------------" << endl;
}

void Insertionsort(KhachHang *a, int n)
{
    int pos;
    KhachHang x;

    for (int i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;

        while ((pos >= 0) && (a[pos].tongtien > x.tongtien))
        {
            a[pos + 1] = a[pos];
            pos--;
        }

        a[pos + 1] = x;
    }
}

int BinarySearch(float X, KhachHang *a, int n)
{
    int m, bottom, top;

    bottom = 0;
    top = n - 1;

    while (bottom <= top)
    {
        m = (bottom + top + 1) / 2;

        if (X == a[m].tongtien)
            return m;
        else if (X < a[m].tongtien)
            top = m - 1;
        else
            bottom = m + 1;
    }

    return -1;
}

void SearchAll(float X, KhachHang *a, int n)
{
    int found = BinarySearch(X, a, n);

    if (found == -1)
    {
        cout << "Khong tim thay khach hang co tong tien "
             << X << endl;
    }
    else
    {
        cout << "Cac khach hang co tong tien "
             << X << " la: " << endl;

        int i = found;

        while (i < n && a[i].tongtien == X)
        {
            cout << " - Ma khach hang: " << a[i].makh
                 << " | Ten: " << a[i].tenkh
                 << " | SDT: " << a[i].sdt
                 << " | Tong tien: " << a[i].tongtien << endl;

            i++;
        }

        i = found - 1;

        while (i >= 0 && a[i].tongtien == X)
        {
            cout << " - Ma khach hang: " << a[i].makh
                 << " | Ten: " << a[i].tenkh
                 << " | SDT: " << a[i].sdt
                 << " | Tong tien: " << a[i].tongtien << endl;

            i--;
        }
    }
}

int main()
{
    int n;
    KhachHang *a;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    a = new KhachHang[n];

    nhap(a, n);

    cout << "\nDanh sach khach hang vua nhap la:" << endl;
    hienThi(a, n);

    cout << "\nDanh sach khach hang sau khi sap xep:" << endl;
    Insertionsort(a, n);
    hienThi(a, n);

    float X;

    cout << "\nVui long nhap tong tien de tim kiem: ";
    cin >> X;

    SearchAll(X, a, n);

    delete[] a;

    return 0;
}
