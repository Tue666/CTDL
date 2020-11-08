#pragma once

class Admin {
private:
	string user, password;
public:
	Admin() {}
	Admin(string user, string password) {
		this->user = user;
		this->password = password;
	}
	~Admin() {}

	string getUser() {
		return this->user;
	}
	void setUser(string user) {
		this->user = user;
	}
	string getPass() {
		return this->password;
	}
	void setPass(string pass) {
		this->password = pass;
	}

	void docDuLieu(int& nAD, ifstream& ifs) {
		string user;
		getline(ifs, user);
		if (user == "") {
			return;
		}
		else {
			this->user = catChuoi(user, 6);
			string pass;
			getline(ifs, pass);
			this->password = catChuoi(pass, 10);
			string key;
			getline(ifs, key);
			if (key == "") nAD++;
		}
	}
};