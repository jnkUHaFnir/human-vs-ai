    #include <string>
    #include <iostream>
    #include <stdio.h>
    
    std::string exec(char* cmd) {
    	FILE* pipe = popen(cmd, "r");
    	if (!pipe) return "ERROR";
    	char buffer[128];
    	std::string result = "";
    	while(!feof(pipe)) {
    		if(fgets(buffer, 128, pipe) != NULL)
    			result += buffer;
    	}
    	pclose(pipe);
    	return result;
    }