#include "common.h"

int FetchNextCharacterAndAddToAccumulator(int incomingByte, int accumulator, int* failedTries)
{   
  if (incomingByte!=-1) 
  {
      accumulator=(accumulator*10)+incomingByte;
  };

  (*failedTries)++;

  return accumulator;
}

int AsciiToBinary(int number)
/*this function is for use while reading a number
from the serial stream. It will convert the Ascii for
digit to the binary for the same, and return -1 for all
other input.*/
{
  int tmp=-1;
  if ((number>47) && (number<58)) 
  {
    tmp = number - 48;
  };

  return tmp;
}

