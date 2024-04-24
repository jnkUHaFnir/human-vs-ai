            capacity *= 2;
            newString = (char*)malloc(capacity*sizeof(char));
            strcpy( newString, inputString );
            free(inputString);
            inputString = newString;