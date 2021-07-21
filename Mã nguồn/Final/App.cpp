#include "App.h"
#include "BoPhanQuanLy.h"
#include "NhanVienKeToan.h"
#include "BoPhanTiepTan.h"
#include "BoPhanBacSi.h"
#include "BoPhanTaiVu.h"
#include "BoPhanBanThuoc.h"

App::App()
{
}

App::~App()
{
}

void App::setVectorValueNV(vector<NV*> val)
{
	this->dsNhanVien.swap(val);
}

void App::setVectorValueBN(vector<BN*> val)
{
	this->dsBenhNhan.swap(val);
}

void App::Menu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>CHUONG TRINH QUAN LY BENH VIEN<<========" << endl;
		cout << "\n\tVai tro: " << endl;
		cout << "\t\t1. Bo phan Quan ly nhan su " << endl;
		cout << "\t\t2. Bo phan Tiep tan va Dieu phoi benh" << endl;
		cout << "\t\t3. Phong Tai vu" << endl;
		cout << "\t\t4. Bac si dieu tri" << endl;
		cout << "\t\t5. Bo phan Ban thuoc" << endl;
		cout << "\t\t6. Bo phan Ke toan" << endl;
		cout << "\t\t0. Ket thuc" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			BoPhanQuanLy* bpql = new BoPhanQuanLy;
			bpql->setVectorValuesNV(dsNhanVien);
			bpql->setVectorValuesBN(dsBenhNhan);
			bpql->BPQLMenu();
		}
		else if (luaChon == 2)
		{
			BoPhanTiepTan* bptt = new BoPhanTiepTan;
			bptt->setVectorValuesBN(dsBenhNhan);
			bptt->setVectorValuesNV(dsNhanVien);
			bptt->BPTTMenu();
		}
		else if (luaChon == 3)
		{
			BoPhanTaiVu* bptv = new BoPhanTaiVu;
			bptv->setVectorValuesBN(dsBenhNhan);
			bptv->setVectorValuesNV(dsNhanVien);
			bptv->BPTVMenu();
		}
		else if (luaChon == 4)
		{
			BoPhanBacSi* bpbs = new BoPhanBacSi;
			bpbs->setVectorValuesBN(dsBenhNhan);
			bpbs->setVectorValuesNV(dsNhanVien);
			bpbs->BPBSMenu();
		}
		else if (luaChon == 5)
		{
			BoPhanBanThuoc* bpbt = new BoPhanBanThuoc;
			bpbt->setVectorValuesBN(dsBenhNhan);
			bpbt->setVectorValuesNV(dsNhanVien);
			bpbt->BPBTMenu();
		}
		else if (luaChon == 6)
		{
			BoPhanKeToan* bpkt = new BoPhanKeToan;
			bpkt->setVectorValuesNV(dsNhanVien);
			bpkt->setVectorValuesBN(dsBenhNhan);
			bpkt->BPKTMenu();
		}
		else if (luaChon == 0)
		{
			exit(1);
		}
	}
}

int main() {
	App* app = new App;
	app->Menu();
	system("pause");
	return 0;
}