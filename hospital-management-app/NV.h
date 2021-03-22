#include<iostream>
#include<string>
using namespace std;

class NV {
	protected:
		string MaNV, hoTen, SDT, diaChi, chucVu;
	public:
		NV();
		virtual void nhapTTNV() = 0;
		virtual void xuatTTNV() = 0;
		NV(const NV& obj);
		~NV();
};