#include <iostream>
#include <string>
#include <sqlite3.h>

// Custom VFS for std::iostream
static int iostreamOpen(sqlite3_vfs* vfs, const char* zName, sqlite3_file* file, int flags, int* pOutFlags) {
    if (flags & SQLITE_OPEN_MAIN_DB) {
        std::iostream* dataStream = static_cast<std::iostream*>(vfs->pAppData);
        file->pMethods = vfs->pMethods;
        file->pMethods->xOpen(vfs->pMethods, nullptr, file, flags, pOutFlags);
        return SQLITE_OK;
    }
    return SQLITE_CANTOPEN;
}

static int iostreamAccess(sqlite3_vfs* vfs, const char* zName, int flags, int* pResOut) {
    if (flags & SQLITE_ACCESS_EXISTS) {
        *pResOut = 1;
        return SQLITE_OK;
    }
    return SQLITE_CANTOPEN;
}

// Register custom VFS with std::iostream
sqlite3* sqlite3_open_iostream(std::iostream* stream) {
    sqlite3_vfs* customVfs = sqlite3_vfs_find("iostream_vfs");
    if (customVfs == nullptr) {
        customVfs = sqlite3_vfs_find(nullptr);  // Use default VFS
        customVfs = new sqlite3_vfs(*customVfs);
        customVfs->szOsFile = sizeof(std::iostream);
        customVfs->szOsFile += customVfs->szOsFile % sizeof(void*); // Make sure it's aligned
        customVfs->pAppData = stream;
        customVfs->xOpen = iostreamOpen;
        customVfs->xAccess = iostreamAccess;
        customVfs->zName = "iostream_vfs";
        sqlite3_vfs_register(customVfs, true);
    }

    sqlite3* db;
    int rc = sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "iostream_vfs");
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open SQLite database\n";
        return nullptr;
    }

    return db;
}

int main() {
    std::stringstream dataStream;
    dataStream << "CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT);";
    dataStream << "INSERT INTO test (id, name) VALUES (1, 'John');";
    dataStream.seekg(0);

    sqlite3* db = sqlite3_open_iostream(&dataStream);
    if (db) {
        // Query and work with the database as usual
        sqlite3_close(db);
    }

    return 0;
}
