#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main() {
    std::ifstream dataStream("database.sqlite");
    SQLite::Database db(dataStream, SQLite::OPEN_READONLY);

    // Now you can use the SQLite database as usual
    // For example: SQLite::Statement query(db, "SELECT * FROM table");
    // ...

    return 0;
}
