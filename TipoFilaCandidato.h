struct candidato{
	char nome[50];
	char email[50];
	char telefone[50];
	char curso[50];
	char tempoExp[50];
};

typedef struct candidato TipoCandidato;

struct no {
    TipoCandidato cand;
	struct no *prox;
};

typedef struct no* TipoFila;

void INIT(TipoFila *ini, TipoFila *fim){
	*ini = NULL;
	*fim = NULL;
}

int isEmpty(TipoFila ini, TipoFila fim){
	
	if ((ini == NULL) && (fim == NULL))
		return(1);
	else
		return(0);
}

void ENQUEUE( TipoFila *ini, TipoFila *fim, TipoCandidato pessoa){
	TipoFila novo;
	novo = (TipoFila) malloc (sizeof(struct no));
	if (novo==NULL)
		printf("Fila Cheia \n");
	else  {
	//*novo -> cand.nome = pessoa.nome;
	novo -> cand = pessoa;
	novo ->prox=NULL;
	if (isEmpty(*ini, *fim)){
    	*ini = novo;
    	}
	else{
    	(*fim) -> prox = novo;
	}
		*fim=novo;
	}
}

int FIRST(TipoFila ini, TipoFila fim, TipoCandidato *pessoa){
	if(isEmpty(ini, fim)) {
		printf("Fila Vazia \n");
		return(0);
	} else{
		*pessoa = ini->cand;	
		return(1);
	}
}

int DEQUEUE (TipoFila *ini,TipoFila *fim, TipoCandidato *pessoa)
{
TipoFila aux;
aux = *ini;
if (!isEmpty(*ini,*fim)){
    *pessoa=(*ini)->cand;
    *ini=(*ini)->prox;
    if(*ini==NULL)
       *fim=NULL;
    free(aux);
    return(1);
}
else
    {
	printf("Fila Vazia \n");
    return(0);
    }
}



