#include <iostream>
#include <math.h>

using namespace std;

// Hàm tìm ước chung lớn nhất (UCLN) của hai số nguyên
int ucln(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
    {
        return a;
    }
    return ucln(a % b, b);
}

// Hàm đếm số chữ số sau dấu thập phân của một số thực
int dem10(double a)
{
    int count = 0;
    while (fabs(a - round(a)) > 1e-12) // Kiểm tra nếu số chưa phải số nguyên
    {
        a *= 10;
        count++;
    }
    return count;
}

// Hàm kiểm tra một số có phải số nguyên không
bool check(double n)
{
    return ceil(n) == floor(n);
}

// Hàm làm tròn hai số thực về số nguyên để tìm UCLN
int lamtron(double &a, double &b)
{
    if (!check(a) || !check(b)) // Nếu một trong hai số không phải số nguyên
    {
        int da = dem10(a), db = dem10(b); // Đếm số chữ số thập phân của từng số
        if (da > db)
        {
            a *= pow(10, da);
            b *= pow(10, da);
        }
        else
        {
            a *= pow(10, db);
            b *= pow(10, db);
        }
    }
    return ucln(a, b);
}

// Cấu trúc dữ liệu biểu diễn phân số
struct phanso
{
    double tuso, mauso;
};

int main()
{
    phanso p1;
    int u = 0;
    int i = 0;
    while (i < 1)
    {
        cout << "Nhap tu so: ";
        cin >> p1.tuso;
        cout << "Nhap mau so: ";
        cin >> p1.mauso;

        if (p1.tuso == p1.mauso)
        {
            cout << "Phan so la: 1";
            i++;
        }
        else if (p1.tuso == 0)
        {
            cout << "Phan so la: 0";
            i++;
        }
        else if (p1.mauso != 0)
        {
            if (p1.tuso < 0 || p1.mauso < 0) // Xử lý trường hợp có dấu âm
            {
                p1.tuso = fabs(p1.tuso);
                p1.mauso = fabs(p1.mauso);
                u = lamtron(p1.tuso, p1.mauso);
                p1.tuso = p1.tuso / u;
                p1.mauso = p1.mauso / u;
                i++;
                cout << "Phan so rut gon la: -";
                cout << p1.tuso << "/" << p1.mauso;
            }
            else
            {
                u = lamtron(p1.tuso, p1.mauso);
                p1.tuso = p1.tuso / u;
                p1.mauso = p1.mauso / u;
                i++;
                cout << "Phan so rut gon la: ";
                cout << p1.tuso << "/" << p1.mauso;
            }
        }
        else
        {
            cout << "Nhap sai, moi nhap lai." << endl;
        }
    }
    return 0;
}

