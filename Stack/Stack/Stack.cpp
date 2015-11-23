// Stack.cpp: главный файл проекта.

#include "stdafx.h"
#include "TStack.h"
#include "TParser.h"
#include <iostream>
using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	char polinom[19] ="2+3*((4-5)/6+7)-1";
    TParser Str (polinom);
	Str.IntToPost();
	system("pause");
	return 0;
}
