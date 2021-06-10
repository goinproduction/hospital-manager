#ifndef BACSI_H
#define BACSI_H
#include<iostream>
#include<string>
#include "App.h"
#include<vector>
#include<Windows.h>
using namespace std;

class BoPhanBacSi : public App {
private:
	vector<BN*> dsBenhNhan_2;
	vector<NV*> dsNhanVien_2;
public:
	BoPhanBacSi();
	~BoPhanBacSi();
	void setVectorValuesBN(vector<BN*>);
	void setVectorValuesNV(vector<NV*>);
	void HienThiThongTin(string);
	void DieuTri(string);
	void CapNhat(string);
	void TimKiem(string);
	void BPBSMenu();
	void DangNhap();
};
#endif // !BACSI_H

