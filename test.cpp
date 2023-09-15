#include<iostream>
#include <cstdlib>
#include<vector>
using namespace std;

bool testaObjetivo(int atual,int objetivo){
	if(atual == objetivo)
		return true;	
	else
		return false;
}


int main()
{
	int inicial,atual,objetivo,filho;
	vector<int>listaVisitados, listaVisitar,copia,imprimeCaminho;
	int mPai[10]={100,100,100,100,100,100,100,100,100,100};
	
	cout<< "Digite o valor do estado inicial\n";
	cin >> inicial;
	system("cls");
	cout<< "Digite o valor do estado objetivo\n";
	cin >> objetivo;
	system("cls");
	

	int grafo[10][10];
	//Matriz
	{
		grafo[0][0]=0;grafo[0][1]=1;grafo[0][2]=0;grafo[0][3]=1;grafo[0][4]=0;grafo[0][5]=0;grafo[0][6]=0;grafo[0][7]=0;grafo[0][8]=0;grafo[0][9]=0;
		grafo[1][0]=1;grafo[1][1]=0;grafo[1][2]=1;grafo[1][3]=0;grafo[1][4]=0;grafo[1][5]=0;grafo[1][6]=0;grafo[1][7]=0;grafo[1][8]=0;grafo[1][9]=0;
		grafo[2][0]=0;grafo[2][1]=1;grafo[2][2]=0;grafo[2][3]=1;grafo[2][4]=0;grafo[2][5]=0;grafo[2][6]=0;grafo[2][7]=0;grafo[2][8]=0;grafo[2][9]=0;
		grafo[3][0]=1;grafo[3][1]=0;grafo[3][2]=1;grafo[3][3]=0;grafo[3][4]=1;grafo[3][5]=0;grafo[3][6]=0;grafo[3][7]=1;grafo[3][8]=0;grafo[3][9]=0;
		grafo[4][0]=0;grafo[4][1]=0;grafo[4][2]=0;grafo[4][3]=1;grafo[4][4]=0;grafo[4][5]=1;grafo[4][6]=0;grafo[4][7]=0;grafo[4][8]=0;grafo[4][9]=0;
		grafo[5][0]=0;grafo[5][1]=0;grafo[5][2]=0;grafo[5][3]=0;grafo[5][4]=1;grafo[5][5]=0;grafo[5][6]=1;grafo[5][7]=0;grafo[5][8]=0;grafo[5][9]=0;
		grafo[6][0]=0;grafo[6][1]=0;grafo[6][2]=0;grafo[6][3]=0;grafo[6][4]=0;grafo[6][5]=1;grafo[6][6]=0;grafo[6][7]=1;grafo[6][8]=0;grafo[6][9]=0;
		grafo[7][0]=0;grafo[7][1]=0;grafo[7][2]=0;grafo[7][3]=1;grafo[7][4]=0;grafo[7][5]=0;grafo[7][6]=1;grafo[7][7]=0;grafo[7][8]=0;grafo[7][9]=0;
		grafo[8][0]=0;grafo[8][1]=0;grafo[8][2]=0;grafo[8][3]=0;grafo[8][4]=0;grafo[8][5]=0;grafo[8][6]=0;grafo[8][7]=0;grafo[8][8]=0;grafo[8][9]=1;
		grafo[9][0]=0;grafo[9][1]=0;grafo[9][2]=0;grafo[9][3]=0;grafo[9][4]=0;grafo[9][5]=0;grafo[9][6]=0;grafo[9][7]=0;grafo[9][8]=1;grafo[9][9]=0;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	atual = inicial;
	
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

	cout << "\n\n";
	return 0;	
}