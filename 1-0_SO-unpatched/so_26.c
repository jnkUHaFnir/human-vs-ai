    int * p = realloc(fake.temp, (fake.count + 1) * sizeof(int));
    if (p) { fake.temp = p; ++fake.count; }
    else   { /* error! But fake was untouched. */ }