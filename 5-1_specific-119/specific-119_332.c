
By using `std::forward` in your constructor, you can forward the arguments without creating temporary objects, allowing for efficient construction of objects directly in-place within the message buffer.
