#pragma once

void exit() {
	char x = _getch();
	while (x != 27) {
		if (x != -32) {
			cout << "Nhan ESC de quay lai." << endl;
		}
		x = _getch();
	}
}

template <class T>
void loadFile(int n, T* array, string fileText) {
	ofstream ofs(fileText, ios::out);
	for (int i = 0; i < n; i++) {
		array[i].ghiDuLieu(ofs);
	}
	ofs.close();
}
template <class T>
void layDS(int& n, T* array, string fileText) {
	ifstream ifs(fileText);
	while (!ifs.eof()) {
		array[n].docDuLieu(n, ifs);
	}
	ifs.close();
}
template <class T>
bool isEmpty(int n, T a) {
	return (n == 0);
}
template<class T>
void deleteElement(int& n, T* array, int vitri) {
	if (n <= 0) return;
	else {
		if (vitri >= 0 && vitri < n) {
			for (int i = vitri; i < n - 1; i++) {
				array[i] = array[i + 1];
			}
		}
		n--;
	}
}

bool checkExistByIDProduct(string maHang, int nHH, HangHoa* hangHoa) {
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == maHang) {
			return false;
		}
	}
	return true;
}

float singlePriceByID(string _maHang) {
	float donGia = 0;
	HangHoa hangHoa[100];
	int nHH = 0;
	layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == _maHang) {
			return hangHoa[i].getGiaBan();
		}
	}
	return donGia;
}
int quantityShowingByID(string _maHang) {
	int soLuong = 0;
	HangHoa hangHoa[100];
	int nHH = 0;
	layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == _maHang) {
			return hangHoa[i].getSoLuongHienThi();
		}
	}
	return soLuong;
}
void editQuantityShowing(string _maHang, int soLuong) {
	HangHoa hangHoa[100];
	int nHH = 0;
	layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == _maHang) {
			hangHoa[i].setSoLuongHienThi(hangHoa[i].getSoLuongHienThi() - soLuong);
			loadFile<HangHoa>(nHH, hangHoa, "HangHoa.txt");
		}
	}
}
int quantitySavingByID(string _maHang) {
	int soLuong = 0;
	HangHoa hangHoa[100];
	int nHH = 0;
	layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == _maHang) {
			return hangHoa[i].getSoLuongTonKho();
		}
	}
	return soLuong;
}
bool editQuantitySaving(int nHH, HangHoa* hangHoa, string maHang, int soLuong) {
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == maHang) {
			hangHoa[i].setSoLuongTonKho(soLuong);
			loadFile<HangHoa>(nHH, hangHoa, "HangHoa.txt");
			return true;
		}
	}
	return false;
}

void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

//t = 1: Main Menu
//t = 2: Manage Menu
//t = 3: Sub Manage Menu
void focusChoose(int currentChoose, int k, int t) {
	string mess;
	switch (t)
	{
	case 1:
	{
		switch (currentChoose)
		{
		case 1: mess = " Hien thi thong tin hang hoa ";
			break;
		case 2: mess = " Tim kiem thong tin hang hoa ";
			break;
		case 3: mess = "           Dat hang          ";
			break;
		case 4: mess = "           Quan ly           ";
			break;
		default:
			mess = "           Thoat             ";
			break;
		}
		break;
	}
	case 2:
	{
		switch (currentChoose)
		{
		case 1: mess = "        Xu ly don hang       ";
			break;
		case 2: mess = "       Quan ly hang hoa      ";
			break;
		default:
			mess = "           Thoat             ";
			break;
		}
		break;
	}
	default:
		switch (currentChoose)
		{
		case 1: mess = "        Them hang hoa        ";
			break;
		case 2: mess = "         Xoa hang hoa        ";
			break;
		case 3: mess = "  Cap nhat so luong hang hoa ";
			break;
		default:
			mess = "           Thoat             ";
			break;
		}
		break;
	}
	cout << setw(22) << "*";
	if (currentChoose == k) {
		SetColor(6, 0);
	}
	cout << setw(27) << mess;
	SetColor(0, 14);
	cout << "*" << endl;
}
void showMainMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 14);
	cout << setw(57) << right << "|----------> MENU CHINH <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 5; i++) {
		focusChoose(i, k, 1);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 7);
}
void showManageMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 14);
	cout << setw(58) << right << "|----------> MENU QUAN LY <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 3; i++) {
		focusChoose(i, k, 2);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 7);
}
void showSubManageMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 14);
	cout << setw(58) << right << "|----------> MENU CON QUAN LY <---------|\n\n\n";

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 4; i++) {
		focusChoose(i, k, 3);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 7);
}
void showWarning(int k, string mess) {
	system("cls");
	cout << "\n\n";
	cout << setw(21) << "" << setfill('-') << setw(32) << "-" << setfill(' ') << endl;
	cout << setw(22) << "|" << setw(22) << "Them ma hang?" << setw(9) << "|" << endl;
	cout << setw(22) << "|" << setw(31) << "|" << endl;
	cout << setw(22) << "|" << setw(31) << "|" << endl;

	cout << setw(22) << "|" << setw(5) << "";
	if (k == 1) {
		SetColor(6, 0);
	}
	cout << "YES";
	SetColor(0, 14);
	cout << setw(15) << "";
	if (k == 2) {
		SetColor(6, 0);
	}
	cout  << "NO";
	SetColor(0, 14);
	cout << setw(6) << "|" << endl;

	cout << setw(22) << "|" << setw(31) << "|" << endl;
	cout << setw(21) << "" << setfill('-') << setw(32) << "-" << setfill(' ') << endl;
}

