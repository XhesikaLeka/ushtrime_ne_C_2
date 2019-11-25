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
mag=fopen("C:/magazina.txt","rt");
h=fopen("C:/hyrje.txt","rt");
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
for (j=0;j<12;j++)
{fscanf (h,"%d",&mg[i].t[j]);}
}
for (j=0;j<12;j++)
{s=0;
for (i=0;i<m;i++)
{s=s+mg[i].t[j];}
if (s<min)
{min =s;
poz=j;}
}
printf (" muaji qe ka pasur me pak hyrje ne total eshte %d ",poz+1);

fclose (mag);
fclose (h);
return 0;

}

