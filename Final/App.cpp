#include "App.h"
#include "BoPhanQuanLy.h"
#include "NhanVienKeToan.h"

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
			//polymorphism
			BoPhanQuanLy qlns;
			App* app = &qlns;
			app->BPQLMenu();

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
		else if (luaChon == 5)
		{

		}
		else if (luaChon == 6)
		{
			BoPhanKeToan bpkt;
			App* app = &bpkt;
			app->BPKTMenu();
		}
		else if (luaChon == 0)
		{
			break;
		}
	}
}

int main() {
	App* app = new App;
	app->Menu();
	system("pause");
	return 0;
}