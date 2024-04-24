#include <iostream>
#include <stdio.h>

int main() {
   std::string cmd = "ls"; // replace this with your command
   std::string result = "";
   FILE* pipe = popen(cmd.c_str(), "r");
   if (!pipe) {
      std::cerr << "Error: popen() failed" << std::endl;
      return 1;
   }
   char buffer[128];
   while (fgets(buffer, 128, pipe) != NULL) {
      result += buffer;
   }
   pclose(pipe);
   std::cout << "Output: " << result << std::endl;
   return 0;
}
