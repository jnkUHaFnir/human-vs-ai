#include <stdio.h> 
#include <cjson/cJSON.h> // You may need to adjust this include depending on your installation

int main() {
    char *source = "{\"hello\": 42}";
    
    // Here we parse the source into a cJSON object
    cJSON *json = cJSON_Parse(source);
    
    // This is how we get an integer from an object
    int value = cJSON_GetObjectItem(json, "hello")->valueint;
    printf("%d", value);  // output: 42

    cJSON_Delete(json);
 
    return 0;
}
``` 

This is a very basic example and your situation may require more complex manipulation. However, the cJSON library provides a way to manipulate arrays and nested objects as well.

Note: Don't forget to install the cJSON library and include the header file in your project.

This will help avoid potential parsing errors and will make your code cleaner and easier to maintain. And thus, saving you loads of time rather than trying to parse and search in text manually!
