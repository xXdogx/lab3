#include <iostream>
#include <cctype>
#include "create_new_string.h"

size_t min_index(const size_t* arr, size_t size)
{
  size_t mn = arr[0]; // индекс минимального элемента массива
  size_t index = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] < mn) {
      mn = arr[i];
      index = i;
    }
  }
  return index;
}

void three_most_repetitive(char* dest, const char* src)
{
  size_t i = 0;
  char ind[3] = { 0 }; // буквы
  size_t mx[3] = { 0 }; // кол-во вх

  while (src[i] != '\0') {
    char current = src[i];
    bool isUnique = true;
    for (size_t j = 0; j < i; ++j) {
      if (src[j] == current) {
        isUnique = false;
        break;
      }
    }
    if (!isUnique) {
      i++;
      continue;
    }
    i++;
    size_t j = i;
    size_t cnt = 1;

    while (src[j] != '\0') {
      if (src[j] == current) {
        cnt++;
      }
      j++;
    }

    size_t mnInd = min_index(mx, 3);
    if (cnt > mx[mnInd]) {
      mx[mnInd] = cnt;
      ind[mnInd] = current;
      while (true) {
        if (mnInd < 2 && current > ind[++mnInd]) {
          std::swap(mx[mnInd], mx[mnInd - 1]);
          std::swap(ind[mnInd], ind[mnInd - 1]);
        }
        else if (mnInd > 0 && current < ind[--mnInd]) {
          std::swap(mx[mnInd], mx[mnInd + 1]);
          std::swap(ind[mnInd], ind[mnInd + 1]);
        }
        else {
          break;
        }
      }
    }
  }

  unsigned short shift = 0;
  for (i = 0; i < 3; ++i) {
    if (mx[i] == 0) {
      shift++;
      continue;
    }
    dest[i - shift] = ind[i];
  }
  dest[i - shift] = '\0';
}