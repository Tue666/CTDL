#pragma once

class DonHang {
private:
	int soThuTu;
	int n;
	string* maHang;
	int* soLuong;
	float tongTien;
	string tenKhachHang, diaChiKH, soDienThoai, ngayDatHang;
public:
	DonHang() {}
	DonHang(int soThuTu, int n, string* maHang, int* soLuong, float tongTien, string tenKH, string diaChiKH, string soDT, string ngayDatHang) {
		this->soThuTu = soThuTu;
		this->n = n;
		this->maHang = maHang;
		this->soLuong = soLuong;
		this->tongTien = tongTien;
		this->tenKhachHang = tenKH;
		this->diaChiKH = diaChiKH;
		this->soDienThoai = soDT;
		this->ngayDatHang = ngayDatHang;
	}
	~DonHang() {}

	int getSTT() {
		return this->soThuTu;
	}
	void setSTT(int stt) {
		this->soThuTu = stt;
	}
	int getN() {
		return this->n;
	}
	void setN(int n) {
		this->n = n;
	}
	string* getMaHang() {
		return this->maHang;
	}
	int* getSoLuong() {
		return this->soLuong;
	}
	void setSoLuong(int* soLuong) {
		this->soLuong = soLuong;
	}
	void getMaHang(string* maHang) {
		this->maHang = maHang;
	}
	float getTongTien() {
		return this->tongTien;
	}
	void setTongTien(float tongTien) {
		this->tongTien = tongTien;
	}
	string getTenKH() {
		return this->tenKhachHang;
	}
	void setTenKH(string tenKH) {
		this->tenKhachHang = tenKH;
	}
	string getDiaChiKH() {
		return this->diaChiKH;
	}
	void setDiaChiKH(string diaChiKH) {
		this->diaChiKH = diaChiKH;
	}
	string getSDT() {
		return this->soDienThoai;
	}
	void setSDT(string soDT) {
		this->soDienThoai = soDT;
	}
	string getNgayDat() {
		return this->ngayDatHang;
	}
	void setNgayDat(string ngayDat) {
		this->ngayDatHang = ngayDat;
	}

	void docDuLieu(int& nDH, ifstream& ifs) {
		string soThuTu;
		getline(ifs, soThuTu);
		if (soThuTu == "") {
			return;
		}
		else {
			this->soThuTu = stringSangINT(catChuoi(soThuTu, 11));
			this->maHang = new string[20];
			this->soLuong = new int[20];
			this->n = 0;
			while (true) {
				string _maHang;
				getline(ifs, _maHang);
				if (_maHang.find("Ma hang: ") == 0) {
					this->maHang[this->n] = _maHang.substr(9, _maHang.find(",") - 9);
					this->soLuong[this->n] = stringSangINT(_maHang.substr(_maHang.find(",") + 12, _maHang.length() - _maHang.find(",") + 12));
					this->n++;
				}
				else {
					//Tong tien
					this->tongTien = stringSangFLOAT(catChuoi(_maHang, 11));
					break;
				}
			}
			string tenKH;
			getline(ifs, tenKH);
			this->tenKhachHang = catChuoi(tenKH, 16);
			string diaChi;
			getline(ifs, diaChi);
			this->diaChiKH = catChuoi(diaChi, 9);
			string soDT;
			getline(ifs, soDT);
			this->soDienThoai = catChuoi(soDT, 15);
			string ngayDat;
			getline(ifs, ngayDat);
			this->ngayDatHang = catChuoi(ngayDat, 15);
			string key;
			getline(ifs, key);
			if (key == "") nDH++;
		}
	}
	void ghiDuLieu(ofstream& ofs) {
		ofs << "So thu tu: " << this->soThuTu << endl;
		for (int i = 0; i < this->n; i++) {
			ofs << "Ma hang: " << this->maHang[i] << ", so luong: " << this->soLuong[i] << endl;
		}
		ofs << "Tong tien: " << this->tongTien << endl;
		ofs << "Ten khach hang: " << this->tenKhachHang << endl;
		ofs << "Dia chi: " << this->diaChiKH << endl;
		ofs << "So dien thoai: " << this->soDienThoai << endl;
		ofs << "Ngay dat hang: " << this->ngayDatHang << endl << endl;
	}

};