#include "PatientManager.h"
#include<iostream>
#include<string>
using namespace std;

class App: public PatientManager{
public:
	void Menu() {
		int selection;
		cout << "\t\t==============>>MENU<<=============" << endl;
		cout << "\t\t1. THONG TIN BENH NHAN" << endl;
		cout << "\t\t2. KHAM BENH" << endl;
		cout << "\t\t3.	THANH TOAN" << endl;
		cout << "\t\t4. TIM KIEM" << endl;
		cout << "\t\t5. THOAT" << endl;
	}
};