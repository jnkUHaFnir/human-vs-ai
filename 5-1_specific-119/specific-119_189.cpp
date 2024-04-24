#include <iostream>
#include <sqlite3.h>

static int io_stream_open(sqlite3_vfs *vfs, const char *zName, sqlite3_file *pFile, int flags, int *pOutFlags) {
    std::iostream *stream = static_cast<std::iostream *>(vfs->pAppData);

    pFile->pMethods = sqlite3OsDlSym(stream, "unix", "sqlite3_file"); // Using unix VFS
    return SQLITE_OK;
}

static int io_stream_read(sqlite3_file *pFile, void *zBuf, int iAmt, sqlite3_int64 iOfst) {
    std::iostream *stream = static_cast<std::iostream *>(pFile->pAppData);

    stream->seekg(iOfst);
    stream->read(reinterpret_cast<char *>(zBuf), iAmt);

    return stream->gcount();
}

static int io_stream_write(sqlite3_file *pFile, const void *zBuf, int iAmt, sqlite3_int64 iOfst) {
    // Implement this function if needed
    return SQLITE_IOERR_WRITE;
}

static int io_stream_close(sqlite3_file *pFile) {
    // Implement this function if needed
    return SQLITE_OK;
}

static int io_stream_file_size(sqlite3_file *pFile, sqlite3_int64 *pSize) {
    std::iostream *stream = static_cast<std::iostream *>(pFile->pAppData);

    stream->seekg(0, std::ios::end);
    *pSize = stream->tellg();

    return SQLITE_OK;
}

int main() {
    std::ifstream dataStream("database.sqlite", std::ios::binary);

    sqlite3_vfs vfs = {0};
    vfs.szOsFile = sizeof(std::iostream);
    vfs.mxPathname = 1024;

    vfs.xOpen = io_stream_open;
    vfs.xRead = io_stream_read;
    vfs.xWrite = io_stream_write;
    vfs.xClose = io_stream_close;
    vfs.xFileSize = io_stream_file_size;

    vfs.pAppData = &dataStream;

    sqlite3_vfs_register(&vfs, 1);

    // Now you can use sqlite3_open_v2 with the custom VFS
    sqlite3 *db;
    int rc = sqlite3_open_v2("file:dummy.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "custom_vfs");

    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Do your database operations here

    sqlite3_close(db);
    return 0;
}
