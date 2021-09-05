#include "BoPhanTaiVu.h"
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)

BoPhanTaiVu::BoPhanTaiVu()
{
}

BoPhanTaiVu::~BoPhanTaiVu()
{
}

void BoPhanTaiVu::setVectorValuesBN(vector<BN*> val)
{
	this->dsBenhNhan_2.swap(val);
}

void BoPhanTaiVu::setVectorValuesNV(vector<NV*> val) 
{
	this->dsNhanVien_2.swap(val);
}

void BoPhanTaiVu::Nhap()
{
	while (1)
	{
		string maKhamBenh;
		bool flag;
		do
		{
			cin.ignore();
			cout << "Ma kham benh: ";
			getline(cin, maKhamBenh);
			size_t size = dsBenhNhan_2.size();
			flag = false;
			for (int i = 0; i < size; i++)
			{
				if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh)
				{
					// Kiểm tra xem bệnh nhân thuộc đối tượng nội trú hay ngoại trú
					if (dsBenhNhan_2[i]->getMaGiuongBenh() != "")
					{
						flag = true;
						// Nội trú
						string ngayKT;
						int soNgayDieuTri, tinhTrangRaVien;
						cout << "Ngay ket thuc dieu tri (dd/mm//yyyy): ";
						getline(cin, ngayKT);
						fflush(stdin);
						cout << "So ngay dieu tri: ";
						cin >> soNgayDieuTri;
						cout << "Tinh trang ra vien (1; 2; 3): ";
						cin >> tinhTrangRaVien;
						dsBenhNhan_2[i]->setNgayKT(ngayKT);
						dsBenhNhan_2[i]->setSoNgayDieuTri(soNgayDieuTri);
						dsBenhNhan_2[i]->setTinhTrangRaVien(tinhTrangRaVien);
					}
					break;
				}
			}
			if (flag == false)
			{
				cout << "Co loi xay ra, vui long kiem tra lai!";
				break;
			}
		} while (flag == false);
		if (flag)
		{
			int luaChon;
			cout << "\nBan co muon tiep tuc nhap thong tin cho benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
			cin >> luaChon;
			if (luaChon == 1)
			{
				system("cls");
				continue;
			}
			else if (luaChon == 0)
			{
				break;
				system("cls");
			}
		}
	}
}

