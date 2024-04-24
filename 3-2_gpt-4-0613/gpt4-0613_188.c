
This will register a new VFS that uses your iostream for every operation that SQLite tries to perform on the filesystem.

Keep in mind this is non-trivial because the SQLite VFS API is quite big and some of the methods are not well documented, you should understand what each method does, when it's called and what is expected from it. 

Moreover, you need to make sure that your std::iostream-based implementation meets the thread safety and serialization requirements of SQLite.

Such an implementation would be very complex and fragile. If you are not careful, you may discover bugs only weeks or months down the line when it fails on some obscure edge case. An alternative could be to load the data into a memory database instead, which is natively supported by SQLite.
