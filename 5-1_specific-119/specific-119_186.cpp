#include <iostream>
#include <fstream>
#include <string>
#include <sqlite3.h>

// Custom VFS implementation for handling iostream
static std::iostream* g_dataStream = nullptr;

static int iostreamRead(sqlite3_file *pFile, void *zBuf, int iAmt, sqlite3_int64 iOfst) {
    g_dataStream->seekg(iOfst);
    g_dataStream->read(static_cast<char*>(zBuf), iAmt);
    return g_dataStream->gcount();
}

static int iostreamWrite(sqlite3_file *pFile, const void *zBuf, int iAmt, sqlite3_int64 iOfst){
    g_dataStream->seekp(iOfst);
    g_dataStream->write(static_cast<const char*>(zBuf), iAmt);
    return iAmt;
}

static int iostreamClose(sqlite3_file *pFile){
    return SQLITE_OK;
}

static int iostreamOpen(sqlite3_vfs *pVfs, const char *zName, sqlite3_file *pFile, int flags, int *pOutFlags){
    pFile->pMethods = new sqlite3_io_methods;
    pFile->pMethods->xRead = iostreamRead;
    pFile->pMethods->xWrite = iostreamWrite;
    pFile->pMethods->xClose = iostreamClose;
    return SQLITE_OK;
}

int main() {
    // Open the database file using fstream
    std::fstream dataStream("database.sqlite", std::ios::in | std::ios::out | std::ios::binary);

    // Check if the file opened successfully
    if (!dataStream.is_open()) {
        std::cerr << "Error opening the database file." << std::endl;
        return 1;
    }

    // Store the dataStream globally for VFS to use
    g_dataStream = &dataStream;

    // Register the custom VFS
    sqlite3_vfs* customVfs = new sqlite3_vfs;
    customVfs->pAppData = NULL;
    customVfs->szOsFile = sizeof(sqlite3_file);
    customVfs->zName = "iostream_vfs";
    customVfs->xOpen = iostreamOpen;
    customVfs->xDelete = nullptr; // Optional, set to nullptr if not needed

    // Register the VFS
    sqlite3_vfs_register(customVfs, 1);

    // Initialize SQLite
    sqlite3* db;
    int rc = sqlite3_open_v2("iostream_vfs::database.sqlite", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "iostream_vfs");

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open the database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Database opened successfully." << std::endl;
    }

    // Close the database and cleanup
    sqlite3_close(db);
    delete customVfs;

    return 0;
}
