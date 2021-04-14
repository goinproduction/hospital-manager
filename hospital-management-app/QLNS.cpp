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
	int n;
	cout << "So luong nhan vien can nhap: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\t\tChon kieu nhan vien" << endl;
		cout << "\t\t1. Bac si" << endl;
		cout << "\t\t2. Dieu phoi" << endl;
		cout << "\t\t3. Tai vu" << endl;
		cout << "\t\t4. Ban thuoc" << endl;
		cout << "\t\t5. Ke toan" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "\t\tNhap lua chon: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			this->NhanVien[i] = new BacSi();
			break;
		case 2:
			this->NhanVien[i] = new TTDP();
			break;
		case 3:
			this->NhanVien[i] = new TaiVu();
			break;
		case 4:
			this->NhanVien[i] = new BanThuoc();
			break;
		case 5:
			this->NhanVien[i] = new KeToan();
			break;
		default:
			break;
		}
		cin >> *NhanVien[i];
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
