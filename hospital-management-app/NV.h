#ifndef NV_HEADER
#define NV_HEADER

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class NV {
	protected:
		string MaNV, hoTen, SDT, diaChi;
		int chucVu;
		virtual void Nhap(istream& in) = 0;
		virtual void Xuat(ostream& out) = 0;
		NV** NhanVien = NULL;
	public:
		NV();
		NV(const NV& obj);
		friend istream& operator >> (istream& in,  NV& NV);
		friend ostream& operator << (ostream& out, NV& NV);
		~NV();
};

class BacSi : public NV {
private:
	double luongCB, phuCap;
	int soNgayCong;
public:
	BacSi();

	BacSi(const BacSi& obj);

	~BacSi();

	void Nhap(istream& in);
	void Xuat(ostream& out);

	double getLuong() {
		return this->luongCB;
	}

	double getPhuCap() {
		return this->phuCap;
	}

	int getSoNgayCong() {
		return this->soNgayCong;
	}
};

class TTDP : public NV {
private:
	double luongCB, phuCap;
	int soNgayCong;
public:
	TTDP();

	TTDP(const TTDP& obj);

	~TTDP();

	void Nhap(istream& in);
	void Xuat(ostream& out);
	double getLuong() {
		return this->luongCB;
	}

	double getPhuCap() {
		return this->phuCap;
	}

	int getSoNgayCong() {
		return this->soNgayCong;
	}
};

class TaiVu : public NV {
private:
	double luongCB, phuCap;
	int soNgayCong;
public:
	TaiVu();

	TaiVu(const TaiVu& obj);

	~TaiVu();

	void Nhap(istream& in);
	void Xuat(ostream& out);

	double getLuong() {
		return this->luongCB;
	}

	double getPhuCap() {
		return this->phuCap;
	}

	int getSoNgayCong() {
		return this->soNgayCong;
	}
};

class BanThuoc : public NV {
private:
	double luongCB, phuCap;
	int soNgayCong;
public:
	BanThuoc();

	BanThuoc(const BanThuoc& obj);

	~BanThuoc();

	void Nhap(istream& in);
	void Xuat(ostream& out);

	double getLuong() {
		return this->luongCB;
	}

	double getPhuCap() {
		return this->phuCap;
	}

	int getSoNgayCong() {
		return this->soNgayCong;
	}
};

class KeToan : public NV {
private:
	double luongCB, phuCap;
	int soNgayCong;
public:
	KeToan();

	KeToan(const KeToan& obj);

	~KeToan();

	void Nhap(istream& in);
	void Xuat(ostream& out);

	double getLuong() {
		return this->luongCB;
	}

	double getPhuCap() {
		return this->phuCap;
	}

	int getSoNgayCong() {
		return this->soNgayCong;
	}
};


#endif