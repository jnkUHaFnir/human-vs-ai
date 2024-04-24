#include <iostream>
#include <fstream>
#include <sstream>
#include <sqlite3.h>

class SQLiteStreamWrapper {
public:
    SQLiteStreamWrapper(std::iostream& stream) : stream_(stream) {}

    int openDatabase(sqlite3** db) {
        std::stringstream buffer;
        buffer << stream_.rdbuf();

        int rc = sqlite3_open_v2(":memory:", db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

        if (rc == SQLITE_OK) {
            rc = sqlite3_exec(*db, buffer.str().c_str(), NULL, NULL, NULL);
        }

        return rc;
    }

private:
    std::iostream& stream_;
};

int main() {
    std::ifstream dataStream("database.sqlite");
    if (!dataStream) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    sqlite3* db;
    SQLiteStreamWrapper wrapper(dataStream);

    if (wrapper.openDatabase(&db) != SQLITE_OK) {
        std::cerr << "Error opening database." << std::endl;
        return 1;
    }

    // Use the database as needed

    sqlite3_close(db);

    return 0;
}
