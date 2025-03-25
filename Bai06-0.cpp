#include <iostream>

using namespace std;

const int MAX_SIZE = 1000; // Giới hạn kích thước mảng

// Hàm tìm các vị trí xuất hiện của mảng A trong mảng B
void timViTriXuatHien(int A[], int n, int B[], int m, int viTri[], int& soLuong) {
    soLuong = 0;

    for (int i = 0; i <= m - n; i++) { // Duyệt qua mảng B
        bool found = true;
        for (int j = 0; j < n; j++) {
            if (B[i + j] != A[j]) { // Nếu có phần tử khác nhau, bỏ qua
                found = false;
                break;
            }
        }
        if (found) viTri[soLuong++] = i; // Nếu tìm thấy, lưu vị trí
    }
}

// Hàm nhập dữ liệu cho mảng
void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
}

// Hàm xuất dữ liệu của mảng
void xuatMang(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, m, soLuong;
    cin >> n >> m;  // Nhập số phần tử của A và B

    int A[MAX_SIZE], B[MAX_SIZE], viTri[MAX_SIZE];

    nhapMang(A, n); // Nhập mảng A
    nhapMang(B, m); // Nhập mảng B


    timViTriXuatHien(A, n, B, m, viTri, soLuong); // Tìm vị trí xuất hiện của A trong B

    cout << soLuong << endl; // In số lần xuất hiện
    xuatMang(viTri, soLuong); // In danh sách vị trí tìm được

    return 0;
}
