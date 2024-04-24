#include <iostream>
#include <fstream>

#include "sqlite3.h"

int streamRead(void *file, void *buffer, int amount, int offset) {
    std::istream* stream = static_cast<std::istream*>(file);
    stream->seekg(offset);
    stream->read(static_cast<char*>(buffer), amount);
    return stream->gcount();
}

int main() {
    std::ifstream dataStream("database.sqlite");

    // Initialize SQLite
    sqlite3_initialize();

    sqlite3_vfs* customVfs = new sqlite3_vfs();
    customVfs->zName = "iostream_vfs";
    customVfs->pAppData = &dataStream;
    customVfs->xRead = streamRead;

    sqlite3_vfs_register(customVfs, 1);

    sqlite3* db;
    int rc = sqlite3_open_v2("iostream_vfs::/database.sqlite", &db, SQLITE_OPEN_READWRITE, "iostream_vfs");

    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Database opened successfully." << std::endl;
        // Work with the database as needed
        sqlite3_close(db);
    }

    delete customVfs;
    sqlite3_shutdown();

    return 0;
}
