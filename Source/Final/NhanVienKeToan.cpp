#include "NhanVienKeToan.h"
#pragma warning (disable : 4267)
BoPhanKeToan::BoPhanKeToan()
{
}

BoPhanKeToan::~BoPhanKeToan()
{
}

void BoPhanKeToan::setVectorValuesNV(vector<NV*> val)
{
	this->dsNhanVien_2.swap(val);
}

void BoPhanKeToan::setVectorValuesBN(vector<BN*> val)
{
	this->dsBenhNhan_2.swap(val);
}

void BoPhanKeToan::TinhLuong()
{
	__int64 luongCoBan, phuCap;
	int soNgayCong;
	system("cls");
	cout << "\t========>>NHAP LUONG NHAN VIEN<<========" << endl;
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
						cout << "Luong co ban: ";
						cin >> luongCoBan;
						cout << "So ngay cong: ";
						cin >> soNgayCong;
						cout << "Phu cap: ";
						cin >> phuCap;
						dsNhanVien_2[i]->setLuongCB(luongCoBan);
						dsNhanVien_2[i]->setSoNgayCong(soNgayCong);
						dsNhanVien_2[i]->setPhuCap(phuCap);
						dsNhanVien_2[i]->setTongLuong(dsNhanVien_2[i]->getLuongCB() * (static_cast<__int64>(dsNhanVien_2[i]->getSoNgayCong()) / 30) + dsNhanVien_2[i]->getPhuCap());
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
				cout << "\nBan co muon tiep tuc tinh luong cho nhan vien khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					system("cls");
					break;
				}
			}
		}
	}
}


void BoPhanKeToan::CapNhat()
{
	__int64 luongCoBan, phuCap;
	int soNgayCong;
	system("cls");
	cout << "\t========>>CAP NHAT LUONG NHAN VIEN<<========" << endl;
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
						int luaChon;
						cout << "Chon danh muc can cap nhat (1. Luong co ban; 2. So ngay cong; 3. Phu cap): ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							cout << "Luong co ban: ";
							cin >> luongCoBan;
							dsNhanVien_2[i]->setLuongCB(luongCoBan);
						}
						else if (luaChon == 2)
						{
							cout << "So ngay cong: ";
							cin >> soNgayCong;
							dsNhanVien_2[i]->setSoNgayCong(soNgayCong);
						}
						else if (luaChon == 3)
						{
							cout << "Phu cap: ";
							cin >> phuCap;
							dsNhanVien_2[i]->setPhuCap(phuCap);
						}
						flag = true;
						dsNhanVien_2[i]->setTongLuong(dsNhanVien_2[i]->getLuongCB() * (static_cast<__int64>(dsNhanVien_2[i]->getSoNgayCong()) / 30) + dsNhanVien_2[i]->getPhuCap());
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
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					system("cls");
					break;
				}
			}
		}
	}
}

void BoPhanKeToan::TimKiem()
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
						cout << "\t========>>THONG TIN NHAN VIEN<<========" << endl;
						cout << "Ma NV: " << dsNhanVien_2[i]->getMaNV() << endl;
						cout << "Ten: " << dsNhanVien_2[i]->getTen() << endl;
						cout << "Luong co ban: " << formatCurrency(dsNhanVien_2[i]->getLuongCB()) << endl;
						cout << "So ngay cong: " << formatCurrency(dsNhanVien_2[i]->getSoNgayCong()) << endl;
						cout << "Phu cap: " << formatCurrency(dsNhanVien_2[i]->getPhuCap()) << endl;
						cout << "Tong luong: " << formatCurrency(dsNhanVien_2[i]->getTongLuong()) << endl;
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
					system("cls");
					break;
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
		cout << "\t\t1. Nhap luong nhan vien" << endl;
		cout << "\t\t2. Cap nhat luong nhan vien" << endl;
		cout << "\t\t3. Tim kiem" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->TinhLuong();
		}
		else if (luaChon == 2)
		{
			this->CapNhat();
		}
		else if (luaChon == 3)
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

string BoPhanKeToan::formatCurrency(long long val)
{
	string ans = "";

	string num = to_string(val);

	int count = 0;

	for (int i = num.size() - 1;
		i >= 0; i--) {
		count++;
		ans.push_back(num[i]);

		if (count == 3) {
			ans.push_back(',');
			count = 0;
		}
	}

	reverse(ans.begin(), ans.end());

	if (ans.size() % 4 == 0) {

		ans.erase(ans.begin());
	}

	return ans;
}
