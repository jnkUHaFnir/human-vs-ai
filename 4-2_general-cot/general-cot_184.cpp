#include <iostream>
#include <sqlite3.h>

static int iostreamRead(sqlite3_file* file, void* buffer, int amount, sqlite3_int64 offset) {
    std::iostream* stream = static_cast<std::iostream*>(file->pAppData);
    stream->seekg(offset);
    stream->read(static_cast<char*>(buffer), amount);
    return stream->gcount();
}

static int iostreamWrite(sqlite3_file* file, const void* buffer, int amount, sqlite3_int64 offset) {
    std::iostream* stream = static_cast<std::iostream*>(file->pAppData);
    stream->seekp(offset);
    stream->write(static_cast<const char*>(buffer), amount);
    return amount;
}

static int iostreamClose(sqlite3_file* file) {
    // No action necessary
    return SQLITE_OK;
}

static int iostreamFileSize(sqlite3_file* file, sqlite3_int64* size) {
    std::iostream* stream = static_cast<std::iostream*>(file->pAppData);
    stream->seekg(0, std::ios::end);
    *size = stream->tellg();
    return SQLITE_OK;
}

static int iostreamLock(sqlite3_file* file, int lockType) {
    // Not implemented in this example
    return SQLITE_OK;
}

static int iostreamUnlock(sqlite3_file* file, int lockType) {
    // Not implemented in this example
    return SQLITE_OK;
}

static int iostreamSync(sqlite3_file* file, int flags) {
    // Not implemented in this example
    return SQLITE_OK;
}

static int iostreamOpen(sqlite3_vfs* vfs, const char* path, sqlite3_file* file, int flags, int* outFlags) {
    std::iostream* stream = static_cast<std::iostream*>(vfs->pAppData);
    file->pAppData = stream;
    file->pMethods = &iostreamFileMethods;
    return SQLITE_OK;
}

static sqlite3_io_methods iostreamFileMethods = {
    1,                // iVersion
    iostreamClose,     // xClose
    iostreamRead,      // xRead
    iostreamWrite,     // xWrite
    iostreamFileMethods.xTruncate = nullptr,
    iostreamSync,      // xSync
    iostreamFileSize,  // xFileSize
    iostreamLock,      // xLock
    iostreamLock,      // xUnlock
    iostreamLock,      // xCheckReservedLock
    iostreamLock,      // xFileControl
    iostreamOpen,      // xOpen
    iostreamLock,      // xAccess
    iostreamLock,      // xCheckAccess
    iostreamLock,      // xFullPathname
    nullptr,           // xRandomness
    nullptr,           // xSleep
    nullptr,           // xCurrentTime
};

int main() {
    std::fstream dataStream("database.sqlite");

    // Create a custom VFS with the std::iostream
    sqlite3_vfs* customVfs = new sqlite3_vfs();
    customVfs->iVersion = 3;
    customVfs->zName = "iostream_vfs";
    customVfs->pAppData = &dataStream;

    // Register the custom VFS
    sqlite3_vfs_register(customVfs, 1);

    // Use sqlite3_open_v2 with the custom VFS
    sqlite3* db = nullptr;
    int rc = sqlite3_open_v2("iostream_vfs::memory", &db, SQLITE_OPEN_READWRITE, "iostream_vfs");
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    // Use the database as needed

    // Close the database
    sqlite3_close(db);

    // Unregister the custom VFS and clean up
    delete customVfs;

    return 0;
}
