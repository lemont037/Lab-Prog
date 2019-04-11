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

// swap para indices
template <typename T>
void swap(T* vetor, int a, int b){
	T aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

int escolher_pivo (int primeiro, int ultimo){
	return primeiro;
}


//Particiona o vetor em 2 partições
template <typename T>
T *particiona(T *inicio, T *fim, T *pivo){
	swap(inicio, pivo);
	T *limite = inicio+1;
	for (T *i = inicio+1; i != fim; ++i){
		if(*i < *inicio){
			swap(i, limite);
			limite++;           
		}
	}
	swap(inicio, limite-1);
	return limite-1;
}

// Particiona usando indices
template <typename T>
int particina_i(T *vetor, int inicio, int fim, int pivo){
	swap(vetor, inicio, pivo);
	
	return 0;
}

template <typename T>
void quicksort_p(T* vetor, int inicio, int fim){
	if(inicio < fim){

		int pivo = escolher_pivo(inicio,fim);
		T *p_pivo = particiona(vetor+inicio, vetor+fim, vetor+pivo);
		pivo = p_pivo-vetor;
	// cout <<inicio<<" a "<<fim<< endl;
	// cout <<"pivo = "<< vetor[pivo]<<endl;
	// cout <<"-------------"<<endl;
	
	// for (int i = 0; i < fim; ++i){
	// 	cout << vetor[i] << endl;
	// }	

	// cout <<"-------------"<<endl;
		// if(fim-inicio >= 2){

			quicksort_p(vetor,inicio, pivo);
			quicksort_p(vetor,pivo+1,fim);
		// }
	}

}

int main(int argc, char const *argv[]){
	// gerar_instancia<int> gerar_instancia_int;
	int n;
	cout << endl;
	cin >> n; 
	cout << endl;
	// int* ac;
	int* ac = gerar_instancia<int>(n);
	// int ac[] = {4,3,3,1,3};

	// n= 5;

	// if(!(escrever_instancia<int>(ac, n))){
	for (int i = 0; i < n; ++i){
		cout << ac[i] << endl;
	// }

	}
	cout << endl;
	quicksort_p(ac, 0, n);
	// particiona(ac, ac+n, ac);

	
	for (int i = 0; i < n; ++i){
		cout << ac[i] << endl;
	}	


	return 0;
}