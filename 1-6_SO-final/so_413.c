    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    extern char **environ;	/* see environ(7) */
    
    int
    main(void)
    {
    	char *argv_exec[] = {
    		"/usr/bin/xfce4-terminal",
    		"--geometry",
    		"480x320",
    		"-x",
    		"./gestore",
    		NULL };
    
    	/*
    	 * Structure to drive search for a few variables present in
    	 * current environment, and construct a new, minimal, environment
    	 * containing just those values. Use the direct value from the
    	 * current process's environ variable to set "value" (the string
    	 * of the form "NAME=VALUE"). Just add more entries to nv to handle
    	 * more variables; the code below will adjust sizes.
    	 *
    	 * Any value missing in the environment will be an error.
    	 */
    	struct {
    		char *name;
    		char *value;
    	} nv[] = {
    		{ "DISPLAY", NULL },
    		{ "SESSION_MANAGER", NULL }
    	};
    
    	/* size new_envp to have one more entry than nv */
    	char *new_envp[sizeof(nv) / sizeof(nv[0]) + 1];
    
    	char **e;
    	int i, error_flag;
    	pid_t pid;
    
    	/*
    	 * For each variable needed...
    	 */
    	for (i = 0; i < sizeof(nv) / sizeof(nv[0]); i++) {
    		/* ...search in current environment */
    		for (e = environ; *e; e++) {
    			size_t slen = strlen(nv[i].name);
    			if (strncmp(*e, nv[i].name, slen) == 0) {
    				nv[i].value = *e;
    				break;
    			}
    		}
    	}
    
    	/*
    	 * Check that we found all values, setting up new_envp as we go.
    	 */
    	error_flag = 0;
    	for (i = 0; i < sizeof(nv) / sizeof(nv[0]); i++) {
    		if (nv[i].value == NULL) {
    			(void) fprintf(stderr, "%s not set in environment\n",
    						nv[i].name);
    			error_flag = 1;
    		} else {
    			new_envp[i] = nv[i].value;
    		}
    	}
    	if (error_flag) {
    		return 1;
    	}
    	new_envp[i] = NULL;
    
    	/* very minimal fork/exec processing */
    
    	pid = fork();
    
    	if (pid == -1) {
    		perror("fork");
    		return 1;
    	}
    	if (pid == 0) {
    		(void) execve(argv_exec[0], argv_exec, new_envp);
    		/*
    		 * If execve succeeded, the invoked program has
    		 * replaced this process, and will either run or
    		 * (presumably) report its own errors. If we're
    		 * still in control, the execve failed, so print
    		 * an error and exit.
    		 */
    		perror(argv_exec[0]);
    		return 1;
    	} else {
    		if (wait(0) != pid) {
    			perror("wait");
    			return 1;
    		}
    	}
    
    	return 0;
    }