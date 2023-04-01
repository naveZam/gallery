#pragma once
#include "DatabaseAccess.h"

class DataAccessTest
{
public:
	void buildDB();
	void addUser(int id, std::string name, int idPic);

private:
	DatabaseAccess dataAccessTest;
};

