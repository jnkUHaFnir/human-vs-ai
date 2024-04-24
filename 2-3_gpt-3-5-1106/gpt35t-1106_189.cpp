#include <sqlite3.h>
#include <iostream>
#include <sstream>
#include "SQLiteCpp/SQLiteCpp.h"

int main() {
    // Create a std::stringstream and write some data to it
    std::stringstream dataStream;
    dataStream << "create table test (id integer, name text);"
               << "insert into test values (1, 'test1');"
               << "insert into test values (2, 'test2');";

    // Create a SQLite database using SqliteCpp and open it from the stream
    SQLite::Database db(":memory:", SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE);
    db.open(dataStream);

    // Perform some queries on the database
    SQLite::Statement query(db, "select * from test");
    while (query.executeStep()) {
        int id = query.getColumn(0);
        std::string name = query.getColumn(1);
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }

    return 0;
}
