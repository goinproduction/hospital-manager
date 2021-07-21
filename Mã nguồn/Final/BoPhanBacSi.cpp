#include "BoPhanBacSi.h"

BoPhanBacSi::BoPhanBacSi()
{
}

BoPhanBacSi::~BoPhanBacSi()
{
}

void BoPhanBacSi::setVectorValuesBN(vector<BN*> val)
{
	this->dsBenhNhan_2.swap(val);
}

void BoPhanBacSi::setVectorValuesNV(vector<NV*> val)
{
	this->dsNhanVien_2.swap(val);
}

void BoPhanBacSi::HienThiThongTin(string maBS)
{
	system("cls");
	cout << "========>>THONG TIN BENH NHAN<<========" << endl;
	size_t size = dsBenhNhan_2.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << "\nSTT: " << i + 1 << endl;
		if (dsBenhNhan_2[i]->getBacSiDieuTri() == maBS) {
			dsBenhNhan_2[i]->Xuat();
		}
	}
}

void BoPhanBacSi::DieuTri(string maBS)
{
	string maKhamBenh, chanDoan;
	int chieuCao, canNang, mach, huyetAp, soLuong;
	float nhietDo;
	bool flag;
	vector<pair<int, int>> phuongThucDieuTri;
	while (1)
	{
		system("cls");
		do
		{
			cin.ignore();
			cout << "Ma kham benh: ";
			getline(cin, maKhamBenh);
			size_t size = dsBenhNhan_2.size();
			flag = false;
			for (int i = 0; i < size; i++)
			{
				if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh && dsBenhNhan_2[i]->getBacSiDieuTri() == maBS)
				{
					flag = true;
					fflush(stdin);
					cout << "Chieu cao: ";
					cin >> chieuCao;
					cout << "Can nang: ";
					cin >> canNang;
					cout << "Nhiet do: ";
					cin >> nhietDo;
					cout << "Mach: ";
					cin >> mach;
					cout << "Huyet ap: ";
					cin >> huyetAp;
					dsBenhNhan_2[i]->setChieuCao(chieuCao);
					dsBenhNhan_2[i]->setCanNang(canNang);
					dsBenhNhan_2[i]->setNhietDo(nhietDo);
					dsBenhNhan_2[i]->setMach(mach);
					dsBenhNhan_2[i]->setHuyetAp(huyetAp);
					while (1)
					{
						system("cls");
						int luaChon;
						cout << "I/ Phuong thuc xet nghiem" << endl;
						cout << "1. Phan tich te bao mau ngoai vi" << endl;
						cout << "2. HIV Ag/Ab" << endl;
						cout << "3. Dien giai do (Na, K, Cl) [Mau]" << endl;
						cout << "0. Thoat" << endl;
						cout << "Nhap lua chon: ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(1, soLuong));
							cout << "Them thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 2)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(2, soLuong));
							cout << "Them thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 3)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(3, soLuong));
							cout << "Them thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 0)
						{
							break;
						}
					}

					while (1)
					{
						system("cls");
						int luaChon;
						cout << "II/ Chan doan hinh anh" << endl;
						cout << "1. Chup Xquang" << endl;
						cout << "2. Chup cat lop" << endl;
						cout << "3. Noi soi" << endl;
						cout << "4. Sieu am" << endl;
						cout << "0. Thoat" << endl;
						cout << "Nhap lua chon: ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(4, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 2)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(5, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 3)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(6, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 4)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(7, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 0)
						{
							break;
						}
					}

					while (1)
					{
						system("cls");
						int luaChon;
						cout << "III/ Phau thuat" << endl;
						cout << "1. Tieu phau" << endl;
						cout << "2. Dai phau" << endl;
						cout << "0. Thoat" << endl;
						cout << "Nhap lua chon: ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(8, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");

						}
						else if (luaChon == 2)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(9, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 0)
						{
							break;
						}
					}

					while (1)
					{
						system("cls");
						int luaChon;
						cout << "IV/ Thuoc" << endl;
						cout << "1. Domitazol" << endl;
						cout << "2. Cefoxitine Gerda" << endl;
						cout << "3. Cefepime Kabi" << endl;
						cout << "4. Ciprofloxacin" << endl;
						cout << "0. Thoat" << endl;
						cout << "Nhap lua chon: ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(10, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 2)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(11, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 3)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(12, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 4)
						{
							cout << "So luong: ";
							cin >> soLuong;
							phuongThucDieuTri.push_back(make_pair(13, soLuong));
							cout << "Them thanh cong" << endl;
							system("pause");
						}
						else if (luaChon == 0)
						{
							break;
						}
					}
					dsBenhNhan_2[i]->setPhuongThucDieuTri(phuongThucDieuTri);
					system("cls");
					cin.ignore();
					cout << "Chan doan: ";
					getline(cin, chanDoan);
					dsBenhNhan_2[i]->setChanDoan(chanDoan);
					break;
				}
			}
			if (flag == false)
			{
				cout << "Ma kham benh sai, vui long kiem tra lai!";
				break;
			}
		} while (flag == false);
		if (flag)
		{
			int luaChon;
			cout << "\nBan co muon tiep tuc dieu tri cho benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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

void BoPhanBacSi::CapNhat(string maBS)
{
	while (1)
	{
		vector<pair<int, int>> phuongThucDieuTri;
		string maKhamBenh;
		bool flag;
		int soLuong;
		do
		{
			cout << "Nhap ma kham benh: ";
			cin >> maKhamBenh;
			size_t size = dsBenhNhan_2.size();
			flag = false;
			for (size_t i = 0; i < size; i++)
			{
				if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh && dsBenhNhan_2[i]->getBacSiDieuTri() == maBS)
				{
					flag = true;
					if (flag == true)
					{
						system("cls");
						int luaChon;
						cout << "Danh muc can cap nhat" << endl;
						cout << "1. Thong tin co ban (Chieu cao, can nang, nhiet do, mach, huyet ap)" << endl;
						cout << "2. Xet nghiem" << endl;
						cout << "3. Chan doan hinh anh" << endl;
						cout << "4. Phau thuat" << endl;
						cout << "5. Thuoc" << endl;
						cout << "6. Chan doan" << endl;
						cout << "0. Thoat" << endl;
						cout << "Nhap lua chon: ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							system("cls");
							int chieuCao, canNang, mach, huyetAp;
							float nhietDo;
							fflush(stdin);
							cout << "Chieu cao: ";
							cin >> chieuCao;
							cout << "Can nang: ";
							cin >> canNang;
							cout << "Nhiet do: ";
							cin >> nhietDo;
							cout << "Mach: ";
							cin >> mach;
							cout << "Huyet ap: ";
							cin >> huyetAp;
							dsBenhNhan_2[i]->setChieuCao(chieuCao);
							dsBenhNhan_2[i]->setCanNang(canNang);
							dsBenhNhan_2[i]->setNhietDo(nhietDo);
							dsBenhNhan_2[i]->setMach(mach);
							dsBenhNhan_2[i]->setHuyetAp(huyetAp);
							cout << "Cap nhat thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 2)
						{
							while (1)
							{
								system("cls");
								int luaChon;
								cout << "I/ Phuong thuc xet nghiem" << endl;
								cout << "1. Phan tich te bao mau ngoai vi" << endl;
								cout << "2. HIV Ag/Ab" << endl;
								cout << "3. Dien giai do (Na, K, Cl) [Mau]" << endl;
								cout << "0. Thoat" << endl;
								cout << "Nhap lua chon: ";
								cin >> luaChon;
								if (luaChon == 1)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(1, soLuong));
									cout << "Them thanh cong!" << endl;
									system("pause");
								}
								else if (luaChon == 2)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(2, soLuong));
									cout << "Them thanh cong!" << endl;
									system("pause");
								}
								else if (luaChon == 3)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(3, soLuong));
									cout << "Them thanh cong!" << endl;
									system("pause");
								}
								else if (luaChon == 0)
								{
									break;
								}
							}
							cout << "Cap nhat thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 3)
						{
							while (1)
							{
								system("cls");
								int luaChon;
								cout << "II/ Chan doan hinh anh" << endl;
								cout << "1. Chup Xquang" << endl;
								cout << "2. Chup cat lop" << endl;
								cout << "3. Noi soi" << endl;
								cout << "4. Sieu am" << endl;
								cout << "0. Thoat" << endl;
								cout << "Nhap lua chon: ";
								cin >> luaChon;
								if (luaChon == 1)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(4, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 2)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(5, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 3)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(6, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 4)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(7, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 0)
								{
									break;
								}
							}
							cout << "Cap nhat thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 4)
						{
							while (1)
							{
								system("cls");
								int luaChon;
								cout << "III/ Phau thuat" << endl;
								cout << "1. Tieu phau" << endl;
								cout << "2. Dai phau" << endl;
								cout << "0. Thoat" << endl;
								cout << "Nhap lua chon: ";
								cin >> luaChon;
								if (luaChon == 1)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(8, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");

								}
								else if (luaChon == 2)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(9, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 0)
								{
									break;
								}
							}
							cout << "Cap nhat thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 5)
						{
							while (1)
							{
								system("cls");
								int luaChon, soLuong;
								cout << "IV/ Thuoc" << endl;
								cout << "1. Domitazol" << endl;
								cout << "2. Cefoxitine Gerda" << endl;
								cout << "3. Cefepime Kabi" << endl;
								cout << "4. Ciprofloxacin" << endl;
								cout << "0. Thoat" << endl;
								cout << "Nhap lua chon: ";
								cin >> luaChon;
								if (luaChon == 1)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(10, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 2)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(11, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 3)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(12, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 4)
								{
									cout << "So luong: ";
									cin >> soLuong;
									phuongThucDieuTri.push_back(make_pair(13, soLuong));
									cout << "Them thanh cong" << endl;
									system("pause");
								}
								else if (luaChon == 0)
								{
									break;
								}
							}
							cout << "Cap nhat thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 6)
						{
							string chanDoan;
							system("cls");
							cin.ignore();
							cout << "Chan doan: ";
							getline(cin, chanDoan);
							dsBenhNhan_2[i]->setChanDoan(chanDoan);
							cout << "Cap nhat thanh cong!" << endl;
							system("pause");
						}
						else if (luaChon == 0)
						{
							break;
						}
					}
					break;
				}
			}
			if (flag == false)
			{
				cout << "Ma kham benh khong hop le, vui long kiem tra lai!";
			}
		} while (flag == false);
		if (flag)
		{
			int luaChon;
			cout << "\nBan co muon tiep tuc cap nhat cho benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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

void BoPhanBacSi::TimKiem(string maBS)
{
	system("cls");
	bool flag;
	string maKhamBenh;
	do
	{
		cin.ignore();
		cout << "Ma kham benh: ";
		getline(cin, maKhamBenh);
		flag = false;
		size_t size = dsBenhNhan_2.size();
		for (size_t i = 0; i < size; i++)
		{
			if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh && dsBenhNhan_2[i]->getBacSiDieuTri() == maBS)
			{
				flag = true;
				cout << "Chieu cao: " << dsBenhNhan_2[i]->getChieuCao() << " (cm)" << "\tCan nang: " << dsBenhNhan_2[i]->getCanNang() << " (KG)" << endl;
				cout << "Nhiet do: " << dsBenhNhan_2[i]->getNhietDo() << " (C)" << "\t\tMach: " << dsBenhNhan_2[i]->getMach() << " (bpm)" << endl;
				cout << "Huyet ap: " << dsBenhNhan_2[i]->getHuyetAp() << " (mmHg)" << endl;
				vector<pair<int, int>> buffer = dsBenhNhan_2[i]->getPhuongThucDieuTri();
				size_t size = buffer.size();
				cout << "I/ Quy trinh xet nghiem" << endl;
				for (size_t i = 0; i < size; i++)
				{
					if (buffer[i].first == 1)
					{
						cout << "- Phan tich te bao mau ngoai vi" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 2)
					{
						cout << "- HIV Ag/Ab" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 3)
					{
						cout << "- Dien giai do (Na, K, Cl) [Mau]" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
				}
				cout << "II/ Chan doan hinh anh" << endl;
				for (size_t i = 0; i < size; i++)
				{
					if (buffer[i].first == 1)
					{
						cout << "- Chup Xquang" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 2)
					{
						cout << "- Chup cat lop" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 3)
					{
						cout << "- Noi soi" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 4)
					{
						cout << "- Sieu am" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
				}
				cout << "III/ Phau thuat" << endl;
				for (size_t i = 0; i < size; i++)
				{
					if (buffer[i].first == 1)
					{
						cout << "- Tieu phau" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 2)
					{
						cout << "- Dai phau" << endl;
						cout << "So luong: " << buffer[i].second << endl;
					}
				}
				cout << "IV/ Thuoc" << endl;
				for (size_t i = 0; i < size; i++)
				{
					if (buffer[i].first == 1)
					{
						cout << "- Domitazol" << "\t\tSo luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 2)
					{
						cout << "- Cefoxitine Gerda" << "\t\tSo luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 3)
					{
						cout << "- Cefepime Babi" << "\t\tSo luong: " << buffer[i].second << endl;
					}
					else if (buffer[i].first == 4)
					{
						cout << "- Ciprofloxacin" << "\t\tSo luong: " << buffer[i].second << endl;
					}
				}
				cout << "Chan doan: " << dsBenhNhan_2[i]->getChanDoan() << endl;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Ma kham benh khong hop le, vui long kiem tra lai!";
		}
	} while (flag == false);
}

void BoPhanBacSi::BPBSMenu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>DANG NHAP HE THONG<<========" << endl;
		cout << "\t\t1. Dang nhap" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->DangNhap();
		}
		else if (luaChon == 0)
		{
			break;
		}
	}
}

void BoPhanBacSi::DangNhap()
{
	while (1)
	{
		bool loginState;
		string maBS, pwd;
		cin.ignore();
		cout << "Ten dang nhap: ";
		getline(cin, maBS);
		cout << "Nhap mat khau: ";
		getline(cin, pwd);
		loginState = false;
		size_t size = dsNhanVien_2.size();
		for (size_t i = 0; i < size; i++)
		{
			if (dsNhanVien_2[i]->getMaNV() == maBS && dsNhanVien_2[i]->getChucVu() == 1 && pwd == "root")
			{
				loginState = true;
				break;
			}
		}
		if (loginState == false)
		{
			cout << "Dang nhap that bai!" << endl;
			system("pause");
			break;
		}
		if (loginState == true)
		{
			cout << "Dang nhap thanh cong!";
			Sleep(500);
			while (1)
			{
				system("cls");
				int luaChon;
				cout << "\t========>>BO PHAN BAC SI<<========" << endl;
				cout << "\t\t1. Hien thi danh sach benh nhan" << endl;
				cout << "\t\t2. Dieu tri benh nhan" << endl;
				cout << "\t\t3. Cap nhat qua trinh dieu tri" << endl;
				cout << "\t\t4. Tim kiem benh nhan" << endl;
				cout << "\t\t0. Quay lai" << endl;
				cout << "Nhap lua chon: ";
				cin >> luaChon;
				if (luaChon == 0)
				{
					break;
				}
				else if (luaChon == 1)
				{
					this->HienThiThongTin(maBS);
					system("pause");
				}
				else if (luaChon == 2)
				{
					this->DieuTri(maBS);
				}
				else if (luaChon == 3)
				{
					this->CapNhat(maBS);
				}
				else if (luaChon == 4)
				{
					this->TimKiem(maBS);
					system("pause");
				}
			}
			break;
		}
	}
}
