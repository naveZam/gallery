#include "DatabaseAccess.h"
#include <io.h>

bool DatabaseAccess::open()
{
    std::string dbFileName = "galleryDB.sqlite";
    int file_exist = _access(dbFileName.c_str(), 0);
    int res = sqlite3_open(dbFileName.c_str(), &db);

    if (res != SQLITE_OK) {
        db = nullptr;
        std::cout << "Failed to open DB" << std::endl;
        return false;
    }

    if (file_exist != 0) {
        // init database
    }
    return true;
}
