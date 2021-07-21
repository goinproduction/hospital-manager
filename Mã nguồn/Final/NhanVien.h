#ifndef NV_header
#define NV_header

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class NV {
protected:
	string hoTen, SDT, diaChi, maNV;
	int chucVu, soNgayCong, khoaCongTac;
	__int64 luongCB, phuCap, tongLuong;
public:
	NV();
	NV(const NV& obj);

	virtual void Nhap();
	virtual void Xuat();

	string getTen();
	string getSDT();
	string getDiaChi();
	string getMaNV();

	void setMaNV(string ma);

	int getChucVu();
	void setChucVu(int cv);

	int getSoNgayCong();
	void setSoNgayCong(int);

	__int64 getLuongCB();
	void setLuongCB(__int64);

	__int64 getPhuCap();
	void setPhuCap(__int64);

	void setTongLuong(__int64);
	__int64 getTongLuong();

	int getKhoaCongTac();
	~NV();
};

class BacSi : public NV {
public:
	BacSi();
	BacSi(const BacSi& obj);
	~BacSi();

	void Nhap();
	void Xuat();
};

class TTDP : public NV {
public:
	TTDP();
	TTDP(const TTDP& obj);
	~TTDP();

	void Nhap();
	void Xuat();

};

class TaiVu : public NV {
public:
	TaiVu();
	TaiVu(const TaiVu& obj);
	~TaiVu();

	void Nhap();
	void Xuat();
};

class BanThuoc : public NV {
public:
	BanThuoc();
	BanThuoc(const BanThuoc& obj);
	~BanThuoc();

	void Nhap();
	void Xuat();
};

class KeToan : public NV {
public:
	KeToan();
	KeToan(const KeToan& obj);
	~KeToan();

	void Nhap();
	void Xuat();
};
#endif // !NV_header