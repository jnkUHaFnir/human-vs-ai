	#include<stdio.h>
	#include<string.h>
	void main()
	{
		int i,n,count=0;
		char f[30];
		printf("Enter the string. :  ");
		fgets(f, 29, stdin);
		n = strlen(f);
		for(i=0;i<n;i++)
		{
			if(f[i]==f[n-i-2])
			count=count+1;
		}
		if(count==n)
		printf("\n Entered string is Palindrome");
		else
		printf("\n Entered string is NOT Palindrome");
	}