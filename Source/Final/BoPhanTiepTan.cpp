#include "BoPhanTiepTan.h"

void BoPhanTiepTan::setVectorValuesBN(vector<BN*> val)
{
	this->dsBenhNhan_2.swap(val);
}

void BoPhanTiepTan::setVectorValuesNV(vector<NV*> val)
{
	this->dsNhanVien_2.swap(val);
}

void BoPhanTiepTan::Nhap()
{
	while (1) {
		system("cls");
		int luaChon;
		BN* bn = new BN;
		cout << "\t\t========>>NHAP THONG TIN BENH NHAN<<========" << endl;
		cout << "\t\t1. Benh nhan moi" << endl;
		cout << "\t\t2. Benh nhan cu" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		
		if (luaChon == 2)
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
						dsBenhNhan_2[i]->setMaKhamBenh(maKhamBenh);
						string trieuChung;
						cout << "Trieu chung: ";
						getline(cin, trieuChung);
						dsBenhNhan_2[i]->setTrieuChung(trieuChung);
						cout << "Thanh cong!" << endl;
						break;
					}
				}
				if (flag == false)
				{
					cout << "Benh nhan chua ton tai trong he thong!" << endl;
					break;
				}
			} while (flag == false);
			system("pause");
		}else if (luaChon == 1)
		{
			system("cls");
			int luaChon_2;
			cout << "\t\t========>>NHAP THONG TIN BENH NHAN<<========" << endl;
			cout << "\t\t1. Benh nhan noi tru" << endl;
			cout << "\t\t2. Benh nhan ngoai tru" << endl;
			cout << "\t\t0. Quay lai" << endl;
			cout << "Nhap lua chon: ";
			cin >> luaChon_2;
			if (luaChon_2 == 1)
			{
				bn = new BenhNhanNoiTru;
				string maKhamBenh;
				bool flag;
				do
				{
					cin.ignore();
					cout << "Ma kham benh: ";
					getline(cin, maKhamBenh);
					size_t size = dsBenhNhan_2.size();
					flag = true;
					for (int i = 0; i < size; i++)
					{
						if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh)
						{
							flag = false;
							break;
						}
					}
					if (flag == false)
					{
						cout << "Ma bi trung, vui long nhap lai!";
					}
				} while (flag == false);
				bn->setMaKhamBenh(maKhamBenh);
				bn->Nhap();
				cin.ignore();
				string trieuChung;
				cout << "Trieu chung: ";
				getline(cin, trieuChung);
				bn->setTrieuChung(trieuChung);
				bool flag_2;
				string maBS;
				do
				{
					cout << "Ma bac si dieu tri: ";
					getline(cin, maBS);
					flag_2 = false;
					size_t size = dsNhanVien_2.size();
					for (int i = 0; i < size; i++)
					{
						if (dsNhanVien_2[i]->getMaNV() == maBS && dsNhanVien_2[i]->getChucVu() == 1 && dsNhanVien_2[i]->getKhoaCongTac() == 1)
						{
							flag_2 = true;
							bn->setBacSiDieuTri(maBS);
							break;
						}
						else
						{
							flag_2 = false;
						}
					}
					if (flag_2 == false)
					{
						cout << "Ma bac si khong ton tai, vui long kiem tra lai!" << endl;
					}
				} while (flag_2 == false);
				dsBenhNhan_2.push_back(bn);
				cout << "Thanh cong!" << endl;
				system("pause");
			}
			else if (luaChon_2 == 2)
			{
				bn = new BenhNhanNgoaiTru;
				string maKhamBenh;
				bool flag;
				do
				{
					cin.ignore();
					cout << "Ma kham benh: ";
					getline(cin, maKhamBenh);
					size_t size = dsBenhNhan_2.size();
					flag = true;
					for (int i = 0; i < size; i++)
					{
						if (dsBenhNhan_2[i]->getMaKhamBenh() == maKhamBenh)
						{
							flag = false;
							break;
						}
					}
					if (flag == false)
					{
						cout << "Ma bi trung, vui long nhap lai!";
					}
				} while (flag == false);
				bn->setMaKhamBenh(maKhamBenh);
				bn->Nhap();
				string trieuChung;
				cout << "Trieu chung: ";
				getline(cin, trieuChung);
				bn->setTrieuChung(trieuChung);
				bool flag_2;
				string maBS;
				do
				{
					cout << "Ma bac si dieu tri: ";
					getline(cin, maBS);
					flag_2 = true;
					size_t size = dsNhanVien_2.size();
					for (int i = 0; i < size; i++)
					{
						if (dsNhanVien_2[i]->getMaNV() == maBS && dsNhanVien_2[i]->getChucVu() == 1 && dsNhanVien_2[i]->getKhoaCongTac() == 2)
						{
							flag_2 = true;
							bn->setBacSiDieuTri(maBS);
							break;
						}
						else
						{
							flag_2 = false;
						}
					}
					if (flag_2 == false)
					{
						cout << "Ma bac si khong ton tai, vui long kiem tra lai!" << endl;
					}
				} while (flag_2 == false);
				dsBenhNhan_2.push_back(bn);
				cout << "Thanh cong!" << endl;
				system("pause");
			}
			else if (luaChon_2 == 0)
			{
				system("cls");
				break;
			}
		}
		else if (luaChon == 0)
		{
			system("cls");
			break;
		}
	}
}

void BoPhanTiepTan::Xuat()
{
	system("cls");
	cout << "========>>DANH SACH BENH NHAN<<========" << endl;
	size_t size = dsBenhNhan_2.size();
	for (int i = 0; i < size; i++)
	{
		cout << "\nSTT: " << i + 1 << endl;
		dsBenhNhan_2[i]->Xuat();
	}
}

