#include "NV.h"

NV::NV()
{
	this->MaNV = nullptr;
	this->hoTen = nullptr;
	this->SDT = nullptr;
	this->diaChi = nullptr;
	this->chucVu = nullptr;
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
