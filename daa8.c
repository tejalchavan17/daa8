#include<stdio.h>
#include<string.h>
int pf[50];
void patternf(char p[],int x);
void textf(char te[],char p[],int ple,int tl);
void main()
{
    char te[50];
	char p[50];
    int ple,tl,flag=1;
    printf("\nEnter Text:");
    gets(te);
    printf("\nEnter Pattern:");
    gets(p);
    ple=strlen(p);
	tl=strlen(te);
	if(ple>=tl)
	{
		printf("\nPattern is greater then text");	
		flag=0;
	}
	if(flag==1)
	{
    	patternf(p,ple);
    	textf(te,p,ple,tl);
	}
}
void patternf(char p[],int ple)
{
    int i,j,t;
	i=1;
	j=0;
    pf[0]=0;
    while(i<ple)
    {
        if(p[i]==p[j])
        {
		
            pf[i]=j+1;
            i++;
            j++;
        }
        else if(j>0)
        {
            j=pf[j-1];
        }
        else
        {
            pf[i]=0;
            i++;
        }
    }
	printf("\nFailure Function");
    for(t=0;t<ple;t++)
        printf("\nf[%d]=%d",t,pf[t]);
}
void textf(char te[],char p[],int ple,int tl)
{
    int i=0,j=0,count=0,t,tj,pos;
    while(i<tl)
    {
        if(te[i]==p[j])
        {
            i++;
            j++;
            count++;
        }
        else if(j>0)
        {
            tj=j;
            j=pf[j-1];
            count=count-(tj-j);
        }
        else
        {
            i++;
        }
        if(count==ple)
            break;
    }
    if(count==ple)
    {
        pos=i-ple;
        printf("\nPattern found at index %d",pos);
    }
    else
        printf("\nPattern not found");
}

/*Output
Case 1:Pattern is greater then text
tejal@ubuntu:~/Downloads$ gcc daa8.c
tejal@ubuntu:~/Downloads$ ./a.out

Enter Text:programing

Enter Pattern:multiprograming

Pattern is greater then text
tejal@ubuntu:~/Downloads$ 

Case 2:Pattern Found
tejal@ubuntu:~/Downloads$ ./a.out

Enter Text:programing

Enter Pattern:gram

Failure Function
0
0
0
0
Pattern found at index 3
tejal@ubuntu:~/Downloads$ 

Case 3:Pattern not found
tejal@ubuntu:~/Downloads$ ./a.out

Enter Text:programing

Enter Pattern:prgrmip

Failure Function
0
0
0
0
0
0
1
Pattern not found
tejal@ubuntu:~/Downloads$ 
*/
