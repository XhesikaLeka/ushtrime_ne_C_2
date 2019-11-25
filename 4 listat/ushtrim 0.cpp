#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nyje {
	int vlere;
	struct nyje *pas;
} nyje;

nyje *krijo_nyje(int vlere)
{
	nyje *n;
	n=(nyje*)malloc(sizeof(nyje));
	n->vlere=vlere;
	n->pas=NULL;
	return n;
}

nyje *krijo_liste(int n)
{
	if(n==0)
	return NULL;
	nyje *koka=NULL;
	int vlere;
	scanf("%d",&vlere);
	koka=krijo_nyje(vlere);
	nyje *eliri=koka;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&vlere);
		eliri->pas=krijo_nyje(vlere);
		eliri=eliri->pas;
	}
	return koka;
}

void afisho(nyje *L)
{
	nyje *tmp=L;
	while(tmp!=NULL)
	{printf("%d ",tmp->vlere);
		tmp=tmp->pas;
	}
}
//heq nr e fundit te listes te barabart me te
nyje *heq (nyje *L,int x)
{nyje *tmp=L;
int c=0;
if(L==NULL)
	return NULL;
else if (L->pas==NULL)
	{if(L->vlere==x)
	return NULL;
	else 
	return L;
	}
	
else
	{while (tmp!=NULL)
		{if(tmp->vlere==x)
		{c++;}
		tmp=tmp->pas;
		}
		tmp=L;	
		if (L->vlere==x)
		c--;
		while (tmp->pas!=NULL)
		{if (tmp->pas->vlere==x)
		c--;
		if (c==0)
		break;
		tmp=tmp->pas;
		}
		tmp->pas=tmp->pas->pas;
	}

return L;	
}




int main()
{
	int n,x;
	printf ("jep nr qe do hiqet\n");
	scanf ("%d",&x);
	printf("Jep numrin e elementeve te listes: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes: ");
	nyje *L=krijo_liste(n);
	L=heq(L,x);
	afisho(L);
	getch();
	return 0;
}
