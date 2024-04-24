#include <fstream>
#include <iostream>
#include <sqlite3iostream.h>

int main() {
    std::ifstream dataStream("database.sqlite", std::ios::binary);
    
    sqlite3::database db(":memory:");
    
    db.exec<sqlite3::load::istream>("main", dataStream);
    
    // Now you can work with the database 'db'
    
    return 0;
}
