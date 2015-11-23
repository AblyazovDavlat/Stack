#pragma once

template <class T>
class TStack
{
private: 
	int MaxSize;
	int Index;
	T *mas;
public:
    TStack(int _MaxSize) //конструктор
	{ 
		MaxSize = _MaxSize;
		Index = -1;
		if (MaxSize <= 0)
			throw MaxSize;
		mas = new T [MaxSize];
	}
~TStack() //диструктор
	{ 
		delete [] mas;
	}
TStack(const TStack &s) // конструктор копирования
	{
		MaxSize = s.MaxSize;
		Index = s.Index;
		mas = new T[MaxSize];
		for ( int i=0 ; i<MaxSize; i++)
			mas[i] = s.mas[i];
	}

TStack &operator = (const TStack &s) // присваивание
	{
		if (MaxSize != s.MaxSize)
			{
				delete [] mas;
		        MaxSize = s.MaxSize;
				mas = new T [MaxSIze]
		    }
		Index = s.Index;
		for ( int i=0; i<=Index; i++)
			mas[i] = s.mas[i];
		return *this;
	}
//проверка на пустоту
bool IsEmpty ()
   {
	   return (Index == -1);
   }
 //проверка на полноту
bool IsFull ()
   {
	   return (Index == MaxSize-1)
   }
//вернуть элемент с вершины стека
T Top()
   {
	   if (Index<0)
		   throw Index;
	   return mas[Index];
   }

T Pop()
   {
	   if (Index < 0)
		   throw Index;
	   T tmp=mas[Index];
	   Index = Index-1;
	   return tmp;
   }
void Push(const T elem)
   {
	   if (Index >= MaxSize)
		   throw MaxSize;
	   mas[++Index] = elem;
   }
};


