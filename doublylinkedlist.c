#include<stdio.h>
#include<stdlib.h>

typedef struct liste
{
	short veri;
	struct liste *next,*prev;
	
}liste;

short kisisayisi=0;

liste *bas=NULL;
liste *son=NULL;

add(short x)
{
	liste *yeni=malloc(sizeof(liste));
	yeni->veri=x;
	yeni->next=NULL;
	yeni->prev=NULL;	
	if(bas==NULL)
	{
		bas=yeni;
	}
	else
	{
		liste *nomad=bas;
		while(nomad->next != NULL)
		{
			nomad=nomad->next;
		}
		
		nomad->next=yeni;
		nomad->next->prev=nomad;
		son=yeni;
	}
	//kisisayisi++;
}
sil(short neyi)
{
	liste *nomad=bas;
	
	while(nomad!=NULL)
	{
		if(nomad->veri==neyi)
		{
			if(nomad==bas)
			{
				bas=bas->next;
			}
			else if(nomad->next!=NULL)
			{
				nomad->prev->next=nomad->next;
				nomad->next->prev=nomad->prev;
			}
			else if(nomad->next==NULL)
			{
				nomad->prev->next=nomad->next;//null ý göstersin
				son=nomad->prev;				
			}
		}
		nomad=nomad->next;
	}
}
nereyeekle(short nereye,short neyi)
{
	liste *nomad=bas;
	liste *yeni=malloc(sizeof(liste));
	yeni->veri=neyi;
	
	if(nereye==1)
	{
		if(bas==NULL)
		{
			bas=yeni;
			bas->next==NULL;
			bas->prev==NULL;
			son=yeni;
		}
		else
		{
			yeni->prev=NULL;
			yeni->next=bas;
			bas->prev=yeni;
			bas=yeni;
		}
	}
	else
	{
		short sira=1;
		liste *nomad=bas;
		
		while(nomad!=NULL && sira<nereye-1)
		{
			nomad=nomad->next;
			sira++;
		}
		if(nomad==son)
		{
			nomad->next=yeni;
			yeni->prev=nomad;
			yeni->next=NULL;
			son=yeni;
		}
		else
		{
			yeni->prev=nomad;
			yeni->next=nomad->next;
			yeni->next->prev=yeni;
			yeni->prev->next=yeni;
		}
	}
	
}
show()
{
	liste *nomad=bas;
	while(nomad!=NULL)
	{
		printf("%d\n",nomad->veri);
		nomad=nomad->next;
	}
}
show2()
{
	liste *nomad=son;
	
	while(nomad!=NULL)
	{
		printf("%d\n",nomad->veri);
		nomad=nomad->prev;
	}
}
main()
{
	add(5);
	add(20);
	add(30);
	nereyeekle(4,55);
	add(675);
	//show();
	sil(675);
	show();
	
	
}
