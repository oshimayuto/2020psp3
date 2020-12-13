#include <stdio.h>
#include <string.h>
#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int key_len;
    int text_len;
    int start=0;
    int pos=0;
    int i;
    text_len=strlen(text);
    key_len=strlen(key);
    for(start=0;start<text_len;start++)
    {
        for(i=0;i<key_len;i++)
        {
            if(text[start+i]==key[pos])
            {   pos++;
                if(key_len==pos)
                {
                    return &text[start];
                }
            } else
            {
                break;
            }
            
        }
        pos =0;
    }
    return NULL;

}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
   char table[ALPHABET_LEN];
   int n=0;
   int index;
   int key_len;
   int pos;
   int index_before;
   int text_len;
   index=strlen(key)-1;
   key_len=strlen(key);
   pos=key_len-1;
   text_len=strlen(text);
   while(n<=ALPHABET_LEN)
   {
       table[n]=key_len;
       n++;
   }
   n=0;
   while(n<key_len)
   {
       table[(int)key[n]]=key_len-1-n;
       n++;
   }
   while(index<=text_len)
   {
       while(pos>=0)
       {
           if(text[index]==key[pos])
           {
               if(pos==0)
               {
                   return text+index;
               }
               index--;
               pos--;
           }
           else
           {
               pos=key_len-1;
               break;
           }  
       }
       index_before=index;
       index=index+table[(int)text[index]];
       if(index_before>=index)
       {
           index=index_before+1;
       }
   } 
   return NULL;
}


int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}