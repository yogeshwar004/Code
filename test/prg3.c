#include<stdio.h>
#include<string.h>
void findreplace(char *text,char *pat,char *rep)
{
    char ans[100];
    int i,j,k=0,l,found=0;
    for(i=0;text[i]!='\0'; i++)
    {
        for(j=0;pat[j]!='\0';j++)
        {
            if(text[i+j]!=pat[j])
                break;
        }
        if(pat[j]=="\0")
        {
            found=1;
            for(l=0;rep[l]!='\0';l++)
                ans[k++]=rep[l];
        }
        else
            ans[k++]=text[i];
    }
    ans[k]='\0';
    if(found==0)
        printf("Pattern not found in the given text");
    else
        printf("The resultant string \n%s\n",ans);
}
int main()
{
    char text[200], pat[20], rep[20];

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);

    printf("Enter the pattern:\n");
    fgets(pat, sizeof(pat), stdin);

    printf("Enter the replace string:\n");
    fgets(rep, sizeof(rep), stdin);

    // Removing newline characters from inputs
    text[strcspn(text, "\n")] = '\0';
    pat[strcspn(pat, "\n")] = '\0';
    rep[strcspn(rep, "\n")] = '\0';

    findreplace(text, pat, rep);
    
    return 0;
}
