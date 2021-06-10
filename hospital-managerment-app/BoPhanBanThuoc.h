#ifndef BANTHUOC_H
#define BANTHUOC_H
#include "App.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class BoPhanBanThuoc : public App {
private:
	vector<BN* >dsBenhNhan_2;
	vector<NV*> dsNhanVien_2;
public:
	BoPhanBanThuoc();
	~BoPhanBanThuoc();
	void setVectorValuesBN(vector<BN*>);
	void setVectorValuesNV(vector<NV*>);
	void HienThiDonThuoc();
	void XuatHoaDon();
	string formatCurrency(long long);
	void BPBTMenu();
};
#endif // !BANTHUOC_H