void BoPhanTiepTan::XuatPhieuKham()
{
	system("cls");
	cout << "========>>XUAT PHIEU KHAM BENH<<========" << endl;
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
						string phongKham;
						int soThuTu;
						cout << "Phong kham: ";
						getline(cin, phongKham);
						dsBenhNhan_2[i]->setPhongKham(phongKham);

						cout << "So thu tu kham: ";
						cin >> soThuTu;
						dsBenhNhan_2[i]->setSoThuTu(soThuTu);

						string nameBeforeConvertToUpper = dsBenhNhan_2[i]->getHoTen();
						transform(nameBeforeConvertToUpper.begin(), nameBeforeConvertToUpper.end(), nameBeforeConvertToUpper.begin(), ::toupper);
						
						string file_out_path = "PHIEUKHAMBENH/" + dsBenhNhan_2[i]->getMaKhamBenh() + "_" + nameBeforeConvertToUpper + ".txt";
						ofstream file_output(file_out_path);

						file_output << "\t      PHIEU KHAM BENH" << endl;
						file_output << "---------------------------------------------" << endl;
						file_output << nameBeforeConvertToUpper << endl;
						file_output << "Tuoi: " << dsBenhNhan_2[i]->getTuoi();
						file_output << "\t\tGioi tinh: " << dsBenhNhan_2[i]->getGioiTinh() << endl;
						auto end = chrono::system_clock::now();
						time_t end_time = chrono::system_clock::to_time_t(end);
						file_output << "Thoi gian tiep nhan: " << ctime(&end_time);
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
						file_output << "Phong kham: " << dsBenhNhan_2[i]->getPhongKham() << endl;
						file_output << "So thu tu kham: " << dsBenhNhan_2[i]->getSoThuTu();
						file_output.close();
						cout << "Xuat phieu kham benh thanh cong!" << endl;
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
			if (flag)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc xuat phieu kham benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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

void BoPhanTiepTan::CapNhat()
{
	system("cls");
	cout << "\t========>>CAP NHAT THONG TIN BENH NHAN<<========" << endl;
	size_t size = dsBenhNhan_2.size();
	if (size == 0)
	{
		cout << "Danh sach benh nhan rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else
	{
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
						string idUpdate;
						do
						{
							cout << "Ma kham benh: ";
							getline(cin, idUpdate);
							size_t size = dsBenhNhan_2.size();
							flag = true;
							for (int i = 0; i < size; i++)
							{
								if (dsBenhNhan_2[i]->getMaKhamBenh() == idUpdate)
								{
									flag = false;
									break;
								}
							}
							if (flag == false)
							{
								cout << "Ma kham bi trung, vui long nhap lai!" << endl;
							}
						} while (flag == false);
						dsBenhNhan_2[i]->setMaKhamBenh(idUpdate);
						dsBenhNhan_2[i]->Nhap();
						cin.ignore();
						string trieuChung;
						cout << "Trieu chung: ";
						getline(cin, trieuChung);
						dsBenhNhan_2[i]->setTrieuChung(trieuChung);
						cout << "Cap nhat thanh cong!" << endl;
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
			if (flag)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc cap nhat benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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

void BoPhanTiepTan::Xoa()
{
	system("cls");
	cout << "\t========>>XOA BENH NHAN<<========" << endl;
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
						int luaChon;
						cout << "Ban co chac chan xoa khong? (1: Co; 0: Khong): ";
						cin >> luaChon;
						if (luaChon == 0)
						{
							break;
						}
						else if (luaChon == 1)
						{
							auto buffer = dsBenhNhan_2.begin();
							while (buffer != dsBenhNhan_2.end()) {
								if ((*buffer)->getMaKhamBenh() == maKhamBenh)
								{
									delete* buffer;
									dsBenhNhan_2.erase(buffer);
									break;
								}
								buffer++;
							}
							cout << "Xoa thanh cong!" << endl;
							break;
						}
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
				cout << "\nBan co muon tiep tuc xoa benh nhan khac? (Tiep tuc: 1; Dung lai: 0): ";
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
			else {
				cout << "\nDanh sach benh nhan rong!" << endl;
				system("pause");
				break;
			}
		}
	}
}

void BoPhanTiepTan::TimKiem()
{
	system("cls");
	cout << "\t========>>TIM KIEM BENH NHAN<<========" << endl;
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
						cout << "========>>THONG TIN BENH NHAN<<========" << endl;
						dsBenhNhan_2[i]->Xuat();
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

void BoPhanTiepTan::BPTTMenu()
{
	while (1) {
		system("cls");
		int luaChon;
		cout << "\t========>>BO PHAN TIEP TAN<<========" << endl;
		cout << "\t\t1. Nhap thong tin benh nhan" << endl;
		cout << "\t\t2. Hien thi danh sach" << endl;
		cout << "\t\t3. Xuat phieu kham benh" << endl;
		cout << "\t\t4. Cap nhat danh sach" << endl;
		cout << "\t\t5. Xoa" << endl;
		cout << "\t\t6. Tim kiem" << endl;
		cout << "\t\t0. Quay lai" << endl;
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			this->Nhap();
		}
		else if (luaChon == 2)
		{
			this->Xuat();
			system("pause");
		}
		else if (luaChon == 3)
		{
			this->XuatPhieuKham();
		}
		else if (luaChon == 4)
		{
			this->CapNhat();
		}
		else if (luaChon == 5)
		{
			this->Xoa();
		}
		else if (luaChon == 6)
		{
			this->TimKiem();
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
