#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

struct HocSinh {
    string hoTen;
    float diemToan, diemVan, diemAnh, diemTB;
};

// Kiểm tra họ tên không chứa chữ số
bool kiemTraHoTen(string ten) {
    for (char c : ten) {
        if (isdigit(c)) return false;
    }
    return !ten.empty();
}

// Nhập điểm và kiểm tra hợp lệ
float nhapDiem(string mon) {
    float diem;
    while (true) {
        cout << "Nhap diem " << mon << ": ";
        cin >> diem;
        if (!cin.fail() && diem >= 0 && diem <= 10) return diem;
        cout << "Diem khong hop le! Nhap lai.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Chuyển đổi chữ cái đầu tiên của mỗi từ thành chữ hoa
string chuanHoaTen(string ten) {
    bool vietHoa = true;
    for (char &c : ten) {
        if (vietHoa && isalpha(c)) {
            c = toupper(c);
            vietHoa = false;
        } else {
            c = tolower(c);
        }
        if (c == ' ') vietHoa = true;
    }
    return ten;
}

// Nhập thông tin học sinh
void nhapHocSinh(HocSinh &hs, int stt) {
    cin.ignore();
    while (true) {
        cout << "Nhap ho ten hoc sinh " << stt << ": ";
        getline(cin, hs.hoTen);
        if (kiemTraHoTen(hs.hoTen)) break;
        cout << "Ho ten khong hop le! Khong duoc co chu so. Nhap lai.\n";
    }
    hs.hoTen = chuanHoaTen(hs.hoTen);
    hs.diemToan = nhapDiem("Toan");
    hs.diemVan = nhapDiem("Van");
    hs.diemAnh = nhapDiem("Anh");
    hs.diemTB = (2 * hs.diemToan + hs.diemVan + hs.diemAnh) / 4;
}

// Xếp loại học sinh
string xepLoai(float diemTB) {
    if (diemTB >= 9) return "Xuat sac";
    if (diemTB >= 8) return "Gioi";
    if (diemTB >= 6.5) return "Kha";
    if (diemTB >= 5) return "Trung binh";
    return "Yeu";
}

// Xuất thông tin một học sinh
void xuatHocSinh(HocSinh hs, int stt) {
    cout << left << setw(4) << stt << setw(20) << hs.hoTen
         << setw(8) << hs.diemToan
         << setw(8) << hs.diemVan
         << setw(8) << hs.diemAnh
         << setw(8) << hs.diemTB
         << setw(12) << xepLoai(hs.diemTB) << endl;
}

// Nhập danh sách học sinh
void nhapDanhSachHocSinh(HocSinh ds[], int n) {
    for (int i = 0; i < n; i++) {
        nhapHocSinh(ds[i], i + 1);
    }
}

// Xuất danh sách học sinh
void xuatDanhSachHocSinh(HocSinh ds[], int n) {
    cout << left << setw(4) << "STT" << setw(20) << "Ho Ten" << setw(8) << "Toan" << setw(8) << "Van" << setw(8) << "Anh" << setw(8) << "DTB" << setw(12) << "Xep Loai" << endl;
    for (int i = 0; i < n; i++) {
        xuatHocSinh(ds[i], i + 1);
    }
}

// Chuyển chuỗi thành chữ thường để tìm kiếm không phân biệt hoa thường
string chuThuong(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Tìm học sinh theo tên
void timHocSinh(HocSinh ds[], int n, string ten) {
    bool timThay = false;
    ten = chuThuong(ten);
    cout << "Ket qua tim kiem: \n";
    for (int i = 0; i < n; i++) {
        if (chuThuong(ds[i].hoTen).find(ten) != string::npos) {
            timThay = true;
        }
    }

    if (!timThay){
        cout << "Khong tim thay." << endl;
        }
    else{
        cout << left << setw(4) << "STT" << setw(20) << "Ho Ten"
         << setw(8) << "Toan" << setw(8) << "Van"
         << setw(8) << "Anh" << setw(8) << "DTB"
         << setw(12) << "Xep Loai" << endl;
        for (int i = 0; i < n; i++) {
            if (chuThuong(ds[i].hoTen).find(ten) != string::npos) {
                xuatHocSinh(ds[i], i + 1);
                timThay = true;
            }
        }
    }
}

// Tìm học sinh có điểm Toán thấp nhất
void timDiemToanThapNhat(HocSinh ds[], int n) {
    float minDiem = 10;
    for (int i = 0; i < n; i++) {
        if (ds[i].diemToan < minDiem) minDiem = ds[i].diemToan;
    }
    cout << "Hoc sinh co diem Toan thap nhat:\n";
    cout << left << setw(4) << "STT" << setw(20) << "Ho Ten" << setw(8) << "Toan" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].diemToan == minDiem) {
            cout << left << setw(4) << (i + 1) << setw(20) << ds[i].hoTen << setw(8) << ds[i].diemToan << endl;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    HocSinh ds[n];
    nhapDanhSachHocSinh(ds, n);
    xuatDanhSachHocSinh(ds, n);

    cin.ignore();
    string ten;
    cout << "Nhap ten hoc sinh can tim: ";
    getline(cin, ten);
    timHocSinh(ds, n, ten);

    timDiemToanThapNhat(ds, n);

    return 0;
}
