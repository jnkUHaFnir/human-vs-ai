// Define your custom VFS
sqlite3_vfs myvfs = {
    ...
    xRead: myvfs_read,
    ...
};

// Register the VFS with SQLite
sqlite3_vfs_register(&myvfs, 1);

// Open the database using the VFS
sqlite3_open_v2("database.sqlite", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "myvfs");

// Implement the xRead method to read data from an input stream
int myvfs_read(sqlite3_file* pFile, void* pBuf, int iAmt, sqlite3_int64 iOfst) {
    std::istream* pStream = (std::istream*)pFile->pAppData;
    pStream->seekg(iOfst);
    pStream->read((char*)pBuf, iAmt);
    return pStream->gcount();
}
std::ifstream dataStream("database.sqlite");
sqlite3_vfs myvfs = {
    ...
    xRead: myvfs_read,
    ...
};
myvfs.pAppData = &dataStream; // set pAppData to point to the stream
sqlite3_vfs_register(&myvfs, 1);
sqlite3_open_v2("database.sqlite", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "myvfs");