void showProduct() {
	int nHH = 0;
	HangHoa hangHoa[50];
	layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
	system("cls");
	SetColor(0, 14);
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl;
	cout << setw(57) << "*                                *" << endl;

	cout << setw(57) << "*       DANH SACH HANG HOA       *" << endl;

	cout << setw(57) << "*                                *" << endl;
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl << endl;
	if (!isEmpty(nHH, hangHoa)) {
		cout << setw(9) << left << "Ma hang";
		cout << setw(18) << left << "Ten hang";
		cout << setw(13) << left << "Noi san xuat";
		cout << setw(8) << left << "Mau sac";
		cout << setw(9) << left << "Gia ban";
		cout << setw(14) << left << "Ngay nhap kho";
		cout << setw(8) << left << "So luong" << endl;
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		for (int i = 0; i < nHH; i++) {
			hangHoa[i].hienThi();
		}
		cout << "\nNhan ESC de quay lai menu chinh.\n" << endl;
	}
	else {
		cout << setw(63) << "\nKhong co hang hoa nao!. Nhan ESC de quay lai.\n" << endl;
	}
}

bool searchProduct(string productName) {
	bool check = false;
	int nHH = 0;
	HangHoa hangHoa[50];
	layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl;
	cout << setw(57) << "*                                *" << endl;

	cout << setw(57) << "*       DANH SACH TIM DUOC       *" << endl;

	cout << setw(57) << "*                                *" << endl;
	cout << setw(23) << "" << setfill('*') << setw(34) << "*" << setfill(' ') << endl << endl;
	if (!isEmpty(nHH, hangHoa)) {
		cout << setw(9) << left << "Ma hang";
		cout << setw(18) << left << "Ten hang";
		cout << setw(13) << left << "Noi san xuat";
		cout << setw(8) << left << "Mau sac";
		cout << setw(9) << left << "Gia ban";
		cout << setw(14) << left << "Ngay nhap kho";
		cout << setw(8) << left << "So luong" << endl;
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		for (int i = 0; i < nHH; i++) {
			if (hangHoa[i].getTenHang() == productName) {
				hangHoa[i].hienThi();
				check = true;
			}
		}
		if (check)
			cout << "\nNhan ESC de quay lai menu chinh.\n";
		else
			cout << "\nKhong co hang hoa nay. Nhan ESC de quay lai.\n";
	}
	else {
		cout << setw(63) << "\nKhong co hang hoa nao!. Nhan ESC de quay lai.\n";
	}
	return check;
}

