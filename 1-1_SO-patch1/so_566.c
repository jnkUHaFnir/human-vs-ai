    int8_t strcmp (const uint8_t* s1, const uint8_t* s2)
    {
      while (*s1 != '\0')
      {
        if (*s1 != *s2)
        {
          break;
        }
    	else
    	{
          s1++; 
          s2++;
    	}
      }
      return (int8_t)( (int16_t)*s1 - (int16_t)*s2 );