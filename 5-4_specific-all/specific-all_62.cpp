void Expression::add_meaning(char *p2c)
{
	if (meanings_ctr < 1) {
		meanings[meanings_ctr] = new char[strlen(p2c) + 1];
		strcpy(meanings[meanings_ctr++], p2c);
	}
	else {
		char** temp_meaning = new char*[meanings_ctr];
		for (int temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
			temp_meaning[temp_ctr] = new char[strlen(meanings[temp_ctr]) + 1];
			strcpy(temp_meaning[temp_ctr], meanings[temp_ctr]);
			delete[] meanings[temp_ctr];
		}
		delete[] meanings;

		meanings = new char*[meanings_ctr + 1];
		for (int temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
			meanings[temp_ctr] = new char[strlen(temp_meaning[temp_ctr]) + 1];
			strcpy(meanings[temp_ctr], temp_meaning[temp_ctr]);
			delete[] temp_meaning[temp_ctr];
		}
		meanings[meanings_ctr] = new char[strlen(p2c) + 1];
		strcpy(meanings[meanings_ctr++], p2c);

		delete[] temp_meaning;
	}
}
