    #include <string>
    #include <vector>
    #include <fstream>
    #include <iostream>
    #include <Windows.h>
    
    using namespace std;
    
    bool FileExists(const std::string& name) {
    	FILE * file;
    	errno_t result = fopen_s(&file, name.c_str(), "r");
    
    	if (result == static_cast<errno_t>(0)) {
    		fclose(file);
    		return true;
    	}
    	else {
    		return false;
    	}
    }
    
    std::vector<std::string> GetFileLines(std::string filePath)
    {
    	const int BUF_SIZE = 1024 * 8;
    
    	vector<string> lines;
    	if (!FileExists(filePath))
    		return lines;
    
    	ifstream input(filePath);
    	if (!input.is_open() || input.fail())
    		return lines;
    
    	char buffer[BUF_SIZE] = "";
    
    	for (input.getline(buffer, BUF_SIZE);; input.getline(buffer, BUF_SIZE))
    	{
    		if (strlen(buffer))
    			lines.push_back(buffer);
    
    		if (!input.eof() && input.fail())
    			throw new exception("GetFileLines input failure. Possibly encountered a line bigger than the buffer.");
    
    		if (input.eof())
    			break;
    	}
    
    	input.close();
    	return lines;
    }
    
    
    int wmain() {
    
    	vector<string> quizLines = GetFileLines("c:\\quiz.txt");
    
    	if (quizLines.size() == 5) {
    		string question = quizLines[0];
    		string answer1 = quizLines[1];
    		string answer2 = quizLines[2];
    		string answer3 = quizLines[2];
    		string answer4 = quizLines[2];
    
    		// Your code begins here
    		std::cout << "Here's Question 2 now for " << char(156) << "200" << endl;
    		Sleep(2000);
    
    		PlaySound(TEXT("Millionaire/£100Play.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    		std::cout << question << endl;
    		Sleep(2000);
    		std::cout << "A: " << answer1 << endl;
    
    		// Rest of your code with changes to use answer# variables should follow
    	}
    	else {
    		std::cout << "Could not load quiz from external file. Cannot continue." << endl;
    	}
    }