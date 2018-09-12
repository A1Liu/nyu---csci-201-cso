//Homework: Simplify the for condition in getline() as just indicated.

/*
int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 &&
              (c=getchar())!=EOF &&
              c!='\n';
         ++i)
      s[i] = c;
    if (c=='\n') {
      s[i]= c;
      ++i;
    }
    s[i] = '\0';
    return i;
  }
*/

#include <stdio.h>

int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1; ++i) {
      if((c=getchar())==EOF || c=='\n') {
        break;
      }
      s[i] = c;
    }
    if (c=='\n') {
      s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

//Homework: 2-3. Write the function htoi(s), which converts a string of hexadecimal digits (including an option 0x or 0X) into its equivalent integer value.
//The allowable digits are 0 through 9, a through f, and A through F.

int htoi(char s[]) {
  int i, n=0, c = 0,c1,c2;
  for( i = 0;(c1 = ((c=s[i]) >='0' && c <= '9')) || (c2 = (c >='a' && c <= 'f')) || (c >='A' && c <= 'F'); i++)
    if (c1)
      n = 16*n + (c-'0');
    else if (c2)
      n = 16*n + (c-'a' + 10);
    else
      n = 16*n + (c-'A' + 10);
  return n;
}

// int main() {
//   char str[] = "13";
//   printf("%d",htoi(str));
//   return 0;
// }

//Homework: 2-4. Write an alternate version of squeeze(s1,s2) that deletes ecah character that mataches any character is the string s2.

void squeeze(char s1[], char s2[]) {
  int s1_ind,new_ind,s2_ind;
  // i is index of str1 we're looking at
  // j is index of the end of the string we're building
  // k is the index of str2 we're looking at
  int instr2;// This is essentially a boolean
  for (s1_ind = new_ind = 0; s1[s1_ind]!='\0';s1_ind++) {
    instr2 = 0;
    for(s2_ind = 0;
      s2[s2_ind]!='\0' &&
      !(instr2 = s2[s2_ind] == s1[s1_ind]);
        s2_ind++) {}
    if (!instr2)
      s1[new_ind++] = s1[s1_ind];
  }
  s1[new_ind] = '\0';
}

// int main() {
//   char s1[] = "abcdef";
//   char s2[] = "bcf";
//   squeeze(s1,s2);
//   printf("%s\n",s1);
// }


//Homework: 2-10. Rewrite the function lower(), which converts upper case letters to lower case with a conditional expression instead of if-else.

void lower(char s[]) {
  int i;
  for(i = 0; s[i] != '\0'; i++) {
      s[i] = s[i] + (s[i] >= 'A' || s[i] <= 'Z')*('a' - 'A');
  }
}

int main() {
  // char s1[] = "awWd2Dns";
  // lower(s1);
  // printf("%s\n",s1);
  int a = 1 > 2;
  printf("%d", a);
}
