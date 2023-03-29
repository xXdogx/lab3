#include <cstddef>
#include <cctype>
#include "has_repeating_elements.h"

bool has_repeating_elements(const char* source)
{
  const char* s1 = source;
  const char* s2 = source + 1;
  while (*s1 != '\0')
  {
    while (*s2 != '\0')
    {
      if (*s1 == *s2)
      {
        return true;
      }
      s2++;
    }
    s1++;
    s2 = s1 + 1;
  }
  return false;
}
/*bool has_repeating_elements(const char* source1, const char* source2)
{
  const char* s1 = source1;
  const char* s2 = source2;

  while (*s1 != '\0')
  {
    while (*s2 != '\0')
    {
      if (*s1 == *s2)
      {
        return true;
      }
      s2++;
    }
    s1++;
    s2 = source2;
  }
  return false;
}*/