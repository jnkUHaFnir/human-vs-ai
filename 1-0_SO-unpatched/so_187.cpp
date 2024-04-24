    void openConnection(std::shared_ptr<std::iostream> stream) {
    	sqlite3* ptr = nullptr;
    
    	// lexical_cast'ing the pointer to the stream into a string
    	// take extra care that it is a shared_ptr<iostream> and not istream or ostream or whatever
    	std::stringstream filenameStream;
    	filenameStream << reinterpret_cast<const void*>(&stream);
    	if (sqlite3_open_v2(filenameStream.str().c_str(), &ptr, 0, getIostreamVFSName().c_str()) != SQLITE_OK)
    		throw std::runtime_error(sqlite3_errmsg(ptr));
    
    	// ...use 'ptr' here...
    }
    
    // this function registers our custom VFS and return its name
    std::string getIostreamVFSName() {