int returnCode = system(runProgram);
if (returnCode == -1) {
  perror("system");
} else {
  printf("Exit status: %d\n", WEXITSTATUS(returnCode));
}
