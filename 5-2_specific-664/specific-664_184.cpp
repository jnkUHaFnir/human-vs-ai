#include <iostream>
#include <fstream>
#include "sqlite3.h"
#include "sqlite3stream.h"

int main() {
    std::ifstream dataStream("database.sqlite", std::ios::binary);
    if (!dataStream) {
        std::cerr << "Error opening database file." << std::endl;
        return 1;
    }

    sqlite3 *db;
    int rc = sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    rc = sqlite3_stream_readopen(db, "main", &dataStream);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open stream: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Database is now open and loaded from the stream, you can start operating on it

    sqlite3_close(db);
    
    return 0;
}
