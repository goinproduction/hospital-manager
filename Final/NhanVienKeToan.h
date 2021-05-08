#ifndef BPKT_H
#define BPKT_H

#include "BoPhanQuanLy.h"
#include<vector>
#include<iostream>
using namespace std;
class App;
class BoPhanKeToan : public BoPhanQuanLy, public App {
public:
	BoPhanKeToan();
	~BoPhanKeToan();
	void TinhLuong();
	void Xuat();
	void CapNhat();
	void TimKiem();
	void BPKTMenu();
};

#endif // !BPKT