#include <iostream>
#include <sqlite3.h>

static int backupDB(sqlite3 *pFrom, sqlite3 *pTo) {
  sqlite3_backup *pBackup = sqlite3_backup_init(pTo, "main", pFrom, "main");
  if (pBackup) {
    sqlite3_backup_step(pBackup, -1);
    sqlite3_backup_finish(pBackup);
  }
  return sqlite3_errcode(pTo);
}

int main() {
  sqlite3 *pFrom;
  sqlite3 *pTo;

  // Open the source database from a file or other source
  sqlite3_open("source.db", &pFrom);

  // Create an in-memory database to use as the destination
  sqlite3_open(":memory:", &pTo);

  // Copy data from the source to the destination
  int rc = backupDB(pFrom, pTo);

  if (rc == SQLITE_OK) {
    std::cout << "Database copied successfully\n";
  } else {
    std::cout << "Database copy failed: " << sqlite3_errmsg(pTo) << "\n";
  }

  // Now you can work with the in-memory database (pTo)

  sqlite3_close(pFrom);
  sqlite3_close(pTo);
}
