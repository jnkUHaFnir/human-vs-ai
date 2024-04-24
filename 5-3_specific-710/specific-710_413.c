char sess_m[80];
sess_m[0]='\0'; // Ensure sess_m is an empty string initially
strcat(sess_m,"SESSION_MANAGER=");
strcat(sess_m,getenv("SESSION_MANAGER"));

char * envp[4];
envp[0]="DISPLAY=:0.0";
envp[1]=sess_m;
envp[2]="TERM=xterm"; // You can add more environment variables if required
envp[3]=NULL;
