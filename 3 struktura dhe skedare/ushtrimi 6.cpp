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
float mes=0.0;
//m=fgetc(h);
fscanf (h,"%d",&m);
magazina mg[m];
for(i=0;i<m;i++)
{mg[i].emri=(char*)malloc(sizeof(char));
fscanf (mag,"%s",mg[i].emri);
for (j=1;j<=12;j++)
fscanf (h,"%d",&mg[i].t[j]);
}
//mesataren e hyrjeve gjate gjith vitit
for(i=0;i<m;i++)
{s=0;
for(j=1;j<=12;j++)
{s=s+mg[i].t[j];}
mes=(float)s/12;
printf ("mesatarje e hyrjeve ne magazinen %s ka mesatarisht %.2f \n",mg[i].emri,mes);
}

fclose (mag);
fclose (h);
return 0;
}
