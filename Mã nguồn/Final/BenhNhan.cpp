#include "BenhNhan.h"

BN::BN()
{
	this->maGiuongBenh = "";
}

BN::~BN()
{
}

void BN::Nhap()
{
	cout << "Ten benh nhan: ";
	getline(cin, hoTen);
	cout << "Tuoi: ";
	cin >> tuoi;
	cin.ignore();
	cout << "Gioi tinh(1. Nam; 0. Nu): ";
	cin >> gioiTinh;
	cin.ignore();
	cout << "Dia chi: ";
	getline(cin, diaChi);
	cout << "So dien thoai: ";
	cin >> soDienThoai;
	cin.ignore();
	cout << "Doi tuong (0. BHYT 0%; 1. BHYT 80%; 2. BHYT 85%; 3. BHYT 90%): ";
	cin >> doiTuong;
	cin.ignore();
	if (this->doiTuong == 0)
	{
		bhyt = "";
	}
	else {
		cout << "Ma the BHYT: ";
		getline(cin, bhyt);
	}
}

void BN::Xuat()
{
	cout << "Ma kham benh: " << this->maKhamBenh << endl;
	cout << "Ten benh nhan: " << this->hoTen << "\t\t\tTuoi: " << this->tuoi << "\t\tGioi tinh: " << this->gioiTinh << endl;
	cout << "Dia chi: " << this->diaChi << endl;
	cout << "So dien thoai: " << this->soDienThoai << endl;
	switch (this->doiTuong)
	{
	case 0:
		cout << "Doi tuong: BHYT 0%" << endl;
		break;
	case 1:
		cout << "Doi tuong: BHYT 80%" << endl;
		break;
	case 2:
		cout << "Doi tuong: BHYT 85%" << endl;
		break;
	case 3:
		cout << "Doi tuong: BHYT 90%" << endl;
		break;
	default:
		break;
	}
	cout << "Ma the BHYT: " << this->bhyt << endl;
	cout << "Trieu chung: " << this->trieuChung << endl;
	cout << "Bac si dieu tri: " << this->bacSiDieuTri << endl;
}

void BN::setPhuongThucDieuTri(vector<pair<int, int>> val)
{
	this->phuongThucDieuTri = val;
}

vector<pair<int, int>> BN::getPhuongThucDieuTri()
{
	return this->phuongThucDieuTri;
}

void BN::setMaKhamBenh(string val)
{
	this->maKhamBenh = val;
}

string BN::getMaKhamBenh()
{
	return this->maKhamBenh;
}

void BN::setTrieuChung(string val)
{
	this->trieuChung = val;
}

string BN::getTrieuChung()
{
	return this->trieuChung;
}

int BN::getLoaiGiuong()
{
	return this->loaiGiuong;
}

string BN::getBHYT()
{
	return this->bhyt;
}

int BN::getDoiTuong()
{
	return this->doiTuong;
}

int BN::getTuoi()
{
	return this->tuoi;
}

int BN::getSDT()
{
	return this->soDienThoai;
}

void BN::setPhongKham(string val)
{
	this->phongKham = val;
}

string BN::getPhongKham()
{
	return this->phongKham;
}

int BN::getChieuCao()
{
	return this->chieuCao;
}

void BN::setChieuCao(int val)
{
	this->chieuCao = val;
}

int BN::getCanNang()
{
	return this->canNang;
}

void BN::setCanNang(int val)
{
	this->canNang = val;
}

float BN::getNhietDo()
{
	return this->nhietDo;
}

void BN::setNhietDo(float val)
{
	this->nhietDo = val;
}

int BN::getMach()
{
	return this->mach;
}

void BN::setMach(int val)
{
	this->mach = val;
}

int BN::getHuyetAp()
{
	return this->huyetAp;
}

void BN::setHuyetAp(int val)
{
	this->huyetAp = val;
}

int BN::getSoThuTu()
{
	return this->soThuTu;
}

void BN::setSoThuTu(int val)
{
	this->soThuTu = val;
}

void BN::setBacSiDieuTri(string val)
{
	this->bacSiDieuTri = val;
}

string BN::getBacSiDieuTri()
{
	return this->bacSiDieuTri;
}

void BN::setMaGiuongBenh(string val)
{
	this->maGiuongBenh = val;
}

string BN::getMaGiuongBenh()
{
	return this->maGiuongBenh;
}

string BN::getNgayBD()
{
	return this->ngayBD;
}

void BN::setNgayKT(string val)
{
	this->ngayKT = val;
}

string BN::getNgayKT()
{
	return this->ngayKT;
}

void BN::setSoNgayDieuTri(int val)
{
	this->soNgayDieuTri = val;
}

int BN::getSoNgayDieuTri()
{
	return this->soNgayDieuTri;
}

void BN::setTinhTrangRaVien(int val)
{
	this->tinhTrangRaVien = val;
}

int BN::getTinhTrangRaVien()
{
	return this->tinhTrangRaVien;
}

void BN::setChanDoan(string val)
{
	this->chanDoan = val;
}

string BN::getChanDoan()
{
	return this->chanDoan;
}

void BN::setTongVienPhi(long double val)
{
	this->tongVienPhi = val;
}

long double BN::getTongVienPhi()
{
	return this->tongVienPhi;
}

string BN::getHoTen()
{
	return this->hoTen;
}

int BN::getGioiTinh()
{
	return this->gioiTinh;
}

string BN::getDiaChi()
{
	return this->diaChi;
}

BenhNhanNoiTru::BenhNhanNoiTru()
{
	this->ngayKT = "";
}

BenhNhanNoiTru::~BenhNhanNoiTru()
{
}

void BenhNhanNoiTru::Nhap()
{
	BN::Nhap();
	cout << "Ma giuong benh: ";
	getline(cin, maGiuongBenh);
	cout << "Loai giuong (1; 2; 3): ";
	cin >> this->loaiGiuong;
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1;
	int year = aTime->tm_year + 1900;
	
	this->ngayBD = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void BenhNhanNoiTru::Xuat()
{
	BN::Xuat();
	cout << "Ma giuong benh: " << this->maGiuongBenh << endl;
	cout << "Ngay bat dau dieu tri: " << this->ngayBD << endl;
}


BenhNhanNgoaiTru::BenhNhanNgoaiTru()
{
}

BenhNhanNgoaiTru::~BenhNhanNgoaiTru()
{
}

void BenhNhanNgoaiTru::Nhap()
{
	BN::Nhap();
}

void BenhNhanNgoaiTru::Xuat()
{
	BN::Xuat();
}
