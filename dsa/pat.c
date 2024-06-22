/* 2. Develop a Program in C for the following operations on Strings. 
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in 
STR with REP if PAT exists in STR. Report suitable messages in case PAT does not 
exist in STR
Support the program with functions for each of the above operations. Don't use Built-in 
functions. */
#include <stdio.h>
void findreplace(char* text, char* pat, char* rep) {
  char ans[100];
  int i, j, k = 0, l, found = 0;
  for (i = 0; text[i] != '\0'; i++) {
    for (j = 0; pat[j] != '\0'; j++) {
      if (text[i + j] != pat[j])
        break;
    }
    if (pat[j] == '\0') {
      found = 1;
      for (l = 0; rep[l] != '\0'; l++)
        ans[k++] = rep[l];
      i = i + j - 1;
    } else
      ans[k++] = text[i];
  }
  ans[k] = '\0';
  if (found == 0)
    printf("pattern not found in the given text ");
  else
    printf("the resultant string is\n %s\n", ans);
}
int main() {
  char text[100], pat[20], rep[20];
  printf("Enter the text\n");
  gets(text);
  printf("Enter the pattern");
  gets(pat);
  printf("Enter the replace string");
  gets(rep);
  findreplace(text, pat, rep);
}