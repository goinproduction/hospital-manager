#include "QLNS.h"
#include "App.h"

QLNS::QLNS()
{
}

QLNS::QLNS(const QLNS& obj)
{
}

void QLNS::Nhap(istream& in)
{
	int luaChon;
	cout << "============================>> QUAN LY BENH VIEN <<============================\n";
	cout << "\t\t1. Bac si" << endl;
	cout << "\t\t2. Dieu phoi" << endl;
	cout << "\t\t3. Tai vu" << endl;
	cout << "\t\t4. Ban thuoc" << endl;
	cout << "\t\t5. Ke toan" << endl;
	cout << "\t\t0. Thoat ra" << endl;
	cout << "\t\tNhap lua chon: ";
	cin >> luaChon;
	if (luaChon == 0)
	{

	}
	else if (luaChon == 1)
	{

	}
	else if (luaChon == 2)
	{

	}
	else if (luaChon == 3)
	{

	}
	else if (luaChon == 4)
	{

	}
	else if (luaChon == 0)
	{
		system("cls");

	}
}

void QLNS::Xuat(ostream& out)
{
}


void QLNS::QLNSMenu()
{
	int luaChon;
	cout << "\t=======>> QUAN LY NHAN VIEN <<=======" << endl;
	cout << "\t\t1. Nhap thong tin" << endl;
	cout << "\t\t2. Xuat thong tin" << endl;
	cout << "\t\t3. Tim kiem" << endl;
	cout << "\t\t0. Quay lai" << endl;
	cout << "\t\tNhap lua chon: ";
	cin >> luaChon;
	if (luaChon == 1)
	{

	}
	else if (luaChon == 2)
	{

	}
	else if (luaChon == 0)
	{
		system("cls");
		QLNSMenu();
	}
}

QLNS::~QLNS()
{
}
