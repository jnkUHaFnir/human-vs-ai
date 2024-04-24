    void splitString(const char *original, const char *delimiter, char ** & buffer, int & numStrings, int * & stringLengths){
        const int lo = strlen(original);
        const int ld = strlen(delimiter);
        if(ld > lo){
            buffer = (void *)0;
            numStrings = 0;
            stringLengths = (void *)0;
            return;
        }
        numStrings = 1;
        for(int i = 0;i < (lo - ld);i++){
            if(strncmp(&original[i], delimiter, ld) == 0) {
                i += (ld - 1);
                numStrings++;
            }
        }
        stringLengths = (int *) malloc(sizeof(int) * numStrings);
        int currentStringLength = 0;
        int currentStringNumber = 0;
        int delimiterTokenDecrementCounter = 0;
        for(int i = 0;i < lo;i++){
            if(delimiterTokenDecrementCounter > 0){
                delimiterTokenDecrementCounter--;
            } else if(i < (lo - ld)){
                if(strncmp(&original[i], delimiter, ld) == 0){
                    stringLengths[currentStringNumber] = currentStringLength;
                    currentStringNumber++;
                    currentStringLength = 0;
                    delimiterTokenDecrementCounter = ld - 1;
                } else {
                    currentStringLength++;
                }
            } else {
                currentStringLength++;
            }
            if(i == (lo - 1)){
                stringLengths[currentStringNumber] = currentStringLength;
            }
        }
        buffer = (char **) malloc(sizeof(char *) * numStrings);
        for(int i = 0;i < numStrings;i++){
            buffer[i] = (char *) malloc(sizeof(char) * (stringLengths[i] + 1));
        }
        currentStringNumber = 0;
        currentStringLength = 0;
        delimiterTokenDecrementCounter = 0;
        for(int i = 0;i < lo;i++){
            if(delimiterTokenDecrementCounter > 0){
                delimiterTokenDecrementCounter--;
            } else if(currentStringLength >= stringLengths[currentStringNumber]){
                buffer[currentStringNumber][currentStringLength] = 0;
                delimiterTokenDecrementCounter = ld - 1;
                currentStringLength = 0;
                currentStringNumber++;
            } else {
                buffer[currentStringNumber][currentStringLength] = (char)original[i];
                currentStringLength++;
            }
        }
        buffer[currentStringNumber][currentStringLength] = 0;
    }