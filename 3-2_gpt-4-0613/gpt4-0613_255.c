In the above code, the next node is copied over to the current node and then the next node is deleted. We are essentially deleting the next node.

This approach does not handle the deletion of last node (since the last node has no next node). For your case, 
you would need to decide what's your course of action is when you want to delete the last node. One option might be to set its value to some kind of flag indicating it's been logically deleted or removed.
