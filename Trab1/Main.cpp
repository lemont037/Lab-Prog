
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
void swap_i(T* vetor, int a, int b){
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

// Particionamento triplo
template <typename T>
T* particiona_tri(T *inicio, T *fim, T *pivo){
	swap(inicio, pivo);
	T *limite_1 = inicio+1;
	T retorno[2];
	for (T *i = inicio+1; i != fim; ++i){
		if(*i < *inicio){
			swap(i, limite_1);
			limite_1++;           
		}
	}
	swap(inicio, limite_1-1);
	return retorno;
}

// Particiona usando indices
template <typename T>
int particiona_i(T *vetor, int inicio, int fim, int pivo){
	swap_i(vetor, inicio, pivo);
	int limite = inicio+1;
	for (int i = limite; i < fim; ++i){
		if(vetor[i] < vetor[inicio]){
			swap_i(vetor, i, limite);
			limite++;
		}
	}
	swap_i(vetor, inicio, limite-1);
	return limite-1;
}

template <typename T>
void quicksort_p(T* vetor, int inicio, int fim){
	if(inicio < fim){

		int pivo = escolher_pivo(inicio,fim);
		T *p_pivo = particiona(vetor+inicio, vetor+fim, vetor+pivo);
		pivo = p_pivo-vetor;
		quicksort_p(vetor,inicio, pivo);
		quicksort_p(vetor,pivo+1,fim);
	}
}

template <typename T>
void quicksort_i(T* vetor, int inicio, int fim){
	if(inicio < fim){
		int pivo = escolher_pivo(inicio,fim);
		pivo = particiona_i(vetor, inicio, fim, pivo);
		quicksort_i(vetor, inicio, pivo);
		quicksort_i(vetor, pivo+1, fim);
	}
}


template <typename T>
void  quicksort_cauda(T* vetor, int inicio, int fim){
	if(inicio < fim){

		int pivo = escolher_pivo(inicio, fim);
		T*  p_pivo = particiona(vetor+inicio,  vetor+fim, vetor+pivo);
		pivo = p_pivo-vetor;
		quicksort_cauda(vetor, inicio, pivo);
		
		while(pivo+1 < fim){
			inicio = pivo+1;
			pivo = escolher_pivo(inicio, fim);
			p_pivo = particiona(vetor+inicio,  vetor+fim, vetor+pivo);
			pivo = p_pivo-vetor;
			quicksort_cauda(vetor, inicio, pivo);
		}

	}
}
void quicksort_teste(){
	// gerar_instancia<int> gerar_instancia_int;
	int n;
	cout << endl;
	cin >> n; 
	cout << endl;
	// int* instancia_1;
	int* instancia_1 = gerar_instancia<int>(n);
	int instancia_2[n];
	int instancia_3[n];

	// for (int i = 0; i < n; ++i){
	// 	instancia_2[i] = instancia_1[i];
	// }

	// int instancia_1[] = {4,3,3,1,3};

	// n= 5;

	// if(!(escrever_instancia<int>(instancia_1, n))){
	// cout <<"q1\tq2\tq3"<<endl;
	for (int i = 0; i < n; ++i){
		instancia_2[i] = instancia_1[i];
		instancia_3[i] = instancia_1[i];
		if(n<=100)
			cout << instancia_1[i]<<"\t"<<instancia_2[i]<<"\t"<<instancia_3[i] << endl;
	}

	// }
	cout << endl;
	cout << endl;

	clock_t tempo[4];
	tempo[0] = clock();
	quicksort_i(instancia_1, 0, n);
	tempo[1] = clock()-tempo[0];	
	quicksort_p(instancia_2, 0, n);
	tempo[2] = clock()-tempo[1];	
	quicksort_cauda(instancia_3, 0, n);
	tempo[3] = clock()-tempo[2];	
	
	
	cout <<"q1\tq2\tq3"<<endl;
	if(n<=100)
		for (int i = 0; i < n; ++i)
			cout << instancia_1[i]<<"\t"<<instancia_2[i]<<"\t"<<instancia_3[i] << endl;	

	for (int i = 1; i < 4; ++i)
		cout << ( (long double)(tempo[i]) ) <<"\t";
	cout << endl;

	for (int i = 0; i < 4; ++i)
		cout << (double)tempo[i]/CLOCKS_PER_SEC << endl;
}


int main(int argc, char const *argv[]){
	quicksort_teste();
	return 0;
}