#ifndef APP_H
#define APP_H
#include "NhanVien.h"
#include<iostream>
#include<string>
#include<vector>
#include<string>
using namespace std;
class QuanLyNhanSu;
class App {
public:
	App() {}
	~App() {}
	virtual void BPQLMenu(){}
	virtual void BPKTMenu(){}
	void Menu();
};

#endif // !APP_H