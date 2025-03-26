#include <iostream>

using namespace std;

// Định nghĩa cấu trúc để lưu trữ ngày tháng năm
struct dateTime {
    int day, month, year;
};

// Hàm tính ngày hôm sau của một ngày bất kỳ
dateTime tomorrowTime(dateTime a) {
    int maxDay = 0;

    // Xác định số ngày tối đa của tháng hiện tại
    switch (a.month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        case 2:
            // Kiểm tra năm nhuận
            if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) {
                maxDay = 29;
            } else {
                maxDay = 28;
            }
            break;
    }

    // Tăng ngày lên 1
    a.day++;

    // Nếu ngày vượt quá số ngày của tháng, chuyển sang tháng tiếp theo
    if (a.day > maxDay) {
        a.day = 1;
        a.month++;

        // Nếu tháng vượt quá 12, chuyển sang năm mới
        if (a.month > 12) {
            a.month = 1;
            a.year++;
        }
    }

    return a;
}

// Hàm tính ngày hôm trước của một ngày bất kỳ
dateTime yesterdayTime(dateTime a) {
    int minDay = 1;
    a.day--;

    // Nếu ngày nhỏ hơn 1, cần lùi về tháng trước
    if (a.day < minDay) {
        a.month--;

        // Xác định số ngày của tháng trước
        switch (a.month) {
            case 0: // Nếu tháng trước là tháng 0, tức là năm mới, cần chuyển sang tháng 12 năm trước
                a.month = 12;
                a.day = 31;
                a.year--;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10:
                a.day = 31;
                break;
            case 4: case 6: case 9: case 11:
                a.day = 30;
                break;
            case 2:
                // Kiểm tra năm nhuận để xác định ngày của tháng 2
                if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) {
                    a.day = 29;
                } else {
                    a.day = 28;
                }
                break;
        }
    }

    return a;
}

// Hàm tính số thứ tự của ngày trong năm
int numTime(dateTime a) {
    int countDay = 0;
    // Mảng chứa số ngày của từng tháng trong năm không nhuận
    int s1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Nếu là năm nhuận, tháng 2 có 29 ngày
    if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) {
        s1[1] = 29;
    }

    // Cộng dồn số ngày của các tháng trước đó
    for (int i = 0; i < a.month - 1; i++) {
        countDay += s1[i];
    }

    // Cộng số ngày hiện tại
    countDay += a.day;

    // Nếu năm dương, trả về số ngày bình thường
    if (a.year > 0)
        return countDay;
    else {
        // Nếu năm âm, tính số ngày còn lại trong năm
        if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) {
            countDay = 367 - countDay;
        } else {
            countDay = 366 - countDay;
        }
        return countDay;
    }
}

// Hàm nhập ngày tháng năm từ người dùng
void nhapTime(dateTime &a) {
    int i = 0;
    while (i == 0) {
        cout << "Nhap ngay: ";
        cin >> a.day;
        cout << "Nhap thang: ";
        cin >> a.month;
        cout << "Nhap nam: ";
        cin >> a.year;
        i = 1;

        // Kiểm tra tính hợp lệ của ngày nhập vào
        switch (a.month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if ((a.day > 31) || (a.day < 1)) {
                    cout << "Ngay khong hop le, moi nhap lai.\n";
                    i = 0;
                }
                break;
            case 4: case 6: case 9: case 11:
                if ((a.day > 30) || (a.day < 1)) {
                    cout << "Ngay khong hop le, moi nhap lai.\n";
                    i = 0;
                }
                break;
            case 2:
                // Xử lý riêng cho tháng 2 dựa trên năm nhuận
                if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) {
                    if (a.day > 29 || a.day < 1) {
                        cout << "Ngay khong hop le, moi nhap lai.\n";
                        i = 0;
                    }
                } else {
                    if (a.day > 28 || a.day < 1) {
                        cout << "Ngay khong hop le, moi nhap lai.\n";
                        i = 0;
                    }
                }
                break;
            default:
                cout << "Ngay, thang khong hop le, moi nhap lai.\n";
                i = 0;
                break;
        }

        // Không chấp nhận năm 0
        if (a.year == 0) {
            cout << "Nam khong hop le, moi nhap lai.\n";
            i = 0;
        }
    }
}

int main() {
    dateTime a1, a2, a3;
    int a4;

    // Nhập ngày tháng năm từ người dùng
    nhapTime(a1);

    // Tính ngày kế tiếp và ngày trước đó
    a2 = tomorrowTime(a1);
    a3 = yesterdayTime(a1);

    // Tính số thứ tự ngày trong năm
    a4 = numTime(a1);

    // Xuất kết quả ngày kế tiếp
    if (a2.day == 2 && a2.month == 1 && a2.year == -1) {
        cout << "Ngay ke tiep la: 1/1/1 " << endl;
    } else if (a2.year < 0) {
        a3.year *= -1;
        cout << "Ngay ke tiep la: " << a3.day << "/" << a3.month << "/" << a3.year << " TCN" << endl;
        a3.year *= -1;
    } else {
        cout << "Ngay ke tiep la: " << a2.day << "/" << a2.month << "/" << a2.year << endl;
    }

    // Xuất kết quả ngày trước đó
    if (a3.year < 0) {
        a2.year *= -1;
        cout << "Ngay lien truoc la: " << a2.day << "/" << a2.month << "/" << a2.year << " TCN" << endl;
    } else if (a3.day == 31 && a3.month == 12 && a3.year == 0) {
        cout << "Ngay lien truoc la: 1/1/1 TCN" << endl;
    } else {
        cout << "Ngay lien truoc la: " << a3.day << "/" << a3.month << "/" << a3.year << endl;
    }

    // Xuất số thứ tự ngày trong năm
    cout << "Ngay thu " << a4 << " trong nam.";
}
