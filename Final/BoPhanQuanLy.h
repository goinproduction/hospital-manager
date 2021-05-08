#ifndef QLNS_H
#define QLNS_H
#include "NhanVien.h"
#include<vector>
#include<iostream>
#include "App.h"
using namespace std;
class BoPhanQuanLy: public App{
protected:
	vector<NV*> dsNhanVien;
public:
	BoPhanQuanLy();
	~BoPhanQuanLy();
	void Nhap();
	void Xuat();
	void CapNhat();
	void Xoa();
	void TimKiem();
	void BPQLMenu();
};

#endif // !QLNS
