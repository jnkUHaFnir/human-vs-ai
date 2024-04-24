#include <SQLiteCpp/SQLiteCpp.h>
#include <fstream>

int main() {
    std::fstream dataStream("database.sqlite", std::ios::binary | std::ios::in);

    // Create a new database connection using the std::iostream
    SQLite::Database db(dataStream);

    // Execute an SQL query
    SQLite::Statement query(db, "SELECT * FROM table_name");
    while (query.executeStep()) {
        // Process the results
        int id = query.getColumn(0);  // Assuming the first column is an integer
        std::string name = query.getColumn(1);  // Assuming the second column is a string
    }

    return 0;
}
