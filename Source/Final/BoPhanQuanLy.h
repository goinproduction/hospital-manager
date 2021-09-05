#ifndef QLNS_H
#define QLNS_H
#include "App.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BoPhanQuanLy: public App{
private:
	vector<NV*> dsNhanVien_2;
	vector<BN*> dsBenhNhan_2;
public:
	BoPhanQuanLy();
	~BoPhanQuanLy();
	void setVectorValuesNV(vector<NV*>);
	void setVectorValuesBN(vector<BN*>);
	void Nhap();
	void Xuat();
	void CapNhat();
	void Xoa();
	void TimKiem();
	void BPQLMenu();
};

#endif // !QLNS

