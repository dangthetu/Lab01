#include <iostream>
#include <cmath>
using namespace std;

// Cấu trúc dữ liệu biểu diễn phân số
struct phanSo{
    double tuSo, mauSo;
};

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

// Hàm đổi dấu để mẫu số luôn dương
int doiDau(double &a, double &b){
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

// Hàm so sánh hai phân số
int soSanh(phanSo x, phanSo y){
    int a1, a2;
    doiDau(x.tuSo, x.mauSo);
    doiDau(y.tuSo, y.mauSo);
    a1 = x.tuSo * y.mauSo;
    a2 = y.tuSo * x.mauSo;
    if (a1 > a2) return 1;
    else if(a1 == a2) return 0;
    else return 2;
}

// Hàm xuất kết quả phân số lớn nhất
void xuatPhanSo(phanSo a, phanSo b){
    if(soSanh(a, b) == 1){
        rutGon(a);
        cout << "Phan so 1 la phan so lon nhat: p1 = " << a.tuSo << "/" << a.mauSo;
    }
    else if(soSanh(a, b) == 0){
        cout << "Hai phan so bang nhau.";
    }
    else{
        rutGon(b);
        cout << "Phan so 2 la phan so lon nhat: p2 = " << b.tuSo << "/" << b.mauSo;
    }
}

// Hàm nhập phân số từ người dùng
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

    // Làm tròn nếu có số thập phân
    lamTron(p1.tuSo, p1.mauSo);
    lamTron(p2.tuSo, p2.mauSo);

    // Xuất kết quả
    xuatPhanSo(p1, p2);

    return 0;
}
