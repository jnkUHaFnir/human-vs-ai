// Load your data into memory first
std::vector<char> data = ...; // Your loaded data

// Open a memory database
sqlite3* db;
sqlite3_open(":memory:", &db);

// Write your data into the memory database
sqlite3_exec(db, "BEGIN IMMEDIATE", 0, 0, 0);
sqlite3_blob* blob;
sqlite3_blob_open(db, "main", "sqlite_master", "sql", 1, 1, &blob);
sqlite3_blob_write(blob, data.data(), data.size(), 0);
sqlite3_blob_close(blob);
sqlite3_exec(db, "COMMIT", 0, 0, 0);

// Use the database as usual
...
