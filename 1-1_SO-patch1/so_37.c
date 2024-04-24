    size_t length = strcspn(cAFirst, "\n");
    // …
    for (size_t i = 0; i < length; i++) {
      k = (int)cAFirst[i];
      if ( isupper(k) ) {
        uc++;
      }
      else if ( islower(k) ) {
        lc++;
      }
    }