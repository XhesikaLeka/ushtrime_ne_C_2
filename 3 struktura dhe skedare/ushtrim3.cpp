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
mag=fopen("C:/magazina.txt","rt");
f=fopen("C:/magmax.txt","w");
h=fopen("C:/hyrje.txt","rt");
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

//emrin e magazinave qe kane pasur me shume hyrje ne secilin muaj emrat ne skedarin magmax.txt
for (j=0;j<12;j++)
{max=0;
for (i=0;i<m;i++)
{if (mg[i].t[j]>max)
{max=mg[i].t[j];
poz=i;
}
}
fprintf (f,"%s\n",mg[poz].emri);
}
fclose (mag);
fclose (h);
return 0;

}

