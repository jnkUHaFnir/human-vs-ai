std::fstream dataStream("database.sqlite");
std::stringstream dataStringStream;
dataStringStream << dataStream.rdbuf(); // Load data from dataStream into dataStringStream

SQLite::Database db(":memory:", SQLite::OPEN_READONLY); // or any other database file name
db.exec(dataStringStream.str()); // Load dataStringStream into the database

// Now you can query and manipulate the database using SQLiteCpp
