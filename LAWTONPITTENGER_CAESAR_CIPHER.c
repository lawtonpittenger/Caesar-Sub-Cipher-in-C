/*  Program Author: Lawton Pittenger
    Program Name: LAWTONPITTENGER_CAESAR_CIPHER.c
    Program Purpose: A cipher program that encrypts characters by offsetting them by a
    user-defined integer value.
    4/07/20
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


int readstr(char string[])//Function that collects a string input from the user
{
   char *ift;
   char x;
   int i=0;
   printf("Enter a sentence: ");
   while((x = getchar()) != '\n')
       string[i++] = x;
   ift = string;                                 
   return strlen(string);
}

void encryptCeaser(char ori_str[], char enc_str[], int shift)//Function that actually performs the encryption. 
{
   int z=0;
   char *ift;
   ift = ori_str;
   
   while(*ift!='\0')// Goes through each character one at a time checking if each value is uppercase / lowercase, then assigns the user entered shift to perform the cipher.
   {
       char y = *ift++;
       if(y>=97 && y<=122)
           enc_str[z] = (((y-'a')+shift+26)%26+'a');
       else if(y>=65 && y<=90)
           enc_str[z] = (((y-'A')+shift+26)%26+'A');
       else
           enc_str[z]=y;
       z++;
   }
   enc_str[z]='\0';
}



int main() //Main function where all my function calls / print statements are located.
{
  char ori_str[20000]; //Preps original string for a 20,000 sized character input from the user
  readstr(ori_str); 
 
  printf("\nEntered string is: "); //Prints user entered string
   char *ift;
   ift = ori_str;
   while(*ift!='\0')
       printf("%c",*ift++);
   char enc_str[20000];
   printf("\n\n");
   printf("Ceaser Cipher: "); //Collects caesar shift from user
   int shift;
   scanf("%d",&shift);
   printf("String to be encrypted: ");
   ift = ori_str;
   while(*ift!='\0')
   printf("%c",*ift++);
   printf("\n\n");
   encryptCeaser(ori_str,enc_str,shift); //Call to my encryption function
   printf("Original string: ");
   ift = ori_str;
   while(*ift!='\0')
   printf("%c",*ift++);
   printf(" --> ");
   printf("Encrypted string: %s\n", enc_str);
   printf("Encrypted string: %s", enc_str);
   printf(" --> ");               //Final print statements
   encryptCeaser(enc_str,ori_str,26-shift);
   printf("Decrypted string: %s\n", ori_str);

   
  

}
