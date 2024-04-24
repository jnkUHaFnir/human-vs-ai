I also replaced ASCII integer values by their equivalent char literals for better readability. These will be automatically converted to their ASCII integer values during the comparison, so the logic is the same.

This will solve the problem you're experiencing. You're only comparing each character of the user entered string and checking whether they are uppercase, lowercase or neither.

