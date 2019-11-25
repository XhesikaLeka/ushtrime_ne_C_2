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
FILE *mag,*h;
mag=fopen("C:\Newfolder\magazina.txt","r");
h=fopen("C:\Newfolder\hyrje.txt","r");
if (mag==NULL||h==NULL)
{printf ("gabim");
return 0;
}
int m,j,i,s,max=0,poz=0,min=0;
fscanf (h,"%d",&m);
magazina mg[m];
for(i=0;i<m;i++)
{mg[i].emri=(char*)malloc(sizeof(char));
fscanf (mag,"%s",mg[i].emri);
for (j=0;j<12;j++)
fscanf (h,"%d",&mg[i].t[j]);
}
//funksion qe gjen dhe afishon emrin e magazines qe ka me shume hyrje ne totatl per nje vit
for(i=0;i<m;i++)
{ s=0;
for (j=0;j<12;j++)
{s=s+mg[i].t[j];}
if (s>max)
{max=s;
poz=i;
}
}
printf ("%s",mg[poz].emri);

fclose (mag);
fclose (h);
return 0;

}

