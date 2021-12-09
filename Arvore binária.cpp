/*programa arv0300.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stNo {
	int info;
	struct stNo *esq, *dir;
} tNo ;

tNo *cria_arvore( int );
tNo *cria_no ( );
void pos_esq (tNo *, int );
void pos_dir (tNo *, int );

void moin () {
	tNo *raiz, *p, *q;
	char linha[80], *numero;
	int num;
	
	gets(linha);
	numero = strtok(linha, " "); /* pega o primeiro numero da lista */
	num = atoi(numero);
	raiz= cria_arvore(num); /* insere na raiz */
	numero = strtok(NULL, " ");
	while (numero) {
		q = raiz; p = raiz;
		printf("Li numero %d\n", num); /* le novo numero */
		num = atoi(numero);
		while (num != p->info && q) { /*procura na arvore */
		p = q;
		if (num < p->info)
	q = p->esq;                 /* passa para a arvore esquerda */
	    else 	
	q = p->dir;                 /* passa para a arvore direita */
	   }
	   if (num == p->info)
	      printf("O numero %d ja existe na arvore. \n", num);
	   else {  /* vou inserir o numero na arvore */
	     if (num < p->info)
	pos_esq(p, num);
	   else
	pos_dir(p, num);
	      }   
	    numero = strtok(NULL, " ");
   } /* fim da while (numero) */
}

tNo *cria_arvore (int x) {
	tNo *p;
	
	p = cria_no ();
	if (p) {
		p->info = x;
		return p;
	}
	else {
		puts("Faltou espaco para alocar no.");
		exit(1);
	}
}

tNo *cria_no() {
	tNo *p;
	
	if ((p = (tNo *) malloc(sizeof(tNo))) == NULL)
	   return NULL;
	else {
		p->esq = NULL; p->dir = NULL;
		return p;
	}   
}