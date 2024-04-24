    else if(text[i] == 's' && text[i+1] == 'e'&&   //line: 99
    ... // skipped
    text[i+18] == 't') {
        while (1)//while ALL                        //line: 104
        {
            if(i>=len) {
                break;
            }
            if(text[i] == 'f' && text[i+1] == 'r'&&
                    text[i+2] == 'o'&& text[i+3] == 'm') {
                   while (1) { //while from          //line: 112
                       // Some code skipped
                    }
            } else {
                i++;                                //line: 130
            }

        }
    }
