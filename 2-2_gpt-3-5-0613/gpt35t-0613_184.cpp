#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main() {
    std::ifstream databaseFileStream("database.sqlite", std::ios::binary);
    std::stringstream databaseStringStream;
    databaseStringStream << databaseFileStream.rdbuf();

    // Create a database connection
    SQLite::Database database(":memory:", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

    // Load the database from stringstream
    database.exec(databaseStringStream.str());

    // Use the loaded database
    SQLite::Statement query(database, "SELECT * FROM table_name");
    while (query.executeStep()) {
        // Perform your logic on the queried rows
    }

    return 0;
}
