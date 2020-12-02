#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafoLista.h"
#define NULL ((void *)0)

GrafoLista *adjGrafoLista(int n_nos, char *alfabeto, int inicial, int *final){
    int i, j;
    GrafoLista *g = (GrafoLista *)malloc(sizeof(GrafoLista));
    g->qtd_no = n_nos;
    //g->qtd_aresta = n_pontes;
    g->alfabeto = alfabeto;
    g->inicial = inicial;
    g->final = final;

    g->lista = (Adjacencia *)malloc(n_nos*sizeof(Adjacencia));
    for (i = 0; i < n_nos; i++){
        g->lista[i] = NULL;
    }   
    return g;
}

void liberaGlista(GrafoLista *g){
    free(g->lista);
    free(g);
}

Adjacencia *criaAdj(int vertice, char aresta){
    Adjacencia *temp = (Adjacencia *)malloc(sizeof(Adjacencia));
    /*
	char q[2]= "q";
    char buffer[2];
    snprintf(buffer, 10, "%d", vertice);
    strcat(q, buffer);
    strcpy(temp->node, q);
    */
    temp->no = vertice;
    temp->ponte = aresta;
    temp->vizinhos = NULL;
    return temp;
}

void criarAresta(GrafoLista *g, int inicio, int fim, char aresta){
    if ((g == NULL) || ((fim < 0) || (fim >= g->qtd_no)) || ((inicio < 0) || (inicio >= g->qtd_no))){
        return;
    }
    
    Adjacencia *novo = criaAdj(fim, aresta);    
	novo->vizinhos = g->lista[inicio];
    g->lista[inicio] = novo;
    //novo = g->lista[inicio]; 
}

void exibeGrafo(GrafoLista *g){
    printf("Vertices: %d. Arestas: %d. \n", g->qtd_no, g->qtd_aresta);
    int i;
    for (i = 0; i <g->qtd_no; i++){
        printf("q%d: ", i);
        Adjacencia *ad = g->lista[i];
        while (ad){
            printf(" q%d(%c)", ad->no, ad->ponte);
            ad = ad->vizinhos;
        }
        printf("\n");
    }
}

void qtdAresta(GrafoLista *g){
    int i, k= 0;
    for (i = 0; i <g->qtd_no; i++){
        Adjacencia *ad = g->lista[i];
        while (ad){
            //printf(" v%d(%d)", ad->no, ad->ponte);
            if (ad != NULL){
                k++;
            }    
            ad = ad->vizinhos;
        }
        //printf("\n");
    }
    printf("Quantidade de Arestas: %d", k);
}


void addEstados(GrafoLista *g){
    int i,j, ki = 0, kf = 0;
    char texto;
    g->qtd_aresta = strlen(g->alfabeto) * g->qtd_no;
    
    printf("Digite -1 para estados invalidos");
	
	for(i = 0; i < g->qtd_no; i++){
    	for(j = 0; j < strlen(g->alfabeto); j++){
    		printf("\nq%d(%c) -> q",i , g->alfabeto[j]);
    		scanf("%d", &kf);
  			setbuf(stdin, NULL);
  			if(kf != -1){
  				criarAresta(g, i, kf, g->alfabeto[j]);
			}
		}
	}
}


void conferePalavra(GrafoLista *g, char palavra[]){
    int inicial = g->inicial;
	int i, k = 0, j= 0;	

    Adjacencia *ad = g->lista[inicial];
    printf("Teste %d\n", inicial);
    if(ad == NULL){
    	printf("ERRO %d", inicial);
	}
	
	printf("\ndelta(q%d,%c) ", ad->no, palavra[i]);
	for(i = 0; i < strlen(palavra); i++){
		
		if(ad->ponte == palavra[i]){
			printf("\ndelta(q%d,%c) ", ad->no, palavra[i]);
			ad = g->lista[ad->no];
			printf(" = {q%d} ", ad->no);
		}
		else{
			ad = ad->vizinhos;
		}
	}
    
    
    /*
	for (i = 0; i <g->qtd_no; i++){
        Adjacencia *ad = g->lista[k];
        
        while (ad){
        	if(ad->ponte == palavra[j]){
        		printf("Ponte %s", ad->ponte);
				printf("NO %d", ad->node);
				
				//printf("NO %d", ad->node);
			}
			
			else{
				ad = ad->vizinhos;
			}
        }
        printf("\n");
    }
    
    
    
    for(i = 0; i < strlen(palavra); i++){
    	
    	if(ad->ponte == palavra[i]){
    		printf("delta(q%d,%c) ", ad->no, palavra[i]);
    		ad = g->lista[ad->no];
    		printf("= {q%d}\n", ad->no);
		}
		printf(" 1 Teste %d\n", ad->no);
		if(ad->ponte != palavra[i]){
    		ad = ad->vizinhos;
		}
		printf(" 2 Teste %d\n", ad->no);
	}*/
	
	
}




