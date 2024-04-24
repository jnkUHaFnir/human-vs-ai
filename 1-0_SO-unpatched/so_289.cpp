    for (auto it = v.begin(); v != end(); ++it)   // no end() - 1 -- may not be legal!
    {
      for (auto jt = it; jt != v.end(); )
      {
        if (jt == it) continue;
        if (strcmp(*it, *jt) == 0)
        {
          jt = v.erase(jt);
        }
        else
        {
          ++jt;
        }
      }
    }