#include "BoPhanQuanLy.h"
#include <iostream>
using namespace std;
void BoPhanQuanLy::setVectorValuesBN(vector<BN*> val)
{
	this->dsBenhNhan_2.swap(val);
}
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
				size_t size = dsNhanVien_2.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien_2[i]->getMaNV() == ma)
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
			dsNhanVien_2.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 2)
		{
			nv = new TTDP;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien_2.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien_2[i]->getMaNV() == ma)
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
			dsNhanVien_2.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 3)
		{
			nv = new TaiVu;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien_2.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien_2[i]->getMaNV() == ma)
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
			dsNhanVien_2.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 4)
		{
			nv = new BanThuoc;
			string ma;
			bool flag;
			do
			{
				cin.ignore();
				cout << "Ma NV: ";
				getline(cin, ma);
				size_t size = dsNhanVien_2.size();
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsNhanVien_2[i]->getMaNV() == ma)
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
			dsNhanVien_2.push_back(nv);
			cout << "Thanh cong!" << endl;
			system("pause");
		}
		else if (luaChon == 5)
		{
		nv = new KeToan;
		string ma;
		bool flag;
		do
		{
			cin.ignore();
			cout << "Ma NV: ";
			getline(cin, ma);
			size_t size = dsNhanVien_2.size();
			flag = true;
			for (int i = 0; i < size; i++)
			{
				if (dsNhanVien_2[i]->getMaNV() == ma)
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
		dsNhanVien_2.push_back(nv);
		cout << "Thanh cong!" << endl;
		system("pause");
		}
		else if (luaChon == 0)
		{
			system("cls");
			break;
		}
	}
}

BoPhanQuanLy::BoPhanQuanLy()
{
}

BoPhanQuanLy::~BoPhanQuanLy()
{
}

void BoPhanQuanLy::setVectorValuesNV(vector<NV*> val)
{
	this->dsNhanVien_2.swap(val);
}

void BoPhanQuanLy::Xuat()
{
	system("cls");
	cout << "========>>DANH SACH NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien_2.size();
	for (int i = 0; i < size; i++)
	{
		cout << "\nSo thu tu: " << i + 1 << endl;
		dsNhanVien_2[i]->Xuat();
	}
}

void BoPhanQuanLy::CapNhat()
{
	system("cls");
	cout << "\t========>>CAP NHAT THONG TIN NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien_2.size();
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
					if (dsNhanVien_2[i]->getMaNV() == ma)
					{
						flag = true;
						string idUpdate;
						int cvUpdate;
						bool flag;
						do
						{
							cout << "Ma NV: ";
							getline(cin, idUpdate);
							size_t size = dsNhanVien_2.size();
							flag = true;
							for (int i = 0; i < size; i++)
							{
								if (dsNhanVien_2[i]->getMaNV() == idUpdate)
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
						dsNhanVien_2[i]->setMaNV(idUpdate);
						dsNhanVien_2[i]->Nhap();
						cout << "Chuc vu (1. Bac si; 2. TTDP; 3. Tai vu; 4. Ban thuoc; 5. Ke toan): ";
						cin >> cvUpdate;
						dsNhanVien_2[i]->setChucVu(cvUpdate);
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
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
				}
			}
		}
	}
}

void BoPhanQuanLy::Xoa()
{
	system("cls");
	cout << "\t========>>XOA NHAN VIEN<<========" << endl;
	size_t size = dsNhanVien_2.size();
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
					if (dsNhanVien_2[i]->getMaNV() == ma)
					{
						flag = true;
						int luaChon;
						cout << "Ban co chac chan xoa khong? (1: Co; 0: Khong): ";
						cin >> luaChon;
						if (luaChon == 0)
						{
							system("cls");
							break;
						}
						else if (luaChon == 1)
						{
							auto buffer = dsNhanVien_2.begin();
							while (buffer != dsNhanVien_2.end()) {
								if ((*buffer)->getMaNV() == ma)
								{
									delete* buffer;
									dsNhanVien_2.erase(buffer);
									break;
								}
								buffer++;
							}
							cout << "Xoa thanh cong!" << endl;
							break;
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
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{	
					break;
					system("cls");
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
	size_t size = dsNhanVien_2.size();
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
					if (dsNhanVien_2[i]->getMaNV() == ma)
					{
						flag = true;
						cout << "========>>THONG TIN NHAN VIEN<<========" << endl;
						dsNhanVien_2[i]->Xuat();
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
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
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
		cout << "\t\t1. Nhap thong tin nhan vien" << endl;
		cout << "\t\t2. Xuat danh sach" << endl;
		cout << "\t\t3. Cap nhat danh sach" << endl;
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
			app->setVectorValueNV(dsNhanVien_2);
			app->setVectorValueBN(dsBenhNhan_2);
			app->Menu();
		}
	}
}
