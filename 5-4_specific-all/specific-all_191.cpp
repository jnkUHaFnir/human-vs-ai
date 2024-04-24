#include <iostream>
#include <fstream>
#include <sqlite3.h>

static int streamIoRead(sqlite3_file* pFile, void* zBuf, int iAmt, sqlite3_int64 iOfst) {
    std::iostream* stream = static_cast<std::iostream*>(pFile->pMethods->pAppData);
    
    stream->seekg(iOfst);
    stream->read(reinterpret_cast<char*>(zBuf), iAmt);

    return stream->gcount();
}

static int streamIoWrite(sqlite3_file* pFile, const void* zBuf, int iAmt, sqlite3_int64 iOfst) {
    std::iostream* stream = static_cast<std::iostream*>(pFile->pMethods->pAppData);

    stream->seekp(iOfst);
    stream->write(reinterpret_cast<const char*>(zBuf), iAmt);
    
    return iAmt;
}

static int streamIoTruncate(sqlite3_file* pFile, sqlite3_int64 size) {
    std::iostream* stream = static_cast<std::iostream*>(pFile->pMethods->pAppData);

    stream->seekp(size);
    stream->truncate();

    return 0;
}

static int streamIoClose(sqlite3_file* pFile) {
    // No need to close stream, let the stream's destructor handle that
    return 0;
}

int main() {
    std::fstream dataStream("database.sqlite", std::ios::in | std::ios::out | std::ios::binary);

    sqlite3_vfs vfs = {0};
    vfs.iVersion = 3;
    vfs.szOsFile = sizeof(std::iostream);
    vfs.mxPathname = 512; // Adjust this according to your needs
    vfs.pMethods = new sqlite3_io_methods({
        1,                        // iVersion
        nullptr,                  // xClose
        streamIoRead,             // xRead
        streamIoWrite,            // xWrite
        nullptr,                  // xTruncate
        streamIoSync,             // xSync
        streamIoFileSize,         // xFileSize
        streamIoLock,             // xLock
        streamIoUnlock,           // xUnlock
        streamIoCheckReservedLock // xCheckReservedLock
    });

    dataStream.seekg(0, std::ios::end);
    sqlite3_open_v2("streamio", &database, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "streamio_vfs");

    // Use the SQLite database as needed

    sqlite3_close(database);

    delete vfs.pMethods;

    return 0;
}
