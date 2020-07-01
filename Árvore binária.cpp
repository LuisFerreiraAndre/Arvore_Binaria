#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct tree
{
	struct tree *parent;
	struct tree *left;
	struct tree *right;
	int key;
} node;


node *inserir (node *root, int key) 
{
	node *aux;

	if (root == NULL) {
		root = (node*) malloc (sizeof(node));
		(*root).key = key;
		(*root).parent = (*root).left = (*root).right = NULL;
	}

	else { 
		if (key <= (*root).key) {
			aux = inserir ((*root).left, key);
			(*root).left = aux;
			(*aux).parent = root;
		} else {
			aux = inserir ((*root).right, key);
			(*root).right = aux;
			(*aux).parent = root;
		}
	}

	return root;
}

void imprimir (node *root)
{
	if (root != NULL) {
		imprimir ((*root).left);
		printf("%d  ", (*root).key);
		imprimir ((*root).right);
	}
}

node *minimo (node *root) 
{
	node *aux = root;

	while (aux != NULL)
	{
		if ((*aux).left == NULL) {
			break;
		} else {
			aux = (*aux).left;
		}
	}
	return aux;
}

node *maximo (node *root) 
{
	node *aux = root;

	while (aux != NULL)
	{
		if ((*aux).right == NULL) {
			break;
		} else {
			aux = (*aux).right;
		}
	}
	return aux;
}

node *altura (node *root) {
   if (root == NULL){
      printf("Vazio\n"); // altura da árvore vazia
	}
	else if(root != NULL){
		printf("chegou");
      tree *he = altura (root->left);
      tree *hd = altura (root->right);
       
      	if (he < hd){
      		printf("%d", he);
	  	}
	  	else{
	  		printf("%d", hd);
	  	}
   }
   return(0);
}


int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	node *inserir (node *root, int key);
	node *minimo (node *root);
	node *maximo (node *root);
	void imprimir (node *root);
	int altura (node *root);

	node *root, *aux;
	root = NULL;

	int opt, dado;
	mainMenu: 
		printf ("\n\n===========MENU===========\n");
		printf ("1 - Inserir valor:\n"); 
		printf ("2 - Valor mínimo:\n");
		printf ("3 - Valor máximo:\n");
		printf ("4 - Imprimir árvore:\n");
		printf ("0 - Sair.\n");
		printf ("==========================\n");
		scanf ("\n\n%d", &opt);
		system("cls");

		switch(opt){
			case 1:
				printf ("Digite um valor: ");
				scanf ("%d", &dado);
				root = inserir (root, dado);
				break;
			
			case 2:
				printf ("Menor valor: ");
				aux = minimo (root);
				printf ("%d\n", (*aux).key);
				break;

			case 3:
				printf ("Maior valor: ");
				aux = maximo (root);
				printf ("%d\n", (*aux).key);
				break;

			case 4:
				imprimir (root);
				printf("\n");
				break;
				
		}    		
	while (opt != 0){
		goto mainMenu;
	}

	return 0;
}
