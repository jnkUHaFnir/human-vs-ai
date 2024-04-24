#include <iostream>
#include <sqlite3.h>

static int streamRead(void *pData, char *zBuf, int iAmt, int iOfst) {
    std::iostream* stream = static_cast<std::iostream*>(pData);
    stream->seekg(iOfst, std::ios_base::beg);
    stream->read(zBuf, iAmt);
    return stream->gcount();
}

static int streamWrite(void *pData, const char *zBuf, int iAmt, int iOfst) {
    std::iostream* stream = static_cast<std::iostream*>(pData);
    stream->seekp(iOfst, std::ios_base::beg);
    stream->write(zBuf, iAmt);
    return iAmt;
}

int main() {
    // Open an in-memory database
    sqlite3* db;
    sqlite3_open(":memory:", &db);

    // Create a custom VFS
    sqlite3_vfs* customVfs = sqlite3_vfs_find(nullptr); // Use the default VFS
    customVfs->iVersion = 2;
    customVfs->pAppData = &std::cout; // Use std::cout as the data stream

    customVfs->xRead = streamRead; // Custom read function
    customVfs->xWrite = streamWrite; // Custom write function

    // Register the custom VFS
    sqlite3_vfs_register(customVfs, 1);

    // Use the database as usual
    // For example, create a table
    sqlite3_exec(db, "CREATE TABLE Test (ID INT, Name TEXT);", nullptr, nullptr, nullptr);

    // Insert some data
    sqlite3_exec(db, "INSERT INTO Test VALUES (1, 'Alice');", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "INSERT INTO Test VALUES (2, 'Bob');", nullptr, nullptr, nullptr);

    // Query the data
    sqlite3_exec(db, "SELECT * FROM Test;", [](void* data, int argc, char** argv, char** azColName) -> int {
        for (int i = 0; i < argc; i++) {
            std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
        }
        return 0;
    }, nullptr, nullptr);

    // Close the database
    sqlite3_close(db);

    return 0;
}
