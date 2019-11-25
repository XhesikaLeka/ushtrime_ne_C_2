/*  Eshte dhene skedari nota.txt i cili ne rreshtin e pare permban 2 numra te plote,
	numri i pare tregon numrin e studenteve, dhe numri i dyte tregon numrin e notave
	per cdo student, dhe ne rreshtat e tjere te skedarit jane listuar notat per 
	secilin student. Eshte dhene gjithashtu skedari student.txt i cili permban kodet
	e studenteve. Te ndertohet nje program i cili:

	8.	Nderton 2 skedare te rinj: student2.txt dhe nota2.txt me kodet e studenteve dhe notat
		e tyre perkatesisht, te renditura sipas mesatares ne rend zbrites. */

#include <stdio.h>
#include <stdlib.h>
#define z 20

typedef struct student{
	char *kodi;
	int nota[z];
	float mesatare;
} student;

int main()
{
	FILE *nota, *studenti, *nota2, *student2;
	nota=fopen("C:/nota.txt","r");
	studenti=fopen("C:/student.txt","r");
	nota2=fopen("C:/nota2.txt","w");
	student2=fopen("C:/student2.txt","w");
	if(nota==NULL||studenti==NULL)
	{
		printf("Gabim ne hapjen e skedareve");
		return 0;
	}
	int m,n,i,j,shuma;
	fscanf(nota,"%d",&m);
	fscanf(nota,"%d",&n);
	student s[m];
	for(i=0;i<m;i++)
	{
		s[i].kodi=(char *)malloc(sizeof(char));
		fscanf(studenti,"%s",s[i].kodi);
		shuma=0;
		for(j=0;j<n;j++)
		{
			fscanf(nota,"%d",&s[i].nota[j]);
			shuma+=s[i].nota[j];
		}
		s[i].mesatare=(float)shuma/n;	
	}
	student tmp;
	for(i=0;i<m-1;i++)
	for(j=i+1;j<m;j++)
	if(s[j].mesatare>s[i].mesatare)
	{
		tmp=s[j];
		s[j]=s[i];
		s[i]=tmp;
	}
	for(i=0;i<m;i++)
	{
		fprintf(student2,"%s\n",s[i].kodi);
		for(j=0;j<n;j++)
		fprintf(nota2,"%d ",s[i].nota[j]);
		fprintf(nota2,"\n");
	}
	fclose(studenti);
	fclose(nota);
	return 0;
}
