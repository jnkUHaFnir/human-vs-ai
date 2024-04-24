     #include <stdio.h>
     
     #define PLAYERS_NO  19
    
    typedef struct  
    {
         char name[20+1];
         char lastName[25+1];
         int atbat;
         int hits;
         int walks;
         int runs;
         float batavg;
    } Profile;
    
    
    
    int main(int argc, char** argv)
    {
    	Profile stats[PLAYERS_NO];
    	int i;
    	FILE* dataFile;
    	
    	int playerNo;
    	Profile tmpProfile;
    	int games = 0;
    	
    	
    	for(i=0; i<PLAYERS_NO; ++i)
    		memset(&stats, 0, sizeof(Profile));
    		
    	dataFile = fopen("team.txt", "r");
    	if ( dataFile == NULL )
    	{
    		fprintf(stderr, "Can't read file team!\n");
    		exit(1);    
         }
    
         for(i=0; i<PLAYERS_NO; ++i, ++games)
    	 {
            fscanf(dataFile, "%d", &playerNo);
    		if ( playerNo <0 || playerNo > PLAYERS_NO )
    		{
    		   fprintf(stderr, "Player number out of range\n");
    		   continue;
    		}
    		
    		fscanf(dataFile, "%s %s %d %d %d %d", 
    		    &tmpProfile.name,
    			&tmpProfile.lastName,
    			&tmpProfile.atbat,
    			&tmpProfile.hits,
    			&tmpProfile.walks,
    			&tmpProfile.runs);
    		
    		if ( stats[playerNo].name[0] != '\0' && stats[playerNo].lastName[0] != '\0' )
    		{
    			if ( strcmp(stats[playerNo].name, tmpProfile.name) != 0 || 
    				 strcmp(stats[playerNo].lastName, tmpProfile.lastName) != 0 )
    			{
    				fprintf(stderr, "Strange, player number does not correspond to previously set name.\n");
    				continue; /* really? */
    			}
    		}
    		else
    		{
    		    strcpy(stats[playerNo].name, tmpProfile.name);
    			strcpy(stats[playerNo].lastName, tmpProfile.lastName);
    		}
    				
    		stats[playerNo].atbat += tmpProfile.atbat;
    		stats[playerNo].hits += tmpProfile.hits;
    		stats[playerNo].walks += tmpProfile.walks;
    		stats[playerNo].walks += tmpProfile.walks;
    		stats[playerNo].runs += tmpProfile.runs;
    	}
    	
    	/* exercise: compute the average */
    		
    	return 0;
    }
    		