#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define l 20
typedef struct student{
	char*emri;
	int notat [l];
	float mesatare ;
}student;
int main ()
{
FILE *nx1,*nt1,*nx2,*nt2;
nx1=fopen("C:/student.txt","r");
nt1=fopen("C:/nota.txt","r");
nx2=fopen("C:/student2.txt","w");
nt2=fopen("C:/nota2.txt","w");
if (nx1==NULL||nt1==NULL)
{printf ("gabim");
 return 0;
}
int i,j,m,a,k,sh=0,tmp1;
char *tmp;
tmp=(char*)malloc(sizeof(char));
fscanf (nt1,"%d", &m);
fscanf (nt1,"%d",&a);
student s[m];
	for (i=0;i<m;i++)
	{	sh=0;
		s[i].emri=(char*)malloc(sizeof(char));
		fscanf (nx1,"%s",s[i].emri);
		for (j=0;j<a;j++)
			{fscanf(nt1,"%d",&s[i].notat[j]);
				sh=sh+s[i].notat[j];
			}
		s[i].mesatare=(float)sh/a ;
	}
//rendit sipas mesatares
for (i=0;i<m-1;i++)
	{	for(j=i+1;j<m;j++)
		{if(s[i].mesatare<s[j].mesatare)
			{ tmp=s[i].emri;
			 s[i].emri=s[j].emri;
			 s[j].emri=tmp;
			 for (k=0;k<a;k++)
				{tmp1=s[i].notat[k];
					s[i].notat[k]=s[j].notat[k];
					s[j].notat[k]=tmp1;
				}
			}
		}
	}
for (i=0;i<m;i++)
	{fprintf (nx2,"%s\n",s[i].emri);
	  for(j=0;j<a;j++)
		{fprintf(nt2,"%d ",s[i].notat[j]);
		}
	  fprintf(nt2,"\n");
	}
fclose (nx1);
fclose (nx2);
fclose (nt1);
fclose (nt1);
return 0;
}
