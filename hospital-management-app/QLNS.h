#include "NV.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class QLNS : NV, BacSi, TTDP, TaiVu, BanThuoc, KeToan {
	public:
		QLNS();
		QLNS(const QLNS& obj);
		void Nhap(istream& in);
		void Xuat(ostream& out);
		~QLNS();
};