#pragma once
#include "IDataAccess.h"

class DatabaseAccess : public IDataAccess
{
public:
	// album related
	const std::list<Album> getAlbums();
	const std::list<Album> getAlbumsOfUser(const User& user);
	void createAlbum(const Album& album);
	void deleteAlbum(const std::string& albumName, int userId);
	bool doesAlbumExists(const std::string& albumName, int userId);
	Album openAlbum(const std::string& albumName);
	void closeAlbum(Album& pAlbum);
	void printAlbums();

	// picture related
	void addPictureToAlbumByName(const std::string& albumName, const Picture& picture);
	void removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName);
	void tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId);
	void untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId);

	// user related
	void printUsers();
	User getUser(int userId);
	void createUser(User& user);
	void deleteUser(const User& user);
	bool doesUserExists(int userId);


	// user statistics
	int countAlbumsOwnedOfUser(const User& user);
	int countAlbumsTaggedOfUser(const User& user);
	int countTagsOfUser(const User& user);
	float averageTagsPerAlbumOfUser(const User& user);

	// queries
	User getTopTaggedUser();
	Picture getTopTaggedPicture();
	std::list<Picture> getTaggedPicturesOfUser(const User& user);

	bool open();
	void close();
	void clear();

private:
	sqlite3* db;
};

