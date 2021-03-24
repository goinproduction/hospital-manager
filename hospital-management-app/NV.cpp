#include "NV.h"

NV::NV()
{
	this->MaNV = nullptr;
	this->hoTen = nullptr;
	this->SDT = nullptr;
	this->diaChi = nullptr;
	this->luongCB = NULL;
	this->phuCap = NULL;
	this->soNgayCong = NULL;
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
}

BacSi::BacSi(const BacSi& obj)
{
}

BacSi::~BacSi()
{
}

TTDP::TTDP()
{
}

TTDP::TTDP(const TTDP& obj)
{
}

TTDP::~TTDP()
{
}

TaiVu::TaiVu()
{
}

TaiVu::TaiVu(const TaiVu& obj)
{
}

TaiVu::~TaiVu()
{
}

BanThuoc::BanThuoc()
{
}

BanThuoc::BanThuoc(const BanThuoc& obj)
{
}

BanThuoc::~BanThuoc()
{
}

KeToan::KeToan()
{
}

KeToan::KeToan(const KeToan& obj)
{
}

KeToan::~KeToan()
{
}
