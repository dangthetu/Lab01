#include <iostream>

using namespace std;

struct dateTime{
int day, month, year;

};

dateTime tomorrowTime(dateTime a){
int maxDay = 0;
    switch (a.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxDay = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;
            break;
        case 2:
            if((a.year%4==0 && a.year%100!=0)||(a.year%400==0)){
               maxDay = 29;
            }
            else{
               maxDay=28;
            }
            break;
    }
    a.day++;
    if (a.day > maxDay) {
        a.day = 1;
        a.month++;
        if (a.month > 12) {
            a.month = 1;
            a.year++;
        }
    }
    return a;
}

dateTime yesterdayTime(dateTime a){
    int minDay=1;
    a.day--;
    if(a.day<minDay){
        a.month--;
    switch (a.month) {
        case 0:
            a.month=12;
            a.day=31;
            a.year--;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            a.day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            a.day = 30;
            break;
        case 2:
            if((a.year%4==0 && a.year%100!=0)||(a.year%400==0)){
              a.day=29;
            }
            else{
               a.day=28;
            }
            break;
        }

    }

    return a;
}

int numTime(dateTime a) {
int countDay = 0;
int s1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((a.year%4==0 && a.year%100!=0)||(a.year%400==0)) {
        s1[1] = 29;
    }

    for (int i = 0; i < a.month - 1; i++) {
        countDay += s1[i];
    }
    countDay += a.day;
if(a.year>0)
    return countDay;
else{
    if((a.year%4==0 && a.year%100!=0)||(a.year%400==0)){
        countDay = 367-countDay;
    }
    else{
        countDay=366-countDay;
    }
   return countDay;
}
}

void nhapTime(dateTime &a){
int i=0;
while(i==0){
cout<<"Nhap ngay: ";
cin>>a.day;
cout<<"Nhap thang: ";
cin>>a.month;
cout<<"Nhap nam: ";
cin>>a.year;
i = 1;
    switch(a.month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if((a.day > 31)||(a.day < 1)){
                cout<<"Ngay khong hop le, moi nhap lai.\n";
                i=0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if((a.day > 30)||(a.day<1)){
                cout<<"Ngay khong hop le, moi nhap lai.\n";
                i=0;
            }
            break;
        case 2:
            if((a.year%4==0 && a.year%100!=0)||(a.year%400==0)){
                if(a.day>29||a.day<1){
                    cout<<"Ngay khong hop le, moi nhap lai.\n";
                    i=0;
                }
            }
            else{
                if(a.day>28||a.day<1){
                    cout<<"Ngay khong hop le, moi nhap lai.\n";
                    i=0;
                }
            }
            break;
        default:
            cout<<"Ngay, thang khong hop le, moi nhap lai.\n";
            i=0;
            break;
    }
    if(a.year==0){
        cout<<"Nam khong hop le, moi nhap lai.\n";
        i=0;
    }
  }
}
int main(){
dateTime a1,a2,a3;
int a4;
nhapTime(a1);
a2=tomorrowTime(a1);
a3=yesterdayTime(a1);
a4=numTime(a1);

if(a2.day==2 && a2.month == 1 && a2.year == -1 ){
cout<<"Ngay ke tiep la: 1/1/1 "<<endl;
}
else if(a2.year<0){
a3.year*=-1;
cout<<"Ngay ke tiep la: "<<a3.day<<"/"<<a3.month<<"/"<<a3.year<<" TCN"<<endl;
a3.year*=-1;
}
else{
cout<<"Ngay ke tiep la: "<<a2.day<<"/"<<a2.month<<"/"<<a2.year<<endl;
}

if(a3.year<0){
a2.year*=-1;
cout<<"Ngay lien truoc la: "<<a2.day<<"/"<<a2.month<<"/"<<a2.year<<" TCN"<<endl;
}
else if(a3.day==31 && a3.month == 12 && a3.year == 0 ){
cout<<"Ngay lien truoc la: 1/1/1 TCN"<<endl;
}
else {
cout<<"Ngay lien truoc la: "<<a3.day<<"/"<<a3.month<<"/"<<a3.year<<endl;
}

cout<<"Ngay thu "<<a4<<" trong nam.";
}
