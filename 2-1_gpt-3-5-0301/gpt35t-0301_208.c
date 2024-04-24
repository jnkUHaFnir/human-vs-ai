if (access(program_name, X_OK) == -1) {
  // File does not exist or is not executable, handle error
}
int status = system(runProgram);
if (status == -1) {
  // Failed to execute command, handle error
}
else if (WIFEXITED(status)) {
  int exit_status = WEXITSTATUS(status);
  if (exit_status != 0) {
    // Command execution failed, handle error
  }
}
else {
  // Command execution failed, handle error
}
