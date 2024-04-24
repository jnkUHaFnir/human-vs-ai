char cmd[128];

while(fgets(cmd,128,stdin)){
    if(strcmp(cmd, "exit\n") == 0){
        // stop reading input and do something
        break;
    }
    // continue reading input and do something with the input
}
