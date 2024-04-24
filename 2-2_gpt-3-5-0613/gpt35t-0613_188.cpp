#include <sqlite3pp.h>
#include <iostream>

int main() {
  std::fstream dataStream("database.sqlite", std::ios::in | std::ios::binary);
  std::stringstream buffer;
  
  // Read data from the stream into a stringstream
  buffer << dataStream.rdbuf();
  
  // Get the content from the stringstream
  std::string data = buffer.str();

  // Create a memory VFS for SQLite
  sqlite3_vfs* pVfs = sqlite3_vfs_find(NULL);
  sqlite3_vfs* pMemVfs = sqlite3_vfs_find("memvfs");
  if (pMemVfs == NULL) {
    sqlite3_vfs_memvfs_register(pVfs);
    pMemVfs = sqlite3_vfs_find("memvfs");
  }

  // Register the std::iostream with the VFS
  sqlite3_vfs_iofstream_register(pMemVfs);

  // Open the database using the registered VFS and the std::iostream
  sqlite3* pDatabase = NULL;
  if (sqlite3_open_v2("filename=:iostream:", &pDatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "memvfs") != SQLITE_OK) {
    std::cerr << "Failed to open database: " << sqlite3_errmsg(pDatabase) << std::endl;
    return 1;
  }

  // Do something with the database ...

  // Close the database
  sqlite3_close(pDatabase);

  return 0;
}
