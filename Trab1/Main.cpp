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
	int pivo = escolher_pivo(inicio, fim);
	T aux = vetor[inicio];
	vetor[inicio] = vetor[pivo];
	vetor[pivo] = aux;
	for (int i = inicio; i < fim-inicio; ++i){
		
	}
}

int main(int argc, char const *argv[]){
	// gerar_instancia<int> gerar_instancia_int;
	int n;
	cin >> n; 
	int* ac = gerar_instancia<int>(n);
	for (int i = 0; i < n; ++i){
		cout << ac[i] << endl;
	}

	return 0;
}