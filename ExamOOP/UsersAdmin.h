#pragma once

namespace  HearderFiles {

	class Admin : public Users
	{
	public:
		Admin(string adminName, string adminPassword);


		friend void writeToFileAdmin(Admin admin);
	};

	Admin::Admin(string adminName, string adminPassword)
		:Users(adminName, adminPassword)
	{

	}

}