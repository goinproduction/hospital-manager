#ifndef TIEPTAN_H
#define TIEPTAN_H
#define _CRT_SECURE_NO_WARNINGS
#include "App.h"
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<chrono>
using namespace std;

class BoPhanTiepTan: public App {
private:
	vector<BN*> dsBenhNhan_2;
	vector<NV*> dsNhanVien_2;
public:
	void setVectorValuesBN(vector<BN*>);
	void setVectorValuesNV(vector<NV*>);
	void Nhap();
	void Xuat();
	void XuatPhieuKham();
	void CapNhat();
	void Xoa();
	void TimKiem();
	void BPTTMenu();
};
#endif // !TIEPTAN_H

