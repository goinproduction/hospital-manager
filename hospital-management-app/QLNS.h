#include "NV.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class QLNS: public NV {
	private:
		vector<NV*> nhanVienArr;
	public:
		QLNS();
		QLNS(const QLNS& obj);
		~QLNS();
};