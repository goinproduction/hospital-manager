#ifndef BN_H
#define BN_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class BN {
protected:
	string maKhamBenh, hoTen, diaChi, trieuChung, bhyt, chanDoan, phongKham, maGiuongBenh, ngayBD, ngayKT, bacSiDieuTri;
	int tuoi, soDienThoai, chieuCao, canNang, mach, huyetAp, doiTuong, soThuTu, gioiTinh, khoaDieuTri, soNgayDieuTri, tinhTrangRaVien, loaiGiuong;
	float nhietDo;
	vector<pair<int, int>> phuongThucDieuTri;
	long double tongVienPhi;
public:
	BN();
	~BN();

	virtual void Nhap();
	virtual void Xuat();

	void setPhuongThucDieuTri(vector<pair<int, int>>);
	vector<pair<int, int>> getPhuongThucDieuTri();

	void setMaKhamBenh(string);
	string getMaKhamBenh();

	void setTrieuChung(string);
	string getTrieuChung();

	int getLoaiGiuong();

	string getHoTen();
	int getGioiTinh();
	string getDiaChi();
	string getBHYT();

	int getDoiTuong();
	int getTuoi();
	int getSDT();

	void setPhongKham(string);
	string getPhongKham();

	int getChieuCao();
	void setChieuCao(int);

	int getCanNang();
	void setCanNang(int);

	float getNhietDo();
	void setNhietDo(float);

	int getMach();
	void setMach(int);

	int getHuyetAp();
	void setHuyetAp(int);

	int getSoThuTu();
	void setSoThuTu(int);

	void setBacSiDieuTri(string);
	string getBacSiDieuTri();

	void setMaGiuongBenh(string);
	string getMaGiuongBenh();

	void setNgayBD(string);
	string getNgayBD();

	void setNgayKT(string);
	string getNgayKT();

	void setSoNgayDieuTri(int);
	int getSoNgayDieuTri();

	void setTinhTrangRaVien(int);
	int getTinhTrangRaVien();

	void setChanDoan(string);
	string getChanDoan();

	void setTongVienPhi(long double);
	long double getTongVienPhi();

};

class BenhNhanNoiTru : public BN {
public:
	BenhNhanNoiTru();
	~BenhNhanNoiTru();

	void Nhap();
	void Xuat();
};

class BenhNhanNgoaiTru : public BN {
public:
	BenhNhanNgoaiTru();
	~BenhNhanNgoaiTru();

	void Nhap();
	void Xuat();

};
#endif // !BN_H
