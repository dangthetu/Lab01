#include <iostream>
#include<math.h>

using namespace std;

int ucln(int,int);

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

bool check(double n)
{
    return ceil(n) == floor(n);
}

int lamtron(double &a, double &b)
{
    if(check(a)==0||check(b)==0)
    {
    int da = dem10(a),db = dem10(b);
    if(da>db){
        a*=pow(10,da);
        b*=pow(10,da);
    }
    else{
        a*=pow(10,db);
        b*=pow(10,db);
    }

    }
    return ucln(a,b);

}

int ucln(int a, int b)
{
    if(b>a)
    {
        int temp = a;
        a=b;
        b=temp;
    }
    if(b==0)
    {
        return a;
    }
    return ucln(a%b,b);
}

struct phanso
{
double tuso, mauso;

};
int main(){

phanso p1;
int u=0;
int i=0;
while(i<1)
{
cout<<"Nhap tu so: ";
cin>>p1.tuso;
cout<<"Nhap mau so: ";
cin>>p1.mauso;
if(p1.tuso==p1.mauso)
{
cout<<"Phan so la: 1";
i++;
}
else if(p1.tuso==0)
{
cout<<"Phan so la: 0";
i++;
}
else if(p1.mauso!=0)
{
if(p1.tuso<0||p1.mauso<0)
{
p1.tuso = fabs(p1.tuso);
p1.mauso = fabs(p1.mauso);
u = lamtron(p1.tuso, p1.mauso);
p1.tuso = p1.tuso/u;
p1.mauso = p1.mauso/u;
i++;
cout<<"Phan so rut gon la: -";
cout<<p1.tuso<<"/"<<p1.mauso;
}
else
{
u = lamtron(p1.tuso, p1.mauso);
p1.tuso = p1.tuso/u;
p1.mauso = p1.mauso/u;
i++;
cout<<"Phan so rut gon la: ";
cout<<p1.tuso<<"/"<<p1.mauso;
}
}
else cout<<"Nhap sai, moi nhap lai."<<endl;
}
return 0;
}
