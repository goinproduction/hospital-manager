#include "NhanVienKeToan.h"
#include "App.h"
BoPhanKeToan::BoPhanKeToan()
{
}

BoPhanKeToan::~BoPhanKeToan()
{
}

void BoPhanKeToan::TinhLuong()
{
	double luongCoBan, phuCap;
	int soNgayCong;
	system("cls");
	cout << "\t========>>NHAP LUONG NHAN VIEN<<========" << endl;
	int size = dsNhanVien.size();
	if (size == 0)
	{
		cout << "Danh sach nhan vien rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		bool flag;
		string ma;
		while (1) {
			do
			{
				fflush(stdin);
				cin.ignore();
				cout << "Ma nhan vien: ";
				getline(cin, ma);
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						flag = true;
						cin.ignore();
						cout << "Luong co ban: ";
						cin >> luongCoBan;
						cout << "So ngay cong: ";
						cin >> soNgayCong;
						cout << "Phu cap: ";
						cin >> phuCap;
						dsNhanVien[i]->setLuongCB(luongCoBan);
						dsNhanVien[i]->setSoNgayCong(soNgayCong);
						dsNhanVien[i]->setPhuCap(phuCap);
						dsNhanVien[i]->setTongLuong(dsNhanVien[i]->getLuongCB() * dsNhanVien[i]->getSoNgayCong() + dsNhanVien[i]->getPhuCap());
					}
					else
					{
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ma nhan vien khong ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc tinh luong cho nhan vien khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					continue;
				}
				else if (luaChon == 0)
				{
					system("cls");
					this->BPKTMenu();
				}
			}
		}
	}
}

void BoPhanKeToan::Xuat()
{
	int size = dsNhanVien.size();
	if (size == 0)
	{
		system("cls");
		cout << "========>>DANH SACH LUONG NHAN VIEN<<========" << endl;
		cout << "Danh sach nhan vien rong, vui long kiem tra lai!" << endl;
	}
	else {
		system("cls");
		cout << "========>>DANH SACH LUONG NHAN VIEN<<========" << endl;
		int size = dsNhanVien.size();
		for (int i = 0; i < size; i++)
		{
			cout << "\nSo thu tu: " << i + 1 << endl;
			cout << "Ma: " << dsNhanVien[i]->getMaNV() << endl;
			cout << "Ten: " << dsNhanVien[i]->getName() << endl;
			cout << "Luong co ban: " << dsNhanVien[i]->getLuongCB() << endl;
			cout << "So ngay cong: " << dsNhanVien[i]->getSoNgayCong() << endl;
			cout << "Phu cap: " << dsNhanVien[i]->getPhuCap() << endl;
			cout << "Tong luong: " << dsNhanVien[i]->getTongLuong() << endl;
		}
	}
	system("pause");
}

void BoPhanKeToan::CapNhat()
{
	double luongCoBan, phuCap;
	int soNgayCong;
	system("cls");
	cout << "\t========>>CAP NHAT LUONG NHAN VIEN<<========" << endl;
	int size = dsNhanVien.size();
	if (size == 0)
	{
		cout << "Danh sach nhan vien rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		bool flag;
		string ma;
		while (1) {
			do
			{
				fflush(stdin);
				cin.ignore();
				cout << "Ma nhan vien: ";
				getline(cin, ma);
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						int luaChon;
						cout << "Chon danh muc can cap nhat (1. Luong co ban; 2. So ngay cong; 3. Phu cap): ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							cout << "Luong co ban: ";
							cin >> luongCoBan;
							dsNhanVien[i]->setLuongCB(luongCoBan);
							break;
						}
						else if (luaChon == 2)
						{
							cout << "So ngay cong: ";
							cin >> soNgayCong;
							dsNhanVien[i]->setSoNgayCong(soNgayCong);
							break;
						}
						else if (luaChon == 3)
						{
							cout << "Phu cap: ";
							cin >> phuCap;
							dsNhanVien[i]->setPhuCap(phuCap);
							break;
						}
						flag = true;
						dsNhanVien[i]->setTongLuong(dsNhanVien[i]->getLuongCB() * dsNhanVien[i]->getSoNgayCong() + dsNhanVien[i]->getPhuCap());
					}
					else
					{
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ma nhan vien khong ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc cap nhat luong cho nhan vien khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					continue;
				}
				else if (luaChon == 0)
				{
					system("cls");
					this->BPKTMenu();
				}
			}
		}
	}
}

void BoPhanKeToan::TimKiem()
{
	system("cls");
	cout << "\t========>>TIM KIEM NHAN VIEN<<========" << endl;
	int size = dsNhanVien.size();
	if (size == 0)
	{
		cout << "Danh sach nhan vien rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		bool flag;
		string ma;
		while (1) {
			do
			{
				fflush(stdin);
				cin.ignore();
				cout << "Ma nhan vien: ";
				getline(cin, ma);
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						flag = true;
						cout << "========>>THONG TIN NHAN VIEN<<========" << endl;
						cout << "Ma: " << dsNhanVien[i]->getMaNV() << endl;
						cout << "Ten: " << dsNhanVien[i]->getName() << endl;
						cout << "Luong co ban: " << dsNhanVien[i]->getLuongCB() << endl;
						cout << "So ngay cong: " << dsNhanVien[i]->getSoNgayCong() << endl;
						cout << "Phu cap: " << dsNhanVien[i]->getPhuCap() << endl;
						cout << "Tong luong: " << dsNhanVien[i]->getTongLuong() << endl;
						break;
					}
					else
					{
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ma nhan vien khong ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc tim nhan vien khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					continue;
				}
				else if (luaChon == 0)
				{
					system("cls");
					this->BPKTMenu();
				}
			}
		}
	}
}

void BoPhanKeToan::BPKTMenu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>BO PHAN KE TOAN<<========" << endl;
		cout << "\t\t1. Nhap" << endl;
		cout << "\t\t2. Xuat" << endl;
		cout << "\t\t3. Cap nhat" << endl;
		cout << "\t\t4. Tim kiem" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->TinhLuong();
		}
		else if (luaChon == 2)
		{
			this->Xuat();
		}
		else if (luaChon == 3)
		{
			this->CapNhat();
		}
		else if (luaChon == 4)
		{
			this->TimKiem();
		}
		else if (luaChon == 0)
		{
			
		}
	}
}
