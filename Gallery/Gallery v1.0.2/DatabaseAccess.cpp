#include "DatabaseAccess.h"
#include "Album.h"
#include "User.h"
#include <io.h>

bool DatabaseAccess::open()
{
    std::string dbFileName = "galleryDB.sqlite";
    int file_exist = _access(dbFileName.c_str(), 0);
    res = sqlite3_open(dbFileName.c_str(), &db);

    if (res != SQLITE_OK) {
        db = nullptr;
        std::cout << "Failed to open DB" << std::endl;
        return false;
    }

    if (file_exist != 0) {
        const char* sqlStatement = "CREATE TABLE USERS (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name TEXT NOT NULL); ";

        char* errMessage = nullptr;
        res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
        if (res != SQLITE_OK)
            return false;

        sqlStatement = "CREATE TABLE ALBUMS (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name TEXT NOT NULL, creation_date TEXT NOT NULL, user_id INT NOT NULL, FOREIGN KEY(user_id) REFERENCES USERS(id));";

        errMessage = nullptr;
        res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
        if (res != SQLITE_OK)
            return false;

        sqlStatement = "CREATE TABLE PICTURES (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name TEXT NOT NULL, location TEXT NOT NULL, creation_date TEXT NOT NULL, album_id INT NOT NULL, FOREIGN KEY(album_id) REFERENCES ALBUMS(id));";

        errMessage = nullptr;
        res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
        if (res != SQLITE_OK)
            return false;

        sqlStatement = "CREATE TABLE TAGS (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, picture_id INT NOT NULL, user_id INT NOT NULL, FOREIGN KEY(picture_id) REFERENCES PICTURES(id), FOREIGN KEY(user_id) REFERENCES USERS(id));";

        errMessage = nullptr;
        res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
        if (res != SQLITE_OK)
            return false;
    }
    return true;
}

void DatabaseAccess::close()
{
    sqlite3_close(db);
    db = nullptr;
}

void DatabaseAccess::clear()
{
}

bool DatabaseAccess::doesAlbumExists(const std::string& albumName, int userId)
{
    return false;
}

Album DatabaseAccess::openAlbum(const std::string& albumName)
{
    return Album();
}

void DatabaseAccess::closeAlbum(Album& pAlbum)
{
}

void DatabaseAccess::printAlbums()
{
}

void DatabaseAccess::addPictureToAlbumByName(const std::string& albumName, const Picture& picture)
{
}

void DatabaseAccess::removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName)
{
}

void DatabaseAccess::tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
}

void DatabaseAccess::untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
}

void DatabaseAccess::printUsers()
{
}

User DatabaseAccess::getUser(int userId)
{
    return User(-1, "");
}

void DatabaseAccess::createUser(User& user)
{
}

void DatabaseAccess::deleteUser(const User& user)
{
}

bool DatabaseAccess::doesUserExists(int userId)
{
    return false;
}

int DatabaseAccess::countAlbumsOwnedOfUser(const User& user)
{
    return 0;
}

int DatabaseAccess::countAlbumsTaggedOfUser(const User& user)
{
    return 0;
}

int DatabaseAccess::countTagsOfUser(const User& user)
{
    return 0;
}

float DatabaseAccess::averageTagsPerAlbumOfUser(const User& user)
{
    return 0.0f;
}

User DatabaseAccess::getTopTaggedUser()
{
    return User(-1, "");
}

Picture DatabaseAccess::getTopTaggedPicture()
{
    return Picture(-1, "");
}

std::list<Picture> DatabaseAccess::getTaggedPicturesOfUser(const User& user)
{
    return std::list<Picture>();
}

const std::list<Album> DatabaseAccess::getAlbums()
{
    return std::list<Album>();
}

const std::list<Album> DatabaseAccess::getAlbumsOfUser(const User& user)
{
    return std::list<Album>();
}

void DatabaseAccess::createAlbum(const Album& album)
{
}

void DatabaseAccess::deleteAlbum(const std::string& albumName, int userId)
{
    std::string str = "DELETE FROM ALBUMS WHERE user_id = " + std::to_string(userId) + "AND name = \"" + albumName + "\";";
    sqlStatement = str.c_str();
    errMessage = nullptr;
    res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
        return;
}
