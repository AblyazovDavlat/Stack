#include "StdAfx.h"
#include "TParser.h"
bool TParser::IsNumber(char elem)
{
    if ( (elem == '0' ) || (elem == '1') || (elem == '2') || (elem == '3') || (elem == '4') || (elem == '5') || (elem == '6') || (elem == '7') || (elem == '8') || (elem == '9'))
		return true;
	else 
		return false;
}
bool TParser::IsOper (char elem)
{
    if ( (elem == '+') || (elem == '-') || (elem == '*') || (elem == '/') || (elem == '^') || (elem == '=') )
		return true;
	else 
		return false;
}
int TParser::Priority (char elem)
{ int i;
     switch (elem) {
		 /*case ')' : i = 1; break;*/
		 case '(' : i = 1; break;
		 case '+' : i = 2; break;
		 case '-' : i = 2; break;
		 case '*' : i = 3; break;
		 case '/' : i = 3; break;
		 case '^' : i = 4; break;
		 case '=' : i = -1; break;
	 }
	 return i;
}
void TParser:: IntToPost() {
	int i =0; int j = 0;
    st_c.Push('=');
	while (inf[i] != '\0')
	{
		if (IsNumber(inf[i]))
		{
			post[j] = inf[i];
			j++;
		}
		else
			if (inf[i] == '(')
				st_c.Push(inf[i]);
			else 
				if (inf[i] == ')')
				{
					char tmp = st_c.Pop();
					while (tmp!='(')
					{
						post[j] = tmp;
						j++;
						tmp = st_c.Pop();
					}
				}
				else
					if(IsOper(inf[i]))
					{
						char tmp = st_c.Pop();
						while (Priority(tmp)>=Priority(inf[i]))
						{
							post[j] = tmp;
							j++;
							tmp = st_c.Pop();
						}
						st_c.Push(tmp);
						st_c.Push(inf[i]);
					}
					i++;}
}

/*void TParser::IntToPost()
{
	int i=0,j=0; 
	st_c.Push('=');
    while (inf[i] != '\0')
       {
          if(IsNumber(inf[i]))   
		  { post [j] = inf [i] ;
             j++ ;}
          else 
          if (inf[i] =='(')
          { st_c.Push(inf[i]);}
          else if(inf [i] ==')')
             { char tmp = st_c.Pop();
               while ( tmp!='(')
                  { post [j] = tmp;
                    j++;
                    tmp = st_c.Pop();
                  } 
             }
          else if(IsOper(inf[i]))
             {
		        char tmp = st_c.Pop();
                while (Priority (tmp) >= Priority (inf[i]))
                  { post [j] = tmp;
                    j++;
                    tmp= st_c.Pop();
                  }
        st_c.Push(tmp);
        st_c.Push(inf[i]);}
		  i++;}
	}
	*/

/*ostream& operator<<(ostream &ostr,const TParser &s)
{
	int i=0;
	while (i!=' ')
	{ ostr<<inf[i];
	i++;}
	return ostr;
}*/
