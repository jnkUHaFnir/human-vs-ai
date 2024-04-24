
Note that it's not a good practice to use global `using namespace std;` but for the simplicity of this example it's used.

This program reads an array of strings, each string not exceeding 50 characters, sorts them alphabetically and prints the sorted list. Hope this helps.

Please note that the `char**` type should be interpreted as an array of C-style strings. `cin>>` is replaced by `cin.getline()` to get line of strings with spaces. If you want a string without spaces, use `cin >> arr[i];` instead of `cin.getline(arr[i], 50);`.
