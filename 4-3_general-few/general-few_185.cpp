#include <iostream>
#include <fstream>
#include "sqlite3.h"
#include "see.h"

int main() {
    std::ifstream dataStream("database.sqlite", std::ios::binary);
    
    SEEConfig conf;
    SEEConfigInit(&conf);
    conf.zPassphrase = "your_passphrase";
    
    sqlite3 *db;
    sqlite3_open_v2("file:data?fts=0&key=see&cipher=aes-256-cbc", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_URI, &conf);
    
    return 0;
}
