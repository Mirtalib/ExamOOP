#pragma once


namespace  HearderFiles {

	class Users
	{
	private:
		string _userName;
		string _userPassword;


	public:
		Users(string userName, string userPassword = "");
		string getUserName();
		string getUserPassword();
	};

	Users::Users(string userName, string userPassword)
	{
		_userName = userName;
		_userPassword = userPassword;
	}


	string Users::getUserName() {
		return _userName;
	}

	string Users::getUserPassword() {
		return _userPassword;
	}

}
