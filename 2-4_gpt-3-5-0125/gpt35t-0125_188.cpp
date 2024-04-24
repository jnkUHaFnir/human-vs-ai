#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    sqlite3_open(":memory:", &db);

    std::string data = "CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT);";
    sqlite3_exec(db, data.c_str(), NULL, 0, NULL);

    // Read data from std::istream and insert into the database
    std::string line;
    while (std::getline(std::cin, line)) {
        data = "INSERT INTO test (name) VALUES ('" + line + "');";
        sqlite3_exec(db, data.c_str(), NULL, 0, NULL);
    }

    // Retrieve data from the database and write to std::ostream
    data = "SELECT name FROM test;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, data.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << sqlite3_column_text(stmt, 0) << std::endl;
    }
    sqlite3_finalize(stmt);

    sqlite3_close(db);

    return 0;
}