void BoPhanTaiVu::TinhVienPhi()
{
	while (1)
	{
		string maKhamBenh;
		bool flag;
		do
		{
			cin.ignore();
			cout << "Ma kham benh: ";
			getline(cin, maKhamBenh);
			size_t size = dsBenhNhan_2.size();
			flag = false;
			for (int i = 0; i < size; i++)
			{
				if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh)
				{
					flag = true;
					// Kiểm tra xem bệnh nhân thuộc đối tượng nội trú hay ngoại trú
					if (dsBenhNhan_2[i]->getMaGiuongBenh() != "")
					{
						// Nội trú
						double tongVienPhi = 60000;
						vector<pair<int, int>> buff = dsBenhNhan_2[i]->getPhuongThucDieuTri();
						size_t size = buff.size();
						int loaiGiuong = dsBenhNhan_2[i]->getLoaiGiuong();
						int soNgayDieuTri = dsBenhNhan_2[i]->getSoNgayDieuTri();
						if (loaiGiuong == 1)
						{
							tongVienPhi += static_cast<double>(soNgayDieuTri) * 200000;
						}
						else if (loaiGiuong == 2)
						{
							tongVienPhi += static_cast<double>(soNgayDieuTri) * 160000;
						}
						else if (loaiGiuong == 3)
						{
							tongVienPhi += static_cast<double>(soNgayDieuTri) * 120000;
						}
						for (size_t i = 0; i < size; i++)
						{
							if (buff[i].first == 1)
							{
								tongVienPhi += 46200 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 2)
							{
								tongVienPhi += 80000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 3)
							{
								tongVienPhi += 29000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 4)
							{
								tongVienPhi += 65400 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 5)
							{
								tongVienPhi += 522000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 6)
							{
								tongVienPhi += 65400 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 7)
							{
								tongVienPhi += 43900 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 8)
							{
								tongVienPhi += 1700000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 9)
							{
								tongVienPhi += 6000000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 10)
							{
								tongVienPhi += 2288 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 11)
							{
								tongVienPhi += 228400 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 12)
							{
								tongVienPhi += 15575 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 13)
							{
								tongVienPhi += 17575 * static_cast<double>(buff[i].second);
							}
						}
						int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
						if (doiTuong == 0)
						{
							tongVienPhi = tongVienPhi * 1.0;
						}
						else if (doiTuong == 1)
						{
							tongVienPhi = tongVienPhi * 0.2;
						}
						else if (doiTuong == 2)
						{
							tongVienPhi = tongVienPhi * 0.15;
						}
						else if (doiTuong == 3)
						{
							tongVienPhi = tongVienPhi * 0.1;
						}
						dsBenhNhan_2[i]->setTongVienPhi(tongVienPhi);
						cout << "Tinh vien phi thanh cong!" << endl;
						break;
					}
					else
					{
						// Ngoại trú
						double tongVienPhi = 60000;
						vector<pair<int, int>> buff = dsBenhNhan_2[i]->getPhuongThucDieuTri();
						size_t size = buff.size();
						for (size_t i = 0; i < size; i++)
						{
							if (buff[i].first == 1)
							{
								tongVienPhi += 46200 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 2)
							{
								tongVienPhi += 80000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 3)
							{
								tongVienPhi += 29000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 4)
							{
								tongVienPhi += 65400 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 5)
							{
								tongVienPhi += 522000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 6)
							{
								tongVienPhi += 65400 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 7)
							{
								tongVienPhi += 43900 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 8)
							{
								tongVienPhi += 1700000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 9)
							{
								tongVienPhi += 6000000 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 10)
							{
								tongVienPhi += 2288 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 11)
							{
								tongVienPhi += 228400 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 12)
							{
								tongVienPhi += 61900 * static_cast<double>(buff[i].second);
							}
							else if (buff[i].first == 13)
							{
								tongVienPhi += 17575 * static_cast<double>(buff[i].second);
							}
						}
						int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
						if (doiTuong == 0)
						{
							tongVienPhi = tongVienPhi * 1.0;
						}
						else if (doiTuong == 1)
						{
							tongVienPhi = tongVienPhi * 0.2;
						}
						else if (doiTuong == 2)
						{
							tongVienPhi = tongVienPhi * 0.15;
						}
						else if (doiTuong == 3)
						{
							tongVienPhi = tongVienPhi * 0.1;
						}
						dsBenhNhan_2[i]->setTongVienPhi(tongVienPhi);
						cout << "Tinh vien phi thanh cong!" << endl;
						break;
					}
				}
			}
			if (flag == false)
			{
				cout << "Benh nhan chua ton tai trong he thong!";
				break;
			}
		} while (flag == false);
		if (flag)
		{
			int luaChon;
			cout << "\nBan co muon tiep tuc nhap thong tin cho benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
			cin >> luaChon;
			if (luaChon == 1)
			{
				system("cls");
				continue;
			}
			else if (luaChon == 0)
			{
				break;
				system("cls");
			}
		}
	}
}

