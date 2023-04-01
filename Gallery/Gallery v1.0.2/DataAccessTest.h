#pragma once
#include "DatabaseAccess.h"

class DataAccessTest
{
public:
	void buildDB();
	void addUser(int id, std::string name, int idPic);
	void updatePicture(Picture pic, std::string newName);
	void deleteUser(User user);

private:
	DatabaseAccess dataAccessTest;
};

