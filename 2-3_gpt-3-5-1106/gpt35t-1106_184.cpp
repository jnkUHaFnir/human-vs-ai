#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main() {
    std::stringstream dataStream; // use std::stringstream instead of std::fstream for input data
    dataStream << "CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT);"
               << "INSERT INTO test(id, value) VALUES (1, 'hello');";

    // Open the in-memory database from the std::iostream
    SQLite::Database db(":memory:", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    db.exec(dataStream.str()); // execute SQL statements from the dataStream

    // Query the database
    SQLite::Statement query(db, "SELECT * FROM test");
    while (query.executeStep()) {
        int id = query.getColumn(0);
        std::string value = query.getColumn(1);
        std::cout << "id: " << id << ", value: " << value << std::endl;
    }

    return 0;
}
