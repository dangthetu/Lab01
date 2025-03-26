#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x = 0;
    double sum, a;
    int i = 1;

    cout << "Nhap gia tri: ";
    cin >> x;

    sum = x;
    a = x;

    // Vòng lặp tính giá trị gần đúng của sin(x) bằng chuỗi Taylor
    while (fabs(a) > 0.00001) {
        // Tính phần tử tiếp theo của chuỗi Taylor
        a *= (-x * x) / ((2 * i) * (2 * i + 1));

        // Cộng giá trị phần tử mới vào tổng
        sum += a;

        // Tăng bậc của chuỗi lên
        i++;
    }

    cout << "Ket qua la: " << sum << endl;
    return 0;
}
