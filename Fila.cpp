#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;


	struct FILA
	{
		int num;
		FILA *prox;
	};
	
	
int main (void)
{
	setlocale(LC_ALL,"Portuguese");
	//a FILA esta vazia, logo, o ponteiro topo tem valor null
	//as opera��es de inser�� e remo��o acontecem no topo;
	
	FILA *inicio = NULL;
	FILA *fim = NULL;
	FILA *aux;
	int opcao;
	
	do{
		
	system("cls");
	cout<<"\n MENU DE OP��ES\n";
	cout<<"\n1 - Inserir na FILA";
	cout<<"\n2 - Consultar toda a FILA";
	cout<<"\n3 - Remover da FILA (First in, First out)";
	cout<<"\n4 - Esvaziar a FILA";
	cout<<"\n5- Sair";
	cout<<"\nDigite sua op��o: ";
	cin>>opcao;
	
		if(opcao < 1 || opcao > 5)
		cout<<"\nOp��o Inv�lida!!\n";
		
		//INSERIR NA FILA
		if(opcao == 1)
		{
			cout<<"\nDigite o n�mero a ser inserido na FILA: ";
			FILA *novo = new FILA();
			cin>>novo->num;
			novo->prox= NULL;
			
			if (inicio == NULL)
			{
				//A FILA EST� VAZIA E O N�MERO INSERIDO SER� O PRIMEIRO E O ULTIMO
				inicio = novo;
				fim = novo;
			}
			else
			{
				fim->prox = novo;
				fim = novo;
			}
			cout<<"\nN�mero inserido na FILA!!\n";
		}
		//consultar FILA
		if ( opcao == 2)
		{
			if (inicio == NULL)
			{
				cout<<"\nA FILA est� vazia!!";
			}
				else
				{
				cout<<"\nConsultando toda a FILA: \n";
				aux = inicio;
					while (aux != NULL)
						{
							cout<<aux->num<<"   ";
							aux = aux->prox;
						}
				}
		}
		
		if (opcao == 3)
		{
			if (inicio == NULL)
			{
				cout<<"\nA FILA est� vazia!!";
			}
			else
			{
				aux = inicio;
				cout<<"\nN�mero " <<inicio->num<<" removido";
				inicio = inicio->prox;
				delete(aux);
			}
		}
		if (opcao == 4)
		{
			if (inicio == NULL)
			{
				cout<<"\nA FILA est� vazia!!";
			}
			else
			{
				aux=inicio;
				while(aux != NULL)
				{
					inicio = inicio->prox;
					delete (aux);
					aux=inicio;
				}
				cout<<"FILA ESVAZIADA";
			}
		}
		getche();
	}
	
	while (opcao != 5);
}
