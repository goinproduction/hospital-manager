#ifndef APP_H
#define APP_H
#include "BenhNhan.h"
#include "NhanVien.h"
#include<iostream>
#include<string>
#include<vector>
#include<vector>
using namespace std;

class App{
protected:
	vector<NV*> dsNhanVien;
	vector<BN*> dsBenhNhan;
public:
	App();
	~App();
	void setVectorValueNV(vector<NV*>);
	void setVectorValueBN(vector<BN*>);
	void Menu();
};

#endif // !APP_H

