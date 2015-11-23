#pragma once
#include "TStack.h"
#include "stdafx.h"
#include <iostream>
#define MaxSize 201
using namespace std;
class TParser
{ 
  char inf[MaxSize];
  char post[MaxSize];
  TStack <char> st_c;
  TStack <double> st_d;
public:
TParser(char *s=NULL ) : st_d(100) , st_c(100)
{
  if (s == NULL) inf[0] = '\0';
  else 
    strcpy(inf , s);
}
bool IsNumber(char elem);
bool IsOper(char elem);
int Priority (char elem);
void IntToPost();
/*& operator<<(ostream &ostr,const TParser &s);*/
};

