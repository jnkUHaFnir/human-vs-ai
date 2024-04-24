int main(int argc, char* argv[])
{
   if (argc > 1 && _strnicmp(argv[1], "sip:", 4) == 0)
   { // match "sip:" prefix, case insensitive
      std::string cmd = "start \"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial ";
      cmd += std::string(argv[1]+4);
      system(cmd.c_str());
   }
   return 0;
}
