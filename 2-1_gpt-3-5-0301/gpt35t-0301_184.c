std::istringstream sqlScript("SELECT * FROM Foo WHERE Bar = ?");
int barValue = 42;
auto rows = db->query(sqlScript, barValue);
std::ifstream file("database.sqlite");
cppdb::sqlite3::connection db(file);
auto result = db << "SELECT * FROM Foo WHERE Bar = ?" << 42;
