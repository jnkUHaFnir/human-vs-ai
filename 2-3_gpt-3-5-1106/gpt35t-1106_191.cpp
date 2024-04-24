#include "sqlite_modern_cpp.h"
#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputStream("database.sqlite", std::ios::binary);
  
  // Use the sqlite_modern_cpp library to open the database from the input stream
  sqlite::database db(":memory:", sqlite::OPEN_READWRITE | sqlite::OPEN_CREATE);
  db << "PRAGMA case_sensitive_like=ON";

  db.open_blob("main", "sqlite_schema");

  // Now you can execute SQLite queries using the db object
  //...
  
  return 0;
}
