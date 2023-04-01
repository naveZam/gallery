#include "DataAccessTest.h"

void DataAccessTest::buildDB()
{
	dataAccessTest.open();
}

void DataAccessTest::addUser(int id, std::string name, int idPic)
{
	User user = User(id, name);
	Album album = Album(id, ("album-" + name));
	Picture pic1 = Picture(idPic, "pic2-" + name);
	Picture pic2 = Picture(idPic + 1, "pic2-" + name);
	album.addPicture(pic1);
	album.addPicture(pic2);
	dataAccessTest.createUser(user);
	dataAccessTest.createAlbum(album);
}
