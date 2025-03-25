#include <iostream>
#include<cmath>
using namespace std;

int main(){
double x = 0;
double sum , a;
int i = 1;
cout<<"Nhap gia tri: ";
cin>>x;
sum=x;
a=x;
while (fabs(a) > 0.00001) {
    a *= (-x * x) / ((2*i)*(2*i+1));
    sum += a;
    i++;
        }
cout<<"Ket qua la: "<<sum<<endl;
return 0;
}
