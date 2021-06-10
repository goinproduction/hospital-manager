#ifndef TAIVU_H
#define TAIVU_H
#include "App.h"
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
class BoPhanTaiVu : public App {
private:
	vector<NV*> dsNhanVien_2;
	vector<BN*> dsBenhNhan_2;
public:
	BoPhanTaiVu();
	~BoPhanTaiVu();
	void setVectorValuesBN(vector<BN*>);
	void setVectorValuesNV(vector<NV*>);
	void Nhap();
	void TinhVienPhi();
	void TimKiem();
	void XuatHoaDon();
	void BPTVMenu();
	string formatCurrency(long long);
};
#endif // !TAIVU_H


