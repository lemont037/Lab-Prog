#include "instancias_ruins_Quicksort.hpp"
#include <random>
#include <iostream>
#include <new>
using std::nothrow;
using std::cout;using std::endl;using std::cin;


// Gerar vetor com n termos aleatorios de 1 a n
template <typename T>
T* gerar_instancia(int n){
	std::random_device rd;
	std::uniform_int_distribution<T> dist(1,n);
	T *v = new(nothrow) T(n);
	for (T *i = v; i != v+n; ++i)
		*i = dist(rd);
	return v;
}

//swap basico
template <typename T>
void swap(T *a, T *b){
	T aux = *a;
	*a = *b;
	*b = aux;
}

int escolher_pivo (int primeiro, int ultimo){
	return primeiro;
}


//Particiona o vetor em 2 partições
template <typename T>
T *particiona(T *inicio, T *fim, T *pivo){
    // swap(inicio, pivo);
	T *limite = inicio+1;
	for (T *i = inicio+1; i != fim; ++i){
		if(*i <= *inicio){
			swap(i, limite);
			limite++;           
		}
	}
	swap(inicio, limite-1);
	return limite-1;
}

template <typename T>
void quicksort_indices(T* vetor, int inicio, int fim){
	T aux;
	if(fim-inicio>1){
		int pivo = escolher_pivo(inicio, fim);
		aux = vetor[inicio];
		vetor[inicio] = vetor[pivo];
		vetor[pivo] = aux;
		int limite = inicio+1;
		for (int i = inicio+1; i <= fim; ++i){
			if (vetor[i] < vetor[inicio]){
				// if(i != limite){
					aux = vetor[limite];
					vetor[limite] = vetor[i];
					vetor[i] = aux;
					limite++;
				// }
			}
		}
		aux = vetor[limite];
		vetor[limite] = vetor[inicio];
		vetor[inicio] = aux;

		quicksort_indices(vetor, inicio,(fim+inicio)/2);
		quicksort_indices(vetor, (fim+inicio)/2, fim);
	}else if (fim-inicio==1){
		if (vetor[inicio] > vetor[fim]){
			aux = vetor[inicio];
			vetor[inicio] = vetor[fim];
			vetor[fim] = aux;
		}
	}
}

int main(int argc, char const *argv[]){
	// gerar_instancia<int> gerar_instancia_int;
	int n;
	cin >> n; 
	cout << endl;
	int* ac = gerar_instancia<int>(n);
	int ac[] = {4,2,3,2};

	// if(!(escrever_instancia<int>(ac, n))){
		for (int i = 0; i < n; ++i){
			cout << ac[i] << endl;
		}

	// }
	cout << endl;
	quicksort_indices(ac, 0, n-1);
	
	for (int i = 0; i < n; ++i){
		cout << ac[i] << endl;
	}	
	return 0;
}