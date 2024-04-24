
This will allow you to access any arguments passed to your program. In your case, you are looking for a SIP phone number to dial.

Another thing to note is that you are missing a closing `"` in the system command line that you are trying to execute. It should look like this:

```c++
std::string cmd = "start \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial " + std::string(argv[1]+4);
