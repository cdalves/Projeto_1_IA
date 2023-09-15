#ifndef LARGURA  
#define LARGURA

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;

bool testaObjetivo(int atual,int objetivo){
	if(atual == objetivo)
		return true;	
	else
		return false;
}

string buscLargura(int grafo[][100], int inicial, int objetivo) {
	vector<int>listaVisitados, listaVisitar,copia,imprimeCaminho;
	
	string result;
	int filho;
	int atual = inicial;
	int mPai[10]={100,100,100,100,100,100,100,100,100,100};
	while(true){  //BUSCA EM LARGURA
		
		listaVisitados.push_back(atual);
	
		int a = 0;
		while(a<10){ //preenche de lista estados a visitar		
			if(grafo[atual][a] != 0){ //quando acha o num 1 na matriz
				
				listaVisitar.push_back(a);		
			}
			a++;	
		}
	
		//sucessao		
		for(int i = 0;i<listaVisitados.size();i++){    //Para n repetir um estado
			for(int j = 0;j<listaVisitar.size();j++){
				if(listaVisitar.at(j) == listaVisitados.at(i)) 
					listaVisitar.erase(listaVisitar.begin()+j);
			}
		}

		if(listaVisitar.empty()){ // Se acabarem as opÃ§oes
			cout << "Saida = 0 --> ";
			cout << "Nao existe conexao\n";
			break;
		}
		
		copia=listaVisitar;                //Salva quem Ã© pai de quem
		for(int i = 0;i <= copia.size();i++){
			if(mPai[copia.back()] == 100)//para nao sobrescrever
				mPai[copia.back()] = atual;
			copia.pop_back();	
		} 
	
		atual = listaVisitar.front();            //sucessao do atual
		listaVisitar.erase(listaVisitar.begin());
		
		if(testaObjetivo(atual,objetivo)){ //Se o obj for encontrado
			cout << "Saida = 1 --> ";
			cout<<"Existe Conexao\n";
			break;
		}
	
		//Fim sucessao	
	}//FIM DA BUSCA
	
	
	cout<< "\nInicial = " << inicial << "\tObjetivo = " << objetivo <<"\n\n";	
	
  //Imprimir Caminho
  	if(testaObjetivo(atual,objetivo)){
  		
  		cout << "Caminho :\n\n";
  		filho = objetivo;
  		
		while(true) { 
			if(filho == 100)  // 100 representa estados q n tem pai ;-;
				break;
			imprimeCaminho.push_back(filho);
			filho = mPai[filho]; //	pai se torna filho;	
	  }
	  
		while(true){
			cout <<"  " << imprimeCaminho.back();
			imprimeCaminho.pop_back();
			if(imprimeCaminho.empty())
				break;
		}
	  	
	}
	return result;
}

#endif
