#pragma once
class HangHoa {
private:
	string maHang, tenHang, noiSanXuat, mauSac;
	float giaBan;
	string ngayNhapKho;
	int soLuongHienThi;
	int soLuongTonKho;
public:
	HangHoa() {}
	HangHoa(string maHang, string tenHang, string noiSanXuat, string mauSac, float giaBan, string ngayNhapKho, int soLuongHienThi, int soLuongTonKho) {
		this->maHang = maHang;
		this->tenHang = tenHang;
		this->noiSanXuat = noiSanXuat;
		this->mauSac = mauSac;
		this->giaBan = giaBan;
		this->ngayNhapKho = ngayNhapKho;
		this->soLuongHienThi = soLuongHienThi;
		this->soLuongTonKho = soLuongTonKho;
	}
	~HangHoa() {}

	string getMaHang() {
		return this->maHang;
	}
	void setMaHang(string mH) {
		this->maHang = mH;
	}
	string getTenHang() {
		return this->tenHang;
	}
	void setTenHang(string tH) {
		this->tenHang = tH;
	}
	string getNoiSX() {
		return this->noiSanXuat;
	}
	void setNoiSX(string noiSX) {
		this->noiSanXuat = noiSX;
	}
	string getMauSac() {
		return this->mauSac;
	}
	void setMauSac(string mauSac) {
		this->mauSac = mauSac;
	}
	float getGiaBan() {
		return this->giaBan;
	}
	void setGiaBan(float giaBan) {
		this->giaBan = giaBan;
	}
	string getNgayNhap() {
		return this->ngayNhapKho;
	}
	void setNgayNhap(string ngayNhap) {
		this->ngayNhapKho = ngayNhap;
	}
	int getSoLuongHienThi() {
		return this->soLuongHienThi;
	}
	void setSoLuongHienThi(int soLuongHienThi) {
		this->soLuongHienThi = soLuongHienThi;
	}
	int getSoLuongTonKho() {
		return this->soLuongTonKho;
	}
	void setSoLuongTonKho(int soLuongTonKho) {
		this->soLuongTonKho = soLuongTonKho;
	}

	void docDuLieu(int& nHH, ifstream& ifs) {
		string _maHang;
		getline(ifs, _maHang);
		if (_maHang == "") {
			return;
		}
		else {
			this->maHang = catChuoi(_maHang, 9);
			string _tenHang;
			getline(ifs, _tenHang);
			this->tenHang = catChuoi(_tenHang, 10);
			string _noiSX;
			getline(ifs, _noiSX);
			this->noiSanXuat = catChuoi(_noiSX, 14);
			string _mauSac;
			getline(ifs, _mauSac);
			this->mauSac = catChuoi(_mauSac, 9);
			string _giaBan;
			getline(ifs, _giaBan);
			this->giaBan = stringSangFLOAT(catChuoi(_giaBan, 9));
			string _ngayNhap;
			getline(ifs, _ngayNhap);
			this->ngayNhapKho = catChuoi(_ngayNhap, 15);
			string _sLHienThi;
			getline(ifs, _sLHienThi);
			this->soLuongHienThi = stringSangINT(catChuoi(_sLHienThi, 19));
			string _sLTonKho;
			getline(ifs, _sLTonKho);
			this->soLuongTonKho = stringSangINT(catChuoi(_sLTonKho, 18));
			string key;
			getline(ifs, key);
			if (key == "") nHH++;
		}
	}
	void ghiDuLieu(ofstream& ofs) {
		ofs << "Ma hang: " << this->maHang << endl;
		ofs << "Ten hang: " << this->tenHang << endl;
		ofs << "Noi san xuat: " << this->noiSanXuat << endl;
		ofs << "Mau sac: " << this->mauSac << endl;
		ofs << "Gia ban: " << this->giaBan << endl;
		ofs << "Ngay nhap kho: " << this->ngayNhapKho << endl;
		ofs << "So luong hien thi: " << this->soLuongHienThi << endl;
		ofs << "So luong ton kho: " << this->soLuongTonKho << endl << endl;
	}
	void hienThi() {
		cout << setw(9) << left << this->maHang;
		cout << setw(18) << left << this->tenHang;
		cout << setw(13) << left << this->noiSanXuat;
		cout << setw(8) << left << this->mauSac;
		cout << setw(9) << left << this->giaBan;
		cout << setw(14) << left << this->ngayNhapKho;
		cout << setw(4) << right << this->soLuongHienThi << endl;
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
	}
};