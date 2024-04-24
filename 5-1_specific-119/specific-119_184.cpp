#include <sqlite3.h>
#include <iostream>
#include <sstream>

static int streamVfsOpen(sqlite3_vfs* vfs, const char* zName, sqlite3_file* file, int flags, int* pOutFlags) {
    if (zName && zName[0] != '\0') {
        return SQLITE_CANTOPEN;
    }
    
    std::iostream* stream = static_cast<std::iostream*>(vfs->pAppData);
    file->pMethods = stream->good() ? &((sqlite3_io_methods) {0}) : nullptr;

    if (file->pMethods == nullptr) {
        return SQLITE_CANTOPEN;
    }

    if (pOutFlags) {
        *pOutFlags = flags;
    }

    return SQLITE_OK;
}

static int streamVfsRead(sqlite3_file* file, void* buffer, int amount, sqlite3_int64 offset) {
    std::iostream* stream = static_cast<std::iostream*>(file->pVfs->pAppData);

    stream->seekg(offset);
    stream->read(static_cast<char*>(buffer), amount);

    return stream->gcount();
}

static int streamVfsWrite(sqlite3_file* file, const void* buffer, int amount, sqlite3_int64 offset) {
    // Write operation is not supported in this example
    return SQLITE_IOERR_WRITE;
}

static int streamVfsClose(sqlite3_file* file) {
    // Close operation is no-op in this example
    return SQLITE_OK;
}

static int streamVfsSync(sqlite3_file* file, int flags) {
    // Sync operation is no-op in this example
    return SQLITE_OK;
}

static int streamVfsFileSize(sqlite3_file* file, sqlite3_int64* pSize) {
    std::iostream* stream = static_cast<std::iostream*>(file->pVfs->pAppData);

    std::streampos currentPos = stream->tellg();
    stream->seekg(0, std::ios::end);
    *pSize = stream->tellg();
    stream->seekg(currentPos);

    return SQLITE_OK;
}

static int streamVfsLock(sqlite3_file* file, int lockType) {
    // Lock operation is not supported in this example
    return SQLITE_OK;
}

static int streamVfsUnlock(sqlite3_file* file, int lockType) {
    // Unlock operation is not supported in this example
    return SQLITE_OK;
}

static int streamVfsCheckReservedLock(sqlite3_file* file, int* pResOut) {
    // Check reserved lock is not supported in this example
    return SQLITE_OK;
}

static int streamVfsFileControl(sqlite3_file* file, int op, void* pArg) {
    // File control operation is not supported in this example
    return SQLITE_OK;
}

static int streamVfsSectorSize(sqlite3_file* file) {
    // Sector size operation is not supported in this example
    return 0;
}

static int streamVfsDeviceCharacteristics(sqlite3_file* file) {
    // Device characteristics operation is not supported in this example
    return 0;
}

int main() {
    std::fstream dataStream("database.db", std::ios::in | std::ios::binary);

    sqlite3_vfs customVfs = {
        3,                           // iVersion
        sizeof(std::iostream*),      // szOsFile
        1024,                        // mxPathname
        nullptr,                     // pNext
        "stream_vfs",                // zName
        nullptr,                     // pAppData
        &streamVfsOpen,              // xOpen
        &streamVfsDelete,            // xDelete
        &streamVfsAccess,            // xAccess
        &streamVfsFileSize,          // xFileSize
        &streamVfsLock,              // xLock
        &streamVfsUnlock,            // xUnlock
        &streamVfsCheckReservedLock, // xCheckReservedLock
        &streamVfsFileControl,       // xFileControl
        &streamVfsSectorSize,        // xSectorSize
        &streamVfsDeviceCharacteristics // xDeviceCharacteristics
    };

    customVfs.pAppData = &dataStream;

    // Register the custom VFS
    sqlite3_vfs_register(&customVfs, 1);

    // Now you can use sqlite3_open_v2 with "stream_vfs" as the VFS name
    sqlite3* db;
    int rc = sqlite3_open_v2("filename.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "stream_vfs");

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Use the database...

    // Don't forget to close the database connection
    sqlite3_close(db);

    return 0;
}