void BoPhanTaiVu::TimKiem()
{
	system("cls");
	cout << "========>>CHI PHI KHAM, CHUA BENH<<========" << endl;
	size_t size = dsBenhNhan_2.size();
	if (size == 0)
	{
		cout << "Danh sach benh nhan rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		bool flag;
		string maKhamBenh;
		while (1) {
			do
			{
				fflush(stdin);
				cin.ignore();
				cout << "Ma kham benh: ";
				getline(cin, maKhamBenh);
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh)
					{
						flag = true;
						cout << "Noi dung\t\t\t\tSo luong\tThanh tien BV\t\tThanh tien BH\t\tThanh tien" << endl;
						if (dsBenhNhan_2[i]->getMaGiuongBenh() != "")
						{
							// Nội trú
							int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
							if (doiTuong == 0)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t0\t\t\t60,000" << endl;
								cout << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									cout << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t0\t\t\t" << formatCurrency(tienGiuongBenh) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									cout << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t0\t\t\t" << formatCurrency(tienGiuongBenh) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									cout << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t0\t\t\t" << formatCurrency(tienGiuongBenh) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
							else if (doiTuong == 1)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t48,000\t\t\t12,000" << endl;
								cout << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									cout << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t"<< formatCurrency(round(tienGiuongBenh * 0.8)) <<"\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.8)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									cout << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.8)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.8)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									cout << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.8)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.8)) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
							else if (doiTuong == 2)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t51,000\t\t\t9,000" << endl;
								cout << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									cout << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t"<< formatCurrency(round(tienGiuongBenh * 0.85)) <<"\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.85)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									cout << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.85)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.85)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									cout << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.85)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.85)) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
							else if (doiTuong == 3)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t54,000\t\t\t6,000" << endl;
								cout << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									cout << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t"<< formatCurrency(round(tienGiuongBenh * 0.9)) <<"\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.9)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									cout << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.9)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.9)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									cout << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.9)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.9)) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
						}
						else
						{
							// Ngoại trú
							vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
							size_t size = buffer.size();
							int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
							if (doiTuong == 0)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t0\t\t\t60,000" << endl;
								cout << "\n2. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								cout << "\n3. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								cout << "\n4. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								cout << "\n5. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
							else if (doiTuong == 1)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t48,000\t\t\t12,000" << endl;
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
							else if (doiTuong == 2)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t51,000\t\t\t9,000" << endl;
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
							else if (doiTuong == 3)
							{
								cout << "1. Kham benh" << endl;
								cout << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t54,000\t\t\t6,000" << endl;
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								cout << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										cout << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										cout << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										cout << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								cout << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										cout << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										cout << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										cout << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										cout << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								cout << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										cout << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										cout << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								cout << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
							}
						}
						break;
					}
					else
					{
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ma kham benh khong ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc tim benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
				}
			}
		}
	}
}

