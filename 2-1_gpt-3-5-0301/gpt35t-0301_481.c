char* hello(char* name) {
    char* greeting = malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    return greeting;
}
import ctypes

hello = ctypes.cdll.LoadLibrary('./hello.so')
name = "Frank"
c_name = ctypes.c_char_p(name)
foo = hello.hello(c_name)

print(c_name.value)
print(ctypes.c_char_p(foo).value.decode('utf-8'))
hello.free_string(foo)  # Free the memory allocated in C
void hello(char* name, char* greeting, int max_size) {
    snprintf(greeting, max_size, "Hello, %s!\n", name);
    printf("%s\n", greeting);
}
import ctypes

hello = ctypes.cdll.LoadLibrary('./hello.so')
name = "Frank"
max_size = 100
c_name = ctypes.c_char_p(name)
c_greeting = ctypes.create_string_buffer(max_size)
hello.hello(c_name, c_greeting, max_size)

print(c_name.value)
print(c_greeting.value.decode('utf-8'))
