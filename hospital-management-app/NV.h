#include<iostream>
#include<vector>
#include<string>
using namespace std;

class NV {
	protected:
		string MaNV, hoTen, SDT, diaChi;
		virtual void Nhap(istream& in) = 0;
		virtual void Xuat(ostream& out) const = 0;
	public:
		NV();
		NV(const NV& obj);
		friend istream& operator >> (istream& in, NV& NV);
		friend ostream& operator << (ostream& out, const NV& NV);
		~NV();
};

class BacSi : public NV {
	private:
		double luongCB, phuCap;
		int soNgayCong, chucVu;
	public:
		BacSi();
		BacSi(const BacSi& obj);
		~BacSi();
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
		int soNgayCong, chucVu;
	public:
		TTDP();
		TTDP(const TTDP& obj);
		~TTDP();
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
		int soNgayCong, chucVu;
	public:
		TaiVu();
		TaiVu(const TaiVu& obj);
		~TaiVu();
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
		int soNgayCong, chucVu;
	public:
		BanThuoc();
		BanThuoc(const BanThuoc& obj);
		~BanThuoc();
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
		int soNgayCong, chucVu;
	public:
		KeToan();
		KeToan(const KeToan& obj);
		~KeToan();
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

