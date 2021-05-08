#include "BoPhanQuanLy.h"
#include "App.h"
void BoPhanQuanLy::Nhap()
{
	while (1) {
		system("cls");
		int luaChon;
		NV* nv = new NV;
		cout << "\t\t========>>BO PHAN<<========" << endl;
		cout << "\t\t1. Bac si dieu tri" << endl;
		cout << "\t\t2. Bo phan Tiep tan va Dieu phoi" << endl;
		cout << "\t\t3. Phong Tai vu" << endl;
		cout << "\t\t4. Bo phan Ban thuoc" << endl;
		cout << "\t\t5. Bo phan Ke toan" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			nv = new BacSi;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					cout << "Ma bi trung, vui long nhap lai!";
				}
			} while (flag == false);
			nv->setMaNV(ma);
			nv->setChucVu(1);
			nv->Nhap();
			dsNhanVien.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 2)
		{
			nv = new BacSi;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					cout << "Ma bi trung, vui long nhap lai!";
				}
			} while (flag == false);
			nv->setMaNV(ma);
			nv->setChucVu(2);
			nv->Nhap();
			dsNhanVien.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 3)
		{
			nv = new BacSi;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					cout << "Ma bi trung, vui long nhap lai!";
				}
			} while (flag == false);
			nv->setMaNV(ma);
			nv->setChucVu(3);
			nv->Nhap();
			dsNhanVien.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 4)
		{
			nv = new BacSi;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien[i]->getMaNV() == ma)
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					cout << "Ma bi trung, vui long nhap lai!";
				}
			} while (flag == false);
			nv->setMaNV(ma);
			nv->setChucVu(4);
			nv->Nhap();
			dsNhanVien.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 5)
		{
		nv = new BacSi;
		string ma;
		bool flag;
		do
		{
			cin.ignore();
			cout << "Ma NV: ";
			getline(cin, ma);
			size_t size = dsNhanVien.size();
			flag = true;
			for (int i = 0; i < size; i++)
			{
				if (dsNhanVien[i]->getMaNV() == ma)
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
			{
				cout << "Ma bi trung, vui long nhap lai!";
			}
		} while (flag == false);
		nv->setMaNV(ma);
		nv->setChucVu(5);
		nv->Nhap();
		dsNhanVien.push_back(nv);
		cout << "Thanh cong!" << endl;
		system("pause");
		}
		else if (luaChon == 0)
		{
			system("cls");
			break;
			this->BPQLMenu();
		}
	}
}

BoPhanQuanLy::BoPhanQuanLy()
{
}
BoPhanQuanLy::~BoPhanQuanLy()
{

}

void BoPhanQuanLy::Xuat()
{
	system("cls");
	cout << "========>>DANH SACH NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien.size();
	for (int i = 0; i < size; i++)
	{
		cout << "\nSo thu tu: " << i + 1 << endl;
		dsNhanVien[i]->Xuat();
	}
}

void BoPhanQuanLy::CapNhat()
{
	system("cls");
	cout << "\t========>>CAP NHAT NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien.size();
	if (size == 0)
	{
		cout << "Danh sach nhan vien rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else
	{
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
						string idUpdate;
						int cvUpdate;
						bool flag;
						do
						{
							cout << "Ma NV: ";
							getline(cin, idUpdate);
							size_t size = dsNhanVien.size();
							flag = true;
							for (int i = 0; i < size; i++)
							{
								if (dsNhanVien[i]->getMaNV() == idUpdate)
								{
									flag = false;
									break;
								}
							}
							if (flag == false)
							{
								cout << "Ma bi trung, vui long nhap lai!";
							}
						} while (flag == false);
						dsNhanVien[i]->setMaNV(idUpdate);
						dsNhanVien[i]->Nhap();
						cout << "Chuc vu (1. Bac si; 2. TTDP; 3. Tai vu; 4. Ban thuoc; 5. Ke toan): ";
						cin >> cvUpdate;
						dsNhanVien[i]->setChucVu(cvUpdate);
						cout << "Cap nhat thanh cong!" << endl;
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
			if (flag)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc cap nhat nhan vien khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
					this->BPQLMenu();
				}
			}
		}
	}
}

void BoPhanQuanLy::Xoa()
{
	system("cls");
	cout << "\t========>>XOA NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien.size();
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
						int luaChon;
						cout << "Ban co chac chan xoa khong? (1: Co; 0: Khong): ";
						cin >> luaChon;
						if (luaChon == 0)
						{
							continue;
						}
						else if (luaChon == 1)
						{
							dsNhanVien.pop_back();
							size--;
							cout << "Xoa thanh cong!" << endl;
						}
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
				cout << "\nBan co muon tiep tuc xoa nhan vien khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					continue;
				}
				else if (luaChon == 0)
				{	
					break;
					system("cls");
					this->BPQLMenu();
				}
			}
			else {
				cout << "\nDanh sach nhan vien rong!" << endl;
				system("pause");
				break;
			}
		}
	}
}

void BoPhanQuanLy::TimKiem()
{
	system("cls");
	cout << "\t========>>TIM KIEM NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien.size();
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
						dsNhanVien[i]->Xuat();
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
					break;
					system("cls");
					this->BPQLMenu();
				}
			}
		}
	}
}

void BoPhanQuanLy::BPQLMenu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>BO PHAN QUAN LY NHAN SU<<========" << endl;
		cout << "\t\t1. Nhap nhan vien" << endl;
		cout << "\t\t2. Xuat danh sach" << endl;
		cout << "\t\t3. Cap nhat" << endl;
		cout << "\t\t4. Xoa" << endl;
		cout << "\t\t5. Tim kiem" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->Nhap();
		}
		else if (luaChon == 2)
		{
			this->Xuat();
			system("pause");
		}
		else if (luaChon == 3)
		{
			this->CapNhat();
		}
		else if (luaChon == 4)
		{
			this->Xoa();
		}
		else if (luaChon == 5)
		{
			this->TimKiem();
		}
		else if (luaChon == 0)
		{
			App* app = new App;
			app->Menu();
		}
	}
}
