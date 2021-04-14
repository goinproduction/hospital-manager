#ifndef QLNS_HEADER
#define QLNS_HEADER

#include "NV.h"
#include<iostream>
#include<string>
using namespace std;

class QLNS: public NV {
	public:
		QLNS();
		QLNS(const QLNS& obj);
		void Nhap(istream& in);
		void Xuat(ostream& out);
		void QLNSMenu();
		~QLNS();
};

#endif // !QLNS_HEADER