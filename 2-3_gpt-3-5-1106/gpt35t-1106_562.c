
In this example, we use popen() to run the "ls -l" command and capture its output. The result is then read from the pipe and stored in a string variable.

Keep in mind that popen() is a part of the C standard library and not part of the C++ standard library, so its use may be less portable. Additionally, you should be aware of potential security risks when using popen(), as it opens a pipe to a command and can be vulnerable to command injection attacks. Always validate and sanitize any input that is passed to popen() to prevent such attacks.
