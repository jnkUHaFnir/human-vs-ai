#include <sqlite_modern_cpp.h>
#include <fstream>
#include <sstream>

int main() {
  std::ifstream input("database.sqlite", std::ios::binary);

  // Read the entire contents of the file into an std::stringstream
  std::stringstream buffer;
  buffer << input.rdbuf();

  // Construct a custom VFS that overrides xOpen to read from the stringstream
  sqlite::vfs customVfs;
  customVfs.xOpen = [](sqlite3_vfs* vfs, const char* name, sqlite3_file* file, int flags, int* outFlags) {
    // Read from the stringstream instead of a file on disk
    sqlite3_int64 size = buffer.str().size();
    sqlite3_mem_file* memFile = static_cast<sqlite3_mem_file*>(file);
    memFile->pBuf = new char[size];
    memFile->sz = size;
    memcpy(memFile->pBuf, buffer.str().data(), size);
    return SQLITE_OK;
  };

  // Use the custom VFS to open the database
  sqlite::database db(":memory:", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, &customVfs);

  // ...
}
