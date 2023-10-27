#include<bits/stdc++.h>
using namespace std;
class phieu;
class nv
{
	char tennv[20];
	char chucvu[20];
	char phong[20];
	char maphong[20];
	char truongphong[20];
public:
	void nhap();
	void xuat();
};
class taisan
{
	char tents[20];
	char tinhtrang[20];
	int soluong;
public:
	void nhap();
	void xuat();
	friend class phieu;
	friend void dem(phieu a);
	friend void chen(phieu &a);
};
class phieu
{
	char maphieu[20];
	char ngaykiemke[20];
	nv y;
	taisan *x;
	int n;
public:
	void nhap();
	void xuat();
	friend void dem(phieu a);	
	friend void chen(phieu &a);
};
void nv::nhap()
{
	cout<<"Nv kiem ke: "; fflush(stdin); gets(tennv);
	cout<<"Chuc vu: "; fflush(stdin); gets(chucvu);
	cout<<"Kiem ke tai phong: "; fflush(stdin); gets(phong);
	cout<<"Ma phong: "; fflush(stdin); gets(maphong);
	cout<<"Truong phong: "; fflush(stdin); gets(truongphong);
}
void nv::xuat()
{
	cout<<"Nhan vien kiem ke: "<<tennv<<setw(20)<<"Chuc vu: "<<chucvu<<endl;
	cout<<"Kiem ke tai phong: "<<phong<<setw(20)<<"Ma phong: "<<maphong<<endl;
	cout<<"Truong phong: "<<truongphong<<endl;
}
void taisan::nhap()
{
	cout<<"Ten tai san: "; fflush(stdin); gets(tents);
	cout<<"So luong: "; cin>>soluong;
	cout<<"Tinh trang: "; fflush(stdin); gets(tinhtrang);
}
void taisan::xuat()
{
	cout<<tents<<setw(20)<<soluong<<setw(20)<<tinhtrang<<endl;
}
void phieu::nhap()
{
	cout<<"Ma phieu: "; fflush(stdin); gets(maphieu);
	cout<<"Ngay kiem ke: "; fflush(stdin); gets(ngaykiemke);
	y.nhap();
	cout<<"Nhap so tai san: "; cin>>n;
	x=new taisan[n];
	for(int i=0; i<n; i++)
	x[i].nhap();
	
	
}
void phieu::xuat()
{
	cout<<setw(30)<<"PHIEU KIEM KE TAI SAN"<<endl;
	cout<<"Ma phieu: "<<maphieu<<setw(20)<<"Ngay kiem ke: "<<ngaykiemke<<endl;
	y.xuat();
	cout<<"Ten tai san"<<setw(20)<<"So luong"<<setw(20)<<"Tinh trang"<<endl;
	for(int i= 0; i<n; i++)
	x[i].xuat();
	float tongsl=0;
	for(int i= 0; i<n; i++)
	tongsl+=x[i].soluong;
	cout<<"So tai san da kiem ke: "<<n<<setw(20)<<"Tong so luong: "<<tongsl<<endl;
}
void dem(phieu a)
{
	for(int i=0; i<a.n; i++)
	{
		if(a.x[i].soluong>3)
		a.x[i].xuat();
	}
}
void chen(phieu &a)
{
	int k;
	do
	{
		cout<<"/nNHAP VTRI CHEN: "; cin>>k;
	}while(k<0||k>a.n);
	taisan n1;
	cout<<"Nhap tai san moi: "<<endl;
	n1.nhap();
	for(int i=a.n-1; i>k; i--)
	{
		a.x[i]=a.x[i-1];
		
	}
	a.x[k]=n1;
	a.n++;
}
int main()
{
	phieu a;
	a.nhap();
	a.xuat();
	cout<<"tai san co sl lon hon 3: "<<endl;
	dem(a);
	chen(a);
	a.xuat();
	return 0;
}