int currentNumber(string fileText) {
	ifstream ifs(fileText);
	int stt = 0;
	string key;
	while (!ifs.eof()) {
		getline(ifs, key);
		if (key == "") {
			stt++;
		}
	}
	ifs.close();
	if (stt > 1) return stt - 1;
	return 0;
}
bool regisOrder1(int& n, string* maHang, int* soLuong) {
	bool regis = true;
	while (regis) {
		system("cls");
		HangHoa hangHoa[100];
		int nHH = 0;
		layDS<HangHoa>(nHH, hangHoa, "HangHoa.txt");
		SetColor(0, 14);
		cout << setw(59) << right << "|----------> NHAP DON HANG <---------|\n\n\n";
		cout << setw(21) << "" << setfill('*') << setw(32) << "*" << setfill(' ') << endl;
		string mH;
		cout << setw(32) << "Ma hang: ";
		getline(cin, mH);
		while (mH == "" || checkExistByIDProduct(mH, nHH, hangHoa)) {
			if (mH == "")	cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(32) << "Ma hang: ";
			else cout << setw(48) << "(Khong ton tai ma hang nay.)\n\n" << setw(32) << "Ma hang: ";
			getline(cin, mH);
		}
		maHang[n] = mH;
		int sL;
		cout << setw(38) << "Nhap so luong: ";
		cin >> sL;
		if (quantityShowingByID(mH) != 0) {
			while (sL == 0 || sL > quantityShowingByID(mH)) {
				if (sL == 0)
					cout << setw(32) << "(It nhat 1.)\n\n" << setw(38) << "Nhap so luong: ";
				else
					cout << setw(41) << "(San pham nay chi con " << quantityShowingByID(mH) << " san pham)\n\n" << setw(38) << "Nhap so luong: ";
				cin >> sL;
			}
			soLuong[n] = sL;
			cin.ignore();
			n++;
		}
		else {
			cout << "Ma hang nay da het, quay lai menu chinh" << endl;
			return false;
		}

		char choose = 0;
		int k = 1;
		string warningMess = "Them hang hoa?";
		showWarning(k, warningMess);
		while (choose != 27)
		{
			choose = _getch();
			if (choose != -32) {
				showWarning(k, warningMess);
				switch (choose)
				{
				case 77:
					k++;
					if (k == 3) {
						k = 1;
					}
					showWarning(k, warningMess);
					break;
				case 75:
					k--;
					if (k == 0) {
						k = 2;
					}
					showWarning(k, warningMess);
					break;
				case 13:
					switch (k)
					{
					case 1:
						choose = 27;
						regis = true;
						break;
					default:
						choose = 27;
						regis = false;
						break;
					}
					break;
				default:
					break;
				}
			}
		}
	}
	return true;
}
bool regisOrder2(string& tenKH, string& diachiKH, string& soDT, string& ngayDat) {
	system("cls");
	SetColor(0, 14);
	cout << setw(59) << right << "|----------> NHAP THONG TIN <---------|\n\n\n";
	cout << setw(21) << "" << setfill('*') << setw(32) << "*" << setfill(' ') << endl;
	cout << setw(39) << "Ten khach hang: ";
	getline(cin, tenKH);
	while (tenKH == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(39) << "Ten khach hang: ";
		getline(cin, tenKH);
	}

	cout << setw(32) << "Dia chi: ";
	getline(cin, diachiKH);
	while (diachiKH == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(32) << "Dia chi: ";
		getline(cin, diachiKH);
	}

	cout << setw(38) << "So dien thoai: ";
	getline(cin, soDT);
	while (soDT == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(38) << "So dien thoai: ";
		getline(cin, soDT);
	}

	cout << setw(50) << "Ngay dat (year/month/day): ";
	getline(cin, ngayDat);
	while (ngayDat == "") {
		cout << setw(42) << "(Khong duoc bo trong.)\n\n" << setw(50) << "Ngay dat (year/month/day): ";
		getline(cin, ngayDat);
	}
	return true;
}
bool addOrder(int n, string* maHang, int* soLuong, string tenKH, string diachiKH, string soDT, string ngayDat) {
	float tongTien = 0;
	float* donGia = new float[100];
	for (int i = 0; i < n; i++) {
		donGia[i] = soLuong[i] * singlePriceByID(maHang[i]);
		tongTien += donGia[i];
	}
	ofstream ofs("DonHang.txt", ios::app);
	ofs << "So thu tu: " << currentNumber("DonHang.txt") + 1 << endl;
	for (int i = 0; i < n; i++) {
		ofs << "Ma hang: " << maHang[i] << ", so luong: " << soLuong[i] << endl;
		editQuantityShowing(maHang[i], soLuong[i]);
	}
	ofs << "Tong tien: " << tongTien << endl;
	ofs << "Ten khach hang: " << tenKH << endl;
	ofs << "Dia chi: " << diachiKH << endl;
	ofs << "So dien thoai: " << soDT << endl;
	ofs << "Ngay dat hang: " << ngayDat << endl << endl;
	delete donGia;
	ofs.close();
	return true;
}

