#include "BoPhanBanThuoc.h"
#pragma warning (disable : 4244)
#pragma warning (disable : 4267)
#pragma warning (disable : 4834)
using namespace std;

BoPhanBanThuoc::BoPhanBanThuoc()
{
}

BoPhanBanThuoc::~BoPhanBanThuoc()
{
}

void BoPhanBanThuoc::setVectorValuesBN(vector<BN*> val)
{
	this->dsBenhNhan_2.swap(val);
}

void BoPhanBanThuoc::setVectorValuesNV(vector<NV*> val)
{
	this->dsNhanVien_2.swap(val);
}

void BoPhanBanThuoc::HienThiDonThuoc()
{
	system("cls");
	cout << "\t\t\t\t\t========>>THONG TIN DON THUOC<<========" << endl;
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
						long double tongCong;
						cout << "Noi dung\t\t\t\tSo luong\tThanh tien BV\t\tThanh tien BH\t\tThanh tien" << endl;
						flag = true;
						vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
						size_t size = buffer.size();
						int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
						if (doiTuong == 0)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second);
								}
								else if (buffer[i].first == 11)
								{
									cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second);
								}
								else if (buffer[i].first == 12)
								{
									cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second);
								}
								else if (buffer[i].first == 13)
								{
									cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second);
								}
							}
							string rst = formatCurrency(tongCong);
							cout << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
						}
						else if (doiTuong == 1)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8);
								}
								else if (buffer[i].first == 11)
								{
									cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8);
								}
								else if (buffer[i].first == 12)
								{
									cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8);
								}
								else if (buffer[i].first == 13)
								{
									cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8);
								}
							}
							string rst = formatCurrency(tongCong);
							cout << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
						}
						else if (doiTuong == 2)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85);
								}
								else if (buffer[i].first == 11)
								{
									cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85);
								}
								else if (buffer[i].first == 12)
								{
									cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85);
								}
								else if (buffer[i].first == 13)
								{
									cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85);
								}
							}
							string rst = formatCurrency(tongCong);
							cout << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
						}
						else if (doiTuong == 3)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									cout << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9);
								}
								else if (buffer[i].first == 11)
								{
									cout << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9);
								}
								else if (buffer[i].first == 12)
								{
									cout << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9);
								}
								else if (buffer[i].first == 13)
								{
									cout << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9);
								}
							}
							string rst = formatCurrency(tongCong);
							cout << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
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
				cout << "\nBan co muon tiep tuc hien thi hoa don thuoc benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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

void BoPhanBanThuoc::XuatHoaDon()
{
	system("cls");
	cout << "\t\t\t\t\t========>>XUAT HOA DON DON THUOC<<========" << endl;
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
						string nameBeforeConvertToUpper = dsBenhNhan_2[i]->getHoTen();
						transform(nameBeforeConvertToUpper.begin(), nameBeforeConvertToUpper.end(), nameBeforeConvertToUpper.begin(), ::toupper);

						string file_out_path = "HOADONTHUOC/" + dsBenhNhan_2[i]->getMaKhamBenh() + "_" + nameBeforeConvertToUpper + ".txt";
						+"_" + nameBeforeConvertToUpper + ".txt";
						ofstream file_output(file_out_path);

						file_output << "\t      HOA DON THUOC" << endl;
						file_output << "---------------------------------------------" << endl;
						file_output << nameBeforeConvertToUpper << endl;
						file_output << "Tuoi: " << dsBenhNhan_2[i]->getTuoi();
						file_output << "\t\tGioi tinh: " << dsBenhNhan_2[i]->getGioiTinh() << endl;
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
						file_output << "Ma the BHYT: " << dsBenhNhan_2[i]->getBHYT() << endl;

						long double tongCong;
						file_output << "---------------------------------------------" << endl;
						file_output << "Noi dung\t\t\t\tSo luong\tThanh tien BV\t\tThanh tien BH\t\tThanh tien\n" << endl;
						flag = true;
						vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
						size_t size = buffer.size();
						int doiTuong = dsBenhNhan_2[i]->getDoiTuong();
						if (doiTuong == 0)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second);
								}
								else if (buffer[i].first == 11)
								{
									file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second);
								}
								else if (buffer[i].first == 12)
								{
									file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second);
								}
								else if (buffer[i].first == 13)
								{
									file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t0\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second);
								}
							}
							string rst = formatCurrency(tongCong);
							file_output << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
							file_output.close();
							cout << "Xuat hoa don thanh cong!";
							system("pause");
						}
						else if (doiTuong == 1)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.8);
								}
								else if (buffer[i].first == 11)
								{
									file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.8);
								}
								else if (buffer[i].first == 12)
								{
									file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.8);
								}
								else if (buffer[i].first == 13)
								{
									file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.8);
								}
							}
							string rst = formatCurrency(tongCong);
							file_output << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
							file_output.close();
							cout << "Xuat hoa don thanh cong!";
							system("pause");
						}
						else if (doiTuong == 2)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.85);
								}
								else if (buffer[i].first == 11)
								{
									file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.85);
								}
								else if (buffer[i].first == 12)
								{
									file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.85);
								}
								else if (buffer[i].first == 13)
								{
									file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.85);
								}
							}
							string rst = formatCurrency(tongCong);
							file_output << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
							file_output.close();
							cout << "Xuat hoa don thanh cong!";
							system("pause");
						}
						else if (doiTuong == 3)
						{
							tongCong = 0;
							for (int i = 0; i < size; i++)
							{
								if (buffer[i].first == 10)
								{
									file_output << "Domitazol\t\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 2288 * static_cast<long long>(buffer[i].second) - round(2288 * static_cast<long long>(buffer[i].second) * 0.9);
								}
								else if (buffer[i].first == 11)
								{
									file_output << "Cefoxitine Gerda 2g - (Cefoxitin)\t" << buffer[i].second << "\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 228400 * static_cast<long long>(buffer[i].second) - round(228400 * static_cast<long long>(buffer[i].second) * 0.9);
								}
								else if (buffer[i].first == 12)
								{
									file_output << "Cefepime Kabi 1g - (Cefepim)\t\t" << buffer[i].second << "\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 61900 * static_cast<long long>(buffer[i].second) - round(61900 * static_cast<long long>(buffer[i].second) * 0.9);
								}
								else if (buffer[i].first == 13)
								{
									file_output << "Ciprofloxacin 200mg\t\t\t" << buffer[i].second << "\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second)) << "\t\t\t" << formatCurrency(round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << "\t\t\t" << formatCurrency(17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9)) << endl;
									tongCong += 17575 * static_cast<long long>(buffer[i].second) - round(17575 * static_cast<long long>(buffer[i].second) * 0.9);
								}
							}
							string rst = formatCurrency(tongCong);
							file_output << "\n\t\t\t\t\t\t\t\t\t\t\t   TONG CONG: " << rst << endl;
							file_output.close();
							cout << "Xuat hoa don thanh cong!";
							system("pause");
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
				cout << "\nBan co muon tiep tuc hien thi hoa don thuoc benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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

string BoPhanBanThuoc::formatCurrency(long long val)
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

void BoPhanBanThuoc::BPBTMenu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>BO PHAN BAN THUOC<<========" << endl;
		cout << "\t\t1. Hien thi don thuoc" << endl;
		cout << "\t\t2. Xuat hoa don" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->HienThiDonThuoc();
		}
		else if (luaChon == 2)
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
