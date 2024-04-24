This will print the correct answer.

Moreover, this could lead to segmentation fault if a word length crosses 50 characters. You should take care of it in a proper way.

Note: This code assumes that no word in the input string will have a size of more than 50 characters. If a word exceeds this length, the code will result in undefined behavior. Also, don't forget to free memory after you have done using it. It will avoid memory leaks.
