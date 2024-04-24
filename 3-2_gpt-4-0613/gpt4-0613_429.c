
Then use `new_ground_truth_filename` in your code where you were previously using `ground_truth_filename`.

This version of your code will always have a valid array `new_ground_truth_filename`.

Another thing to consider is memory management - if this code can be called repeatedly and often `ground_truth_filename` is not passed in, you'll need to take into account deleting any old dynamically allocated arrays to avoid memory leaks. But that's outside the scope of the current question. 

Please consider using C++ string class (`std::string`), it's more robust, and handles memory management for you. 

Here's equivalent code using `std::string`:

```c++
std::string new_ground_truth_filename;
if (ground_truth_filename == 0)
{
    new_ground_truth_filename = std::string(filename) + ".yaml";
}
else
{
    new_ground_truth_filename = ground_truth_filename;
}
