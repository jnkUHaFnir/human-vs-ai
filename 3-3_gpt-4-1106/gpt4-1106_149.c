This will correctly resize the `meanings` array every time you add a new meaning, without losing the old meanings.

Correctly applying these fixes—particularly fixing the memory management in the `add_meaning` function and ensuring `delete` is used properly—should prevent the crashes you are experiencing.
