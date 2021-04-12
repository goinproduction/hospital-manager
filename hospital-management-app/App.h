#ifndef APP_HEADER
#define APP_HEADER

#include "QLNS.h"
#include<iostream>
#include<string>
using namespace std;

class App{
public:
	void Menu() {
		while (1) {
			int luaChon;
			cout << "\t=======>> QUAN LY BENH VIEN <<=======" << endl;
			cout << "\t\t5. Bo phan Ke toan" << endl;
			cout << "\t\t0. Ket thuc chuong trinh" << endl;
			cout << "\t\tNhap lua chon: ";
			cin >> luaChon;
			if (luaChon == 5)
			{
				system("cls");
				QLNS qlns;
				qlns.QLNSMenu();
			}
			else if (luaChon == 0)
			{
				getchar();
			}
		}
	}
};
#endif // !APP_HEADER