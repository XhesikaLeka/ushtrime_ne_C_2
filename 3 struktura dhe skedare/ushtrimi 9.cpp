//Afishon ne nje skedar te ri vetem kodet e studenteve qe kane kaluar ne cdo lende.
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
FILE *nx1,*nt1,*f;
nx1=fopen("C:/student.txt","r");
nt1=fopen("C:/nota.txt","r");
f=fopen("C:/kalues.txt","w");
if (nx1==NULL||nt1==NULL||f==NULL)
{printf ("gabim");
 return 0;
}
int i,j,m,a,c=0,sh;
fscanf (nt1,"%d", &m);
fscanf (nt1,"%d",&a);
student s[m];
	for (i=0;i<m;i++)
	{ sh=0;
	  s[i].emri=(char*)malloc(sizeof(char));
		fscanf (nx1,"%s",s[i].emri);
		for (j=0;j<a;j++)
			{fscanf(nt1,"%d",&s[i].notat[j]);
			sh=sh+s[i].notat[j];
			}
			s[i].mesatare=(float)sh/a;
	}
	for (i=0;i<m;i++)
	{c=0;
	for (j=0;j<a;j++)
	   {if (s[i].notat[j]!=4)
	   c++;	
		}
		if (c==a)
		fprintf (f,"%s\n",s[i].emri);
	}

fclose (nx1);
fclose (f);
fclose (nt1);
return 0;
}
