#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findreplace(char *text,char *pat,char *rep)
{
    int i,j,k=0,l,found=0;
    char ans[20];
    for(i=0;text[i]!='\0';i++)
    {
        for(j=0;pat[j]!='\0';j++)
        {
            if(text[i+j]!=pat[j])
                break;
        }
        if(pat[j]=='\0')
        {
            found=1;
            for(l=0;rep[l]!='\0';l++)
                ans[k++]=rep[l];
            i=i+j-1;
        }
        else
            ans[k++]=text[i];
    }
    ans[k]='\0';
    if(found==0)
        printf("\nPattern not found in a given text");
    else
        printf("\nThe Resultant string is %s",ans);
}
int main()
{
    char text[20],pat[20],rep[20];
    printf("\nEnter the Text:");
    gets(text);
    printf("\nEnter the Pattern:");
    gets(pat);
    printf("\nEnter the Replacement string:");
    gets(rep);
    findreplace(text,pat,rep);
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findreplace(char *text,char *pat,char *rep)
{
    char ans[100];
    int i,j,k=0,l,found=0;
    for(i=0;text[i]!='\0';i++)
    {
        for(j=0;pat[j]!='\0';j++)
        {
            if(text[i+j]!=pat[j])
                break;
        }
        if(pat[j]=='\0')
        {
            found=1;
            for(l=0;rep[l]!='\0';l++)
                ans[k++]=rep[l];
            i=i+j-1;
        }
        else
            ans[k++]=text[i];
    }
    ans[k]='\0';
    if(found==0)
        printf("\nPattern not found in the given text");
    else
        printf("\nThe resultant string is %s",ans);
}
int main()
{
    char text[]="aabaacaadaabaaba",pat[]="aaba",rep[]="eefe";
    printf("\nEnter the text:");
    gets(text);
    printf("\nEnter the Pattern:");
    gets(pat);
    printf("\nEnter the Replace String:");
    gets(rep);
    findreplace(text,pat,rep);
    return 0;
}
*/