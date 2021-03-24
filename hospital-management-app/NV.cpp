#include "NV.h"

NV::NV()
{
	this->MaNV = nullptr;
	this->hoTen = nullptr;
	this->SDT = nullptr;
	this->diaChi = nullptr;
	this->chucVu = NULL;
}

NV::NV(const NV& obj)
{
	MaNV = obj.MaNV;
	hoTen = obj.hoTen;
	SDT = obj.SDT;
	diaChi = obj.diaChi;
	chucVu = obj.chucVu;
}

NV::~NV()
{
}

istream& operator>>(istream& in, NV& NV)
{
	// TODO: insert return statement here
	fflush(stdin);
	cout << "MaNV: ";
	getline(in, NV.MaNV);
	cout << "Ten: ";
	getline(in, NV.hoTen);
	cout << "SDT: ";
	getline(in, NV.SDT);
	cout << "Dia Chi: ";
	getline(in, NV.diaChi);
	do
	{
		cout << "Chuc vu(0: Bac si, 1: Dieu phoi, 2: Tai vu, 3: Ban thuoc, 4: Ke toan): ";
		cin >> NV.chucVu;
	} while (NV.chucVu > 4 || NV.chucVu < 0);
	NV.Nhap(in);
	return in;
}

ostream& operator<<(ostream& out, const NV& NV)
{
	// TODO: insert return statement here
	fflush(stdin);
	out << "Ma NV: " << NV.MaNV << endl;
	out << "Ten: " << NV.hoTen << endl;
	out << "SDT: " << NV.SDT << endl;
	out << "Dia Chi: " << NV.diaChi << endl;
	switch (NV.chucVu)
	{
	case 0:
		out << "Chuc Vu: Bac si" << endl;
		break;
	case 1:
		out << "Chuc Vu: Dieu phoi" << endl;
		break;
	case 2:
		out << "Chuc Vu: Tai vu" << endl;
		break;
	case 3:
		out << "Chuc Vu: Ban thuoc" << endl;
		break;
	case 4:
		out << "Chuc Vu: Ke toan" << endl;
		break;
	default:
		break;
	}
	NV.Xuat(out);
	return out;
}

BacSi::BacSi()
{
	this->luongCB = NULL;
	this->phuCap = NULL;
	this->soNgayCong = NULL;
}

BacSi::BacSi(const BacSi& obj)
{
}

BacSi::~BacSi()
{
}

void BacSi::Nhap(istream& in)
{
	cout << "Luong CB: ";
	in >> this->luongCB;
	cout << "So ngay cong: ";
	in >> this->soNgayCong;
	cout << "Phu cap: ";
	in >> this->phuCap;
}

TTDP::TTDP()
{
	this->luongCB = NULL;
	this->phuCap = NULL;
	this->soNgayCong = NULL;
}

TTDP::TTDP(const TTDP& obj)
{
	this->luongCB = obj.luongCB;
	this->phuCap = obj.phuCap;
	this->soNgayCong = obj.soNgayCong;
}

TTDP::~TTDP()
{
}

void TTDP::Nhap(istream& in)
{
	cout << "Luong CB: ";
	in >> this->luongCB;
	cout << "So ngay cong: ";
	in >> this->soNgayCong;
	cout << "Phu cap: ";
	in >> this->phuCap;
}

TaiVu::TaiVu()
{
	this->luongCB = NULL;
	this->phuCap = NULL;
	this->soNgayCong = NULL;
}

TaiVu::TaiVu(const TaiVu& obj)
{
	this->luongCB = obj.luongCB;
	this->phuCap = obj.phuCap;
	this->soNgayCong = obj.soNgayCong;
}

TaiVu::~TaiVu()
{
}

void TaiVu::Nhap(istream& in)
{
	cout << "Luong CB: ";
	in >> this->luongCB;
	cout << "So ngay cong: ";
	in >> this->soNgayCong;
	cout << "Phu cap: ";
	in >> this->phuCap;
}

BanThuoc::BanThuoc()
{
	this->luongCB = NULL;
	this->phuCap = NULL;
	this->soNgayCong = NULL;
}

BanThuoc::BanThuoc(const BanThuoc& obj)
{
	this->luongCB = obj.luongCB;
	this->phuCap = obj.phuCap;
	this->soNgayCong = obj.soNgayCong;
}

BanThuoc::~BanThuoc()
{
}

void BanThuoc::Nhap(istream& in)
{
	cout << "Luong CB: ";
	in >> this->luongCB;
	cout << "So ngay cong: ";
	in >> this->soNgayCong;
	cout << "Phu cap: ";
	in >> this->phuCap;
}

KeToan::KeToan()
{
	this->luongCB = NULL;
	this->phuCap = NULL;
	this->soNgayCong = NULL;
}

KeToan::KeToan(const KeToan& obj)
{
	this->luongCB = obj.luongCB;
	this->phuCap = obj.phuCap;
	this->soNgayCong = obj.soNgayCong;
}

KeToan::~KeToan()
{
}

void KeToan::Nhap(istream& in)
{
	cout << "Luong CB: ";
	in >> this->luongCB;
	cout << "So ngay cong: ";
	in >> this->soNgayCong;
	cout << "Phu cap: ";
	in >> this->phuCap;
}
