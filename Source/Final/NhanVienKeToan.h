#ifndef BPKT_H
#define BPKT_H
#include "App.h"
#include<vector>
#include<iostream>
using namespace std;
class BoPhanKeToan : public App {
private:
	vector<NV*> dsNhanVien_2;
	vector<BN*> dsBenhNhan_2;
public:
	BoPhanKeToan();
	~BoPhanKeToan();
	void setVectorValuesNV(vector<NV*>);
	void setVectorValuesBN(vector<BN*>);
	void TinhLuong();
	void CapNhat();
	void TimKiem();
	void BPKTMenu();
	string formatCurrency(long long);
};

#endif // !BPKT