void BoPhanTaiVu::XuatHoaDon()
{
	system("cls");
	cout << "========>>CHI PHI KHAM, CHUA BENH<<========" << endl;
	size_t size = dsBenhNhan_2.size();
	if (size == 0)
	{
		cout << "Danh sach benh nhan rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		bool flag;
		string maKhamBenh;
		while (1) {
			do
			{
				fflush(stdin);
				cin.ignore();
				cout << "Ma kham benh: ";
				getline(cin, maKhamBenh);
				flag = true;
				for (int i = 0; i < size; i++)
				{
					if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh)
					{
						flag = true;
						string nameBeforeConvertToUpper = dsBenhNhan_2[i]->getHoTen();
						transform(nameBeforeConvertToUpper.begin(), nameBeforeConvertToUpper.end(), nameBeforeConvertToUpper.begin(), ::toupper);

						string file_out_path = "HOADONVIENPHI/" + dsBenhNhan_2[i]->getMaKhamBenh() + "_" + nameBeforeConvertToUpper + ".txt";
						ofstream file_output(file_out_path);

						file_output << "\t      HOA DON VIEN PHI" << endl;
						file_output << "---------------------------------------------" << endl;
						file_output << nameBeforeConvertToUpper << endl;
						file_output << "Tuoi: " << dsBenhNhan_2[i]->getTuoi();
						file_output << "\t\tGioi tinh: " << dsBenhNhan_2[i]->getGioiTinh() << endl;
						file_output << "Dia chi: " << dsBenhNhan_2[i]->getDiaChi() << endl;
						file_output << "Ma the BHYT: " << dsBenhNhan_2[i]->getBHYT() << endl;
						if (dsBenhNhan_2[i]->getDoiTuong() == 0)
						{
							file_output << "Doi tuong: BHYT 0%" << endl;
						}
						else if (dsBenhNhan_2[i]->getDoiTuong() == 1)
						{
							file_output << "Doi tuong: BHYT 80%" << endl;
						}
						else if (dsBenhNhan_2[i]->getDoiTuong() == 2)
						{
							file_output << "Doi tuong: BHYT 85%" << endl;
						}
						else if (dsBenhNhan_2[i]->getDoiTuong() == 3)
						{
							file_output << "Doi tuong: BHYT 90%" << endl;
						}
						file_output << "Den kham: " << dsBenhNhan_2[i]->getNgayBD() << endl;
						file_output << "Chan doan: " << dsBenhNhan_2[i]->getChanDoan() << endl;
						file_output << "---------------------------------------------" << endl;
						file_output << "Noi dung\t\t\t\tSo luong\tThanh tien BV\t\tThanh tien BH\t\tThanh tien\n" << endl;
						if (dsBenhNhan_2[i]->getMaGiuongBenh() != "")
						{
							// Nội trú
							int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
							if (doiTuong == 0)
							{
								file_output << "1. Kham benh" << endl;
								file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t0\t\t\t60,000" << endl;
								file_output << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									file_output << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t0\t\t\t" << formatCurrency(tienGiuongBenh) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									file_output << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t0\t\t\t" << formatCurrency(tienGiuongBenh) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									file_output << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t0\t\t\t" << formatCurrency(tienGiuongBenh) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
							else if (doiTuong == 1)
							{
								file_output << "1. Kham benh" << endl;
								file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t48,000\t\t\t12,000" << endl;
								file_output << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									file_output << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.8)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.8)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									file_output << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.8)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.8)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									file_output << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.8)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.8)) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
							else if (doiTuong == 2)
							{
							file_output << "1. Kham benh" << endl;
							file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t51,000\t\t\t9,000" << endl;
							file_output << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									file_output << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.85)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.85)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									file_output << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.85)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.85)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									file_output << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.85)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.85)) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
							else if (doiTuong == 3)
							{
							file_output << "1. Kham benh" << endl;
							file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t54,000\t\t\t6,000" << endl;
							file_output << "\n2. Ngay giuong" << endl;
								if (dsBenhNhan_2[i]->getLoaiGiuong() == 1)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 200000;
									file_output << "Giuong loai I\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.9)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.9)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 2)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 160000;
									file_output << "Giuong loai II\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.9)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.9)) << endl;
								}
								else if (dsBenhNhan_2[i]->getLoaiGiuong() == 3)
								{
									__int64 tienGiuongBenh = static_cast<__int64>(dsBenhNhan_2[i]->getSoNgayDieuTri()) * 120000;
									file_output << "Giuong loai III\t\t\t\t" << "1\t\t" << formatCurrency(tienGiuongBenh) << "\t\t" << formatCurrency(round(tienGiuongBenh * 0.9)) << "\t\t" << formatCurrency(tienGiuongBenh - round(tienGiuongBenh * 0.9)) << endl;
								}
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
						}
						else
						{
							// Ngoại trú
							vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
							size_t size = buffer.size();
							int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
							if (doiTuong == 0)
							{
								file_output << "1. Kham benh" << endl;
								file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t0\t\t\t60,000" << endl;
								file_output << "\n2. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								file_output << "\n3. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								file_output << "\n4. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t0\t\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								file_output << "\n5. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
							else if (doiTuong == 1)
							{
								file_output << "1. Kham benh" << endl;
								file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t48,000\t\t\t12,000" << endl;
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
							else if (doiTuong == 2)
							{
							file_output << "1. Kham benh" << endl;
							file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t51,000\t\t\t9,000" << endl;
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" << endl;
								system("pause");
							}
							else if (doiTuong == 3)
							{
							file_output << "1. Kham benh" << endl;
							file_output << "Kham ngoai\t\t\t\t1\t\t60,000\t\t\t54,000\t\t\t6,000" << endl;
								vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
								size_t size = buffer.size();
								file_output << "\n3. Xet nghiem" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 1)
									{
										file_output << "Phan tich te bao ngoai vi\t\t" << buffer[i].second << "\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(46200 * static_cast<long long>(buffer[i].second) - round(46200 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 2)
									{
										file_output << "HIV Ag/Ab\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(80000 * static_cast<long long>(buffer[i].second) - round(80000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 3)
									{
										file_output << "Dien giai do (Na, K, Cl) [Mau]\t\t" << buffer[i].second << "\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(29000 * static_cast<long long>(buffer[i].second) - round(29000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								file_output << "\n4. Chan doan hinh anh" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 4)
									{
										file_output << "Chup Xquang\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 5)
									{
										file_output << "Chup cat lop\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(522000 * static_cast<long long>(buffer[i].second) - round(522000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 6)
									{
										file_output << "Noi soi \t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(65400 * static_cast<long long>(buffer[i].second) - round(65400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 7)
									{
										file_output << "Sieu am\t\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(43900 * static_cast<long long>(buffer[i].second) - round(43900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								file_output << "\n5. Phau thuat" << endl;
								for (size_t i = 0; i < size; i++)
								{
									if (buffer[i].first == 8)
									{
										file_output << "Tieu phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(1700000 * static_cast<long long>(buffer[i].second) - round(1700000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 9)
									{
										file_output << "Dai phau\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second)) << "\t\t" << formatCurrency(round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t" << formatCurrency(6000000 * static_cast<long long>(buffer[i].second) - round(6000000 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								file_output << "\n6. Thuoc" << endl;
								for (int i = 0; i < size; i++)
								{
									if (buffer[i].first == 10)
									{
										file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 11)
									{
										file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 12)
									{
										file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
									else if (buffer[i].first == 13)
									{
										file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									}
								}
								long long tongCong = long long(dsBenhNhan_2[i]->getTongVienPhi());
								string rst = formatCurrency(tongCong);
								file_output << "\n\t\t\t\t\t\t\t\t\t\t\tTONG CONG: " << rst << endl;
								file_output.close();
								cout << "Xuat hoa don thanh cong!" <<endl;
								system("pause");
							}
						}
						break;
					}
					else
					{
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ma kham benh khong ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc tim benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
				}
			}
		}
	}
}

void BoPhanTaiVu::BPTVMenu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>BO PHAN TAI VU<<========" << endl;
		cout << "\t\t1. Nhap thong tin ket thuc dieu tri" << endl;
		cout << "\t\t2. Tinh vien phi" << endl;
		cout << "\t\t3. Kiem tra chi phi kham, chua benh" << endl;
		cout << "\t\t4. Xuat hoa don vien phi" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->Nhap();
		}
		else if (luaChon == 2)
		{
			this->TinhVienPhi();
		}
		else if (luaChon == 3)
		{
			this->TimKiem();
			system("pause");
		}
		else if (luaChon == 4)
		{
			this->XuatHoaDon();
		}
		else if (luaChon == 0)
		{
			App* app = new App;
			app->setVectorValueBN(dsBenhNhan_2);
			app->setVectorValueNV(dsNhanVien_2);
			app->Menu();
		}
	}
}

string BoPhanTaiVu::formatCurrency(long long val)
{
	string ans = "";

	string num = to_string(val);

	int count = 0;

	for (int i = num.size() - 1;
		i >= 0; i--) {
		count++;
		ans.push_back(num[i]);

		if (count == 3) {
			ans.push_back(',');
			count = 0;
		}
	}

	reverse(ans.begin(), ans.end());

	if (ans.size() % 4 == 0) {

		ans.erase(ans.begin());
	}

	return ans;
}

