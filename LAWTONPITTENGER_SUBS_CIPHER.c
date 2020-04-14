/*  Program Author: Lawton Pittenger
    Program Name: LAWTONPITTENGER_SUBS_CIPHER.c
    4/07/20
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle(char *ift , int num)// Method that shuffles the alphabet
{int z, y, x;
srand(time(0));
if(num > 1){
for(x=0; x<num-1; x++){
y = x + rand() / (RAND_MAX/(num-x) + 1);
z = ift[y];
ift[y] = ift[x];
ift[x] = z;}}
}

int main(){
char enckeys[26];
char a;
int x,v;

for(int x=0; x<26; x++){
enckeys[x] = 'a' + x;}
shuffle(enckeys, 26);
printf("Substitution Cipher: \n");
printf("Shuffled alphabet: ");
for(int x=0; x<26; x++){   //Prints shuffled alphabet
printf("%c", enckeys[x]);}
printf("\n\n");

char sentence[1000];// inputs and displays the sentence
printf("Enter a sentence: ");
scanf("%[^\n]%*c",sentence);
printf("Entered string is: %s", sentence);
printf("\n\n");

int cas = strlen(sentence);
char enc_message[cas]; //creates a char array that is the size of the sentence
for(x=0; x<cas; x++){
a = sentence[x];
if(a >= 'a' && a <= 'z'){
enc_message[x] = enckeys[a - 'a'];}
else if(a >= 'A' && a <= 'Z'){
enc_message[x] = enckeys[a - 'A'] - 'a' + 'A';}
else{
enc_message[x] = a;}}



printf("Original String: %s", sentence);
printf(" --> ");    // displays the output
printf("Encrypted string: %s\n", enc_message);

                        
char dec_message[cas];// decrypts the message
for(x=0; x<cas; x++){
a = enc_message[x];
if(a >= 'a' && a <= 'z'){
v = (int)(strchr(enckeys, a) - enckeys);
dec_message[x] = v + 'a';}
else if(a >= 'A' && a <= 'Z'){
a = a + 'a' - 'A';
v = (int)(strchr(enckeys, a) - enckeys);
dec_message[x] = v + 'A';}
else{
dec_message[x] = a;
}
}

printf("Encrypted string: %s", enc_message);
printf(" --> ");        // displays the output
printf("Decrypted string: %s\n", dec_message);
return 0;
}

