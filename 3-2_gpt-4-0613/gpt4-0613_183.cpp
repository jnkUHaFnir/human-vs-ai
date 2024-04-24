sqlite3* db; 
std::fstream dataStream("database.sqlite", std::ios::binary | std::ios::in | std::ios::out);
dataStream.seekg(0, std::ios::end); 
std::size_t size = dataStream.tellg(); 
dataStream.seekg(0, std::ios::beg);
std::vector<char> buffer(size); 
if(dataStream.read(buffer.data(), size))
{
     sqlite3_open_v2(buffer.data(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_MEMORY, NULL);
}