void showLogin(string& _userName, string& _passWord, string mess) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 12);
	cout << setw(63) << mess << endl;
	SetColor(0, 14);
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << setw(22) << "*" << setw(30) << "*" << endl;
	cout << setw(22) << "*";
	SetColor(0, 11);
	cout << "      DANG NHAP HE THONG     ";
	SetColor(0, 14);
	cout << "*" << endl;
	cout << setw(22) << "*" << setw(30) << "*" << endl;
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	SetColor(0, 3);

	string userName;
	cout << setw(33) << "User: ";
	SetColor(0, 7);
	cin >> userName;
	_userName = userName;
	SetColor(0, 3);
	string passWord;
	cout << setw(37) << "Password: ";
	SetColor(0, 7);

	string pass = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			pass += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	cout << endl;
	_passWord = pass;
}
bool checkAccount(string userName, string passWord, int nAD, Admin* admin) {
	for (int i = 0; i < nAD; i++) {
		if (admin[i].getUser() == userName && admin[i].getPass() == passWord) {
			return true;
			break;
		}
	}
	return false;
}

bool updateProduct(int nHH, HangHoa* hangHoa, int n, string* maHang, int* soLuong) {
	for (int i = 0; i < n; i++) {
		editQuantitySaving(nHH, hangHoa, maHang[i], quantitySavingByID(maHang[i]) - soLuong[i]);
	}
	return true;
}
bool deleteOrder(int& nDH, DonHang* donHang, int soThuTu) {
	for (int i = 0; i < nDH; i++) {
		if (donHang[i].getSTT() == soThuTu) {
			deleteElement<DonHang>(nDH, donHang, i);
			loadFile<DonHang>(nDH, donHang, "DonHang.txt");
			return true;
		}
	}
	return false;
}
bool handlingOrder(int& nDH, DonHang* donHang, int& nHH, HangHoa* hangHoa, int& dem) {
	while (nDH != 0) {
		int i = 0;
		updateProduct(nHH, hangHoa, donHang[i].getN(), donHang[i].getMaHang(), donHang[i].getSoLuong());
		deleteOrder(nDH, donHang, donHang[i].getSTT());
		dem++;
	}
	return true;
}

void regisProduct(int& nHH, HangHoa* hangHoa, string& maHang, string& tenHang, string& noiSanXuat, string& mauSac, float& giaBan, string& ngayNhapKho, int& soLuong) {
	system("cls");
	SetColor(0, 14);
	cout << setw(59) << right << "|----------> NHAP THONG TIN <---------|\n\n\n";
	cout << setw(21) << "" << setfill('*') << setw(32) << "*" << setfill(' ') << endl;
	cout << setw(32) << "Ma hang: ";
	cin >> maHang;
	while (!checkExistByIDProduct(maHang, nHH, hangHoa)) {
		cout << setw(42) << "(Da co ma hang nay.)\n\n" << setw(32) << "Ma hang: ";
		cin >> maHang;
	}
	cin.ignore();
	cout << setw(33) << "Ten hang: ";
	getline(cin, tenHang);
	cout << setw(37) << "Noi san xuat: ";
	getline(cin, noiSanXuat);
	cout << setw(32) << "Mau sac: ";
	getline(cin, mauSac);
	cout << setw(32) << "Gia ban: ";
	cin >> giaBan;
	cin.ignore();
	cout << setw(38) << "Ngay nhap kho: ";
	cin >> ngayNhapKho;
	cout << setw(33) << "So luong: ";
	cin >> soLuong;
	cin.ignore();
}
bool addProduct(string& maHang, string& tenHang, string& noiSanXuat, string& mauSac, float& giaBan, string& ngayNhapKho, int& soLuongHienThi) {
	ofstream ofs("HangHoa.txt", ios::app);
	ofs << "Ma hang: " << maHang << endl;
	ofs << "Ten hang: " << tenHang << endl;
	ofs << "Noi san xuat: " << noiSanXuat << endl;
	ofs << "Mau sac: " << mauSac << endl;
	ofs << "Gia ban: " << giaBan << endl;
	ofs << "Ngay nhap kho: " << ngayNhapKho << endl;
	ofs << "So luong hien thi: " << soLuongHienThi << endl;
	ofs << "So luong ton kho: " << soLuongHienThi << endl << endl;
	ofs.close();
	return true;
}

bool deleteProduct(int& nHH, HangHoa* hangHoa, string maHang) {
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == maHang) {
			deleteElement<HangHoa>(nHH, hangHoa, i);
			return true;
		}
	}
	return false;
}

bool updateQuantityProduct(int nHH, HangHoa* hangHoa, string maHang, int soLuong) {
	for (int i = 0; i < nHH; i++) {
		if (hangHoa[i].getMaHang() == maHang) {
			hangHoa[i].setSoLuongTonKho(soLuong);
			hangHoa[i].setSoLuongHienThi(soLuong);
		}
	}
	return true;
}
