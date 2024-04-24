#include <iostream>
#include <fstream>
#include <sstream>
#include <sqlite3.h>

// Custom VFS structure to handle interactions with std::iostream
static int stream_io_read(void *pFile, void *zBuf, int iAmt, int iOfst) {
    std::iostream* stream = reinterpret_cast<std::iostream*>(pFile);
    stream->seekg(iOfst);
    stream->read(reinterpret_cast<char*>(zBuf), iAmt);
    return stream->gcount();
}

static int stream_io_write(void *pFile, const void *zBuf, int iAmt, int iOfst) {
    std::iostream* stream = reinterpret_cast<std::iostream*>(pFile);
    stream->seekp(iOfst);
    stream->write(reinterpret_cast<const char*>(zBuf), iAmt);
    return iAmt;
}

static int stream_io_truncate(void *pFile, sqlite3_int64 size) {
    std::iostream* stream = reinterpret_cast<std::iostream*>(pFile);
    stream->seekp(size);
    stream->widen('\0');
    return 0;
}

static int stream_io_close(void *pFile) {
    return 0;
}

static int stream_io_sync(void *pFile, int flags) {
    return 0;
}

static int stream_io_file_size(void *pFile, sqlite3_int64 *pSize) {
    std::iostream* stream = reinterpret_cast<std::iostream*>(pFile);
    std::streampos currentPos = stream->tellg();
    stream->seekg(0, std::ios::end);
    *pSize = stream->tellg();
    stream->seekg(currentPos);
    return 0;
}

// Custom VFS structure
static sqlite3_io_methods stream_io_methods = {
    1,                              // iVersion
    stream_io_close,                // xClose
    stream_io_read,                 // xRead
    stream_io_write,                // xWrite
    stream_io_truncate,             // xTruncate
    stream_io_sync,                 // xSync
    stream_io_file_size,            // xFileSize
    NULL,                           // xLock
    NULL,                           // xUnlock
    NULL,                           // xCheckReservedLock
    NULL,                           // xFileControl
    NULL,                           // xSectorSize
    NULL,                           // xDeviceCharacteristics
    NULL                            // xShmMap
};

int main() {
    std::fstream dataStream("database.sqlite", std::ios::in | std::ios::out | std::ios::binary);

    if (!dataStream.is_open()) {
        std::cerr << "Failed to open database file." << std::endl;
        return 1;
    }

    sqlite3_vfs* customVfs = new sqlite3_vfs;
    customVfs->pAppData = &dataStream; // Store the std::iostream in pAppData
    customVfs->pMethods = &stream_io_methods;
    
    int rc = sqlite3_vfs_register(customVfs, 1);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to register custom VFS." << std::endl;
        return 1;
    }

    sqlite3* db;
    rc = sqlite3_open_v2("main", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "customVfs");
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Perform SQLite operations with the opened database

    sqlite3_close(db);
    delete customVfs;
    
    return 0;
}
