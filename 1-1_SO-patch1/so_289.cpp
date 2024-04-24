    for (auto it = v.begin(); v != end(); )   // no end() - 1 -- may not be legal!
    {
      bool comparison = false;
      for (std::size_t n = 0; it + n != v.end(); ++n)
      {
        if (n == 0) continue;
        if (strcmp(*it, *(it + n)) == 0)
        {
          comparison = true;
          break;
        }
      }
      if (comparison) { it = v.erase(it); } // crucial: assign a valid iterator to `it`
      else            { ++it; }
    }