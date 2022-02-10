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
	//as operações de inserçõ e remoção acontecem no topo;
	
	FILA *inicio = NULL;
	FILA *fim = NULL;
	FILA *aux;
	int opcao;
	
	do{
		
	system("cls");
	cout<<"\n MENU DE OPÇÕES\n";
	cout<<"\n1 - Inserir na FILA";
	cout<<"\n2 - Consultar toda a FILA";
	cout<<"\n3 - Remover da FILA (First in, First out)";
	cout<<"\n4 - Esvaziar a FILA";
	cout<<"\n5- Sair";
	cout<<"\nDigite sua opção: ";
	cin>>opcao;
	
		if(opcao < 1 || opcao > 5)
		cout<<"\nOpção Inválida!!\n";
		
		//INSERIR NA FILA
		if(opcao == 1)
		{
			cout<<"\nDigite o número a ser inserido na FILA: ";
			FILA *novo = new FILA();
			cin>>novo->num;
			novo->prox= NULL;
			
			if (inicio == NULL)
			{
				//A FILA ESTÁ VAZIA E O NÚMERO INSERIDO SERÁ O PRIMEIRO E O ULTIMO
				inicio = novo;
				fim = novo;
			}
			else
			{
				fim->prox = novo;
				fim = novo;
			}
			cout<<"\nNúmero inserido na FILA!!\n";
		}
		//consultar FILA
		if ( opcao == 2)
		{
			if (inicio == NULL)
			{
				cout<<"\nA FILA está vazia!!";
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
				cout<<"\nA FILA está vazia!!";
			}
			else
			{
				aux = inicio;
				cout<<"\nNúmero " <<inicio->num<<" removido";
				inicio = inicio->prox;
				delete(aux);
			}
		}
		if (opcao == 4)
		{
			if (inicio == NULL)
			{
				cout<<"\nA FILA está vazia!!";
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
