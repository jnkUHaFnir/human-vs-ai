		char pass[50] = "";
		printf(" Enter Password : ");
		fgets(pass, 50, stdin);
		pass[strcspn(pass, "\n")] = 0;
		if(0 != strcmp(pass, "aaanc6400")) {
			printf("\n Invalid Password.. Please enter the correct password. \n\n");
			verification();
		}