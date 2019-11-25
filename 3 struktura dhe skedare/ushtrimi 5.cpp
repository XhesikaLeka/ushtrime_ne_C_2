#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct magazina {
	char *emri;
	int t[12];
}magazina;
int main ()
{
FILE *mag,*h,*f;
mag=fopen("C:/magazina.txt","r");
h=fopen("C:/hyrje.txt","r");
if (mag==NULL||h==NULL)
{printf ("gabim");
return 0;
}
int m,j,i,s,max=0,poz=0,min=0;
//m=fgetc(h);
fscanf (h,"%d",&m);
magazina mg[m];
for(i=0;i<m;i++)
{mg[i].emri=(char*)malloc(sizeof(char));
fscanf (mag,"%s",mg[i].emri);
for (j=1;j<=12;j++)
fscanf (h,"%d",&mg[i].t[j]);
}
//muaji me hyjre zero kudo
for(j=1;j<=12;j++)
{s=0;
for(i=0;i<m;i++)
{if (mg[i].t[j]==0)
s++;
}
if(s==m)
{printf ("%d",j);}
}
fclose (mag);
fclose (h);
return 0;
}
