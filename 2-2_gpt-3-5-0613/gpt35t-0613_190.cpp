#include <SQLiteCpp/SQLiteCpp.h>
#include <fstream>

int main() {
    std::fstream dataStream("database.sqlite");
    SQLite::Database database;

    // Load database from the input stream
    database.open(dataStream, SQLite::OPEN_READONLY);

    // You can now query the database and perform other operations

    return 0;
}
