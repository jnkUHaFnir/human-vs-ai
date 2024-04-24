char sess_m[80];
strcpy(sess_m,"SESSION_MANAGER=");
strcat(sess_m,getenv("SESSION_MANAGER"));

char * envp[4];
envp[0]="DISPLAY=:0.0";
envp[1]=sess_m;
envp[2]="PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"; // You may need to set the PATH variable
envp[3]=NULL;
