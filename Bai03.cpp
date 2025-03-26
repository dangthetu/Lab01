#include <iostream>
#include <cmath>

using namespace std;

// Cấu trúc dữ liệu biểu diễn phân số
struct phanSo{
    double tuSo, mauSo;
};

// Hàm xuất phân số
void xuatPhanSo(phanSo);

// Hàm đếm số chữ số sau dấu thập phân của một số thực
int dem10(double a)
{
    int count = 0;
    while (fabs(a - round(a)) > 1e-12)
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

// Hàm làm tròn hai số thực về số nguyên nếu có phần thập phân
int lamTron(double &a, double &b)
{
    if(check(a) == 0 || check(b) == 0)
    {
        int da = dem10(a), db = dem10(b);
        if(da > db){
            a *= pow(10, da);
            b *= pow(10, da);
        }
        else{
            a *= pow(10, db);
            b *= pow(10, db);
        }
    }
}

// Hàm chuẩn hóa dấu của phân số (đưa mẫu số về dương)
int chuyenDau(double &a, double &b){
    if((b < 0 && a > 0) || (b < 0 && a < 0)){
        a *= -1;
        b *= -1;
    }
}

// Hàm tìm ước chung lớn nhất (UCLN) của hai số nguyên
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Hàm rút gọn phân số
void rutGon(phanSo &p) {
    int ucln = gcd(p.tuSo, p.mauSo);
    p.tuSo /= ucln;
    p.mauSo /= ucln;
}

// Toán tử cộng hai phân số
phanSo operator +(phanSo a, phanSo b){
    phanSo x;
    x.mauSo = a.mauSo * b.mauSo;
    x.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
    return x;
}

// Toán tử trừ hai phân số
phanSo operator -(phanSo a, phanSo b){
    phanSo x;
    x.mauSo = a.mauSo * b.mauSo;
    x.tuSo = a.tuSo * b.mauSo - b.tuSo * a.mauSo;
    return x;
}

// Toán tử nhân hai phân số
phanSo operator *(phanSo a, phanSo b){
    phanSo x;
    x.mauSo = a.mauSo * b.mauSo;
    x.tuSo = a.tuSo * b.tuSo;
    return x;
}

// Toán tử chia hai phân số
phanSo operator /(phanSo a, phanSo b){
    phanSo x;
    x.mauSo = a.mauSo * b.tuSo;
    x.tuSo = a.tuSo * b.mauSo;
    return x;
}

// Hàm tính toán và xuất kết quả của các phép toán trên phân số
void tinhToan(phanSo a, phanSo b){
    phanSo r1, r2, r3, r4;
    r1 = a + b;
    r2 = a - b;
    r3 = a * b;
    r4 = a / b;

    rutGon(r1);
    rutGon(r2);
    rutGon(r3);
    rutGon(r4);

    chuyenDau(r1.tuSo, r1.mauSo);
    chuyenDau(r2.tuSo, r2.mauSo);
    chuyenDau(r3.tuSo, r3.mauSo);
    chuyenDau(r4.tuSo, r4.mauSo);

    cout << "Tong 2 phan so: ";
    xuatPhanSo(r1);
    cout << "Hieu 2 phan so: ";
    xuatPhanSo(r2);
    cout << "Tich 2 phan so: ";
    xuatPhanSo(r3);
    cout << "Thuong 2 phan so: ";
    xuatPhanSo(r4);
}

// Hàm xuất phân số ra màn hình
void xuatPhanSo(phanSo p){
    if (p.mauSo == 0) cout << "Khong xac dinh." << endl;
    else if(p.mauSo == p.tuSo) cout << "1" << endl;
    else if(p.mauSo == 1) cout << p.tuSo << endl;
    else cout << p.tuSo << "/" << p.mauSo << endl;
}

// Hàm nhập phân số từ bàn phím
void nhapPhanSo(phanSo &p1){
    int i = 0;
    while(i < 1)
    {
        cout << "Nhap tu so: ";
        cin >> p1.tuSo;
        cout << "Nhap mau so: ";
        cin >> p1.mauSo;
        if(p1.mauSo == 0) cout << "Nhap sai, moi nhap lai." << endl;
        else i++;
    }
}

int main(){
    phanSo p1, p2;
    cout << "Nhap phan so thu 1." << endl;
    nhapPhanSo(p1);
    cout << "Nhap phan so thu 2." << endl;
    nhapPhanSo(p2);

    lamTron(p1.tuSo, p1.mauSo);
    lamTron(p2.tuSo, p2.mauSo);

    tinhToan(p1, p2);

    return 0;
}
