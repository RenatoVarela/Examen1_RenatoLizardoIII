#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>



using namespace std;


char** crearMatriz(int);
void liberarMatriz(char**& ,int);
void printMatrix(char**,int);
char** llenar(char**);
void movimiento1(char**);
void jugada1(char**); //jugada de las negras
void jugada2(char**); //jugada de las blancas
void movimiento1(char**,int,int); //movimiento de negras
void movimiento2(char**,int,int);
void eliminar(char**,int,int);
void eliminar2(char**,int,int);
bool ganar1(char**);
bool ganar2(char**);
int filasT(string);




/////Metodo Main---------------------------------------------------------------------------


int main(){
     int tamano = 0;
     bool ganador1 = false;
     bool ganador2 = false;

     char** tablero=NULL;
     tamano = 11;

     int turno = 0;
     tablero = crearMatriz(tamano);


     //Aqui simplemente llenamos el tablero sin piezas

     for(int i = 0;  i < 11 ; i++){

	     for(int j = 0; j < 11 ; j++){
		     tablero[i][j] = '-';


	     }



     }
//terminamos de llenar el tablero sin piezas


     tablero = llenar(tablero);


      while (ganador1 == false && ganador2 == false) {
            if (turno % 2 == 0) {

                 jugada1(tablero);
            } else {
                jugada2(tablero);

            }

           if (ganar1(tablero) == true) {
               ganador1 = true;
                cout<<"ganan las negras" <<endl ;

            }

            if (ganar2(tablero) == true) {
                ganador1 = true ;
                cout<<"ganan las blancas" << endl ;
            }



            turno++;
        }
    




     printMatrix(tablero,tamano);

     liberarMatriz(tablero,tamano);



return 0;
}


///////////////////FInal del metodo main



//EN las siguientes funciones se desarrolla el juego, si queres ve como arme el tablero ve mas abajo igual para las partes como movimiento eliminar y ganar cada una separada para negras y blancas
//---------------------------------------------------------------------------------------------------------------------------------------

void jugada1(char** tabla) {
      
      
        int turno = 0, fila = 0 , cols = 0;
	string coordenada = "" ;

        /**
         * ***--------------Comienza el juego --------*********
         */
        printMatrix(tabla,11);
        
        cout << "EMPIEZAN FICHAS NEGRAS" <<endl;

        cout<<"Ingrese las coordenadas x de la pieza que desea mover" <<endl;
	cin >> coordenada;

	vector<string> coordenadas;
	size_t coma;

	coma = coordenada.find("-");
	coordenadas.push_back(coordenada.substr(0,coma));
	coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

	fila = filasT(coordenadas[0]);
	cols = stoi(coordenadas[1]) ;




	cout<<coordenadas[0]<<"----------------------- asdadas" <<endl;
	cout<<coordenadas[1]<< " -------------------------adasdasad" <<endl;
	cout<< fila <<"asdsa"<<endl;





        
        
        while(fila > 10 || cols > 10 || fila < 0 || cols < 0 ){
	    coordenadas.clear();
            cout<<"coordenadas fuera de rango (NEGRAS)"<<endl;
            cout<<"Ingrese las coordenadas x (fila) de la pieza que desea mover"<<endl;
            cin>> coordenada;

            coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            fila = filasT(coordenadas[0]);

	    cols = stoi(coordenadas[1]) ;


            
        }
        
        

        while (tabla[fila][cols] != '*') {

		coordenadas.clear();
            cout<<"VUELVA A INGRESAR LAS COORDENADAS!!(NEGRAS) "<<endl;

              cout<<"Ingrese las coordenadas x (fila) de la pieza que desea mover"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            fila = filasT(coordenadas[0]);

            cols = stoi(coordenadas[1]) ;

		cout<<fila<<"+"<<cols<<endl;

        }

        movimiento1(tabla, fila, cols);
        
        

    }






///JUgada de las PIezas Blancas
void jugada2(char** tabla) {
        
    
        int turno = 0, fila = 0, cols = 0;
	string coordenada = "";

        /**
         * ***--------------Comienza --------*********
         */


        printMatrix(tabla,11);
        
        cout<<"EMPIEZAN FICHAS BLANCAS"<<endl;

        cout<<"Ingrese las coordenadas x (fila) de la pieza (blancas)" <<endl;
        cin>> coordenada;


	 vector<string> coordenadas;
        size_t coma;

        coma = coordenada.find("-");
        coordenadas.push_back(coordenada.substr(0,coma));
        coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

	fila = filasT(coordenadas[0]);
        cols = stoi(coordenadas[1]) ;

	cout<<coordenadas[0]    << "------------- asdadas" <<endl;
        cout<<coordenadas[1]  <<"  -----------adasdasad" <<endl;
        cout<< fila <<"asdsa"<<endl;





        
         while(fila > 10 || cols > 10 || fila < 0 || cols < 0 ){
	    coordenadas.clear();

            cout<<"coordenadas fuera de rango"<<endl;
            cout<<"Ingrese las coordenadas x (fila) de la pieza que desea mover"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            fila = filasT(coordenadas[0]);

            cols = stoi(coordenadas[1]) ;


            
        }

        while (tabla[fila][cols] != 'o' && tabla[fila][cols] != 'W' ) {

	    coordenadas.clear();

          
            cout<<"Vuelva ingresar la coordenada de la pieza(BLANCAS) "<<endl;
            cout<<"Ingrese las coordenadas x (fila) de la pieza que desea mover"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            fila = filasT(coordenadas[0]);

            cols = stoi(coordenadas[1]) ;


 
        }
        
        
       

        movimiento2(tabla, fila, cols);
       
        eliminar2(tabla, fila, cols);
        
        
       ///return ganar2(tabla);

    }


///FIn de los metodos que avarcan una jugada






//////---------------------------Metodos para los movimientos de las pieza (blancas y negras)




//movimiento para las blancas

void movimiento1(char** tabla, int filas, int cols) {

        int filas2 = 0, columnas2 = 0;
	string coordenada = "";

        bool siguiente = false;
        char aux;

        cout<<"Ingrese las coordenadas x (fila) del lugar al que desea mover"<<endl;
        cin>> coordenada;


         vector<string> coordenadas;
        size_t coma;

        coma = coordenada.find("-");
        coordenadas.push_back(coordenada.substr(0,coma));
        coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );
	filas2 = filasT(coordenadas[0]);

        columnas2 = stoi(coordenadas[1]) ;


        
         while(filas2 > 10 || columnas2 > 10 || filas2 < 0 || columnas2 < 0 ){

             coordenadas.clear();

             cout<<"coordenadas fuera de rango"<<endl;
	     cout<<"INgrese las coordenadas de nuevo"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            filas2 = filasT(coordenadas[0]);

            columnas2 = stoi(coordenadas[1]) ;


            
        }
        
         while(filas != filas2 && cols !=  columnas2){

            coordenadas.clear();

            cout<<"El movimiento tiene que ser ortogonal vuelva a ingresar: "<<endl;
             cout<<"INgrese las coordenadas de nuevo"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            filas2 = filasT(coordenadas[0]);

            columnas2 = stoi(coordenadas[1]) ;



        }
        
        
        while(siguiente == false){
        if (tabla[filas2][columnas2] == '-') {
            tabla[filas2][columnas2] = tabla[filas][cols];
        tabla[filas][cols] = '-';
            siguiente = true;
        }else{
            
             cout<<"No puede poner una pieza encima de otra: "<<endl;
             cout<<"INgrese las coordenadas de nuevo"<<endl;
            cin>> coordenada;

            coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            filas2 = filasT(coordenadas[0]);

            columnas2 = stoi(coordenadas[1]) ;


        }
        }
        
        eliminar(tabla, filas2, columnas2);

       
        

 }
    





///PAra las negras
void movimiento2(char** tabla, int filas, int cols) {

        int filas2 = 0, columnas2 = 0;
	string coordenada = "" ;
        bool siguiente = false;
        char aux;

	cout<<"Ingrese las coordenadas x (fila) del lugar al que desea mover"<<endl;
        cin>> coordenada;


         vector<string> coordenadas;
        size_t coma;

        coma = coordenada.find("-");
        coordenadas.push_back(coordenada.substr(0,coma));
        coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

	filas2 = filasT(coordenadas[0]);
        columnas2 = stoi(coordenadas[1]);
       


        while(filas != filas2 && cols !=  columnas2){

	    coordenadas.clear();

            cout<<"El movimiento tiene que ser recto vuelva a ingresar: "<<endl;
             cout<<"INgrese las coordenadas de nuevo"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            filas2 = filasT(coordenadas[0]);

            columnas2 = stoi(coordenadas[1]) ;



        }
        
           while(filas2 > 11 || columnas2 > 11){

            coordenadas.clear();

            cout<<"coordenadas fuera de rango"<<endl;
             cout<<"INgrese las coordenadas de nuevo"<<endl;
            cin>> coordenada;

	    coma = coordenada.find("-");
            coordenadas.push_back(coordenada.substr(0,coma));
            coordenadas.push_back(coordenada.substr(coma+1,coordenadas.size()) );

            filas2 = filasT(coordenadas[0]);

            columnas2 = stoi(coordenadas[1]) ;



            
        }
        
        
        while(siguiente == false){
        if (tabla[filas2][columnas2] == '-' || tabla[filas2][columnas2] == 'x') {
            tabla[filas2][columnas2] = tabla[filas][cols];
        tabla[filas][cols] = '-';
            siguiente = true;
        }else{
               cout<<"No puede poner una pieza encima de otra: "<<endl;
             cout<<"INgrese las coordenadas de nuevo"<<endl;
            cin>> coordenada;

        }
        
        }
        
        ganar2(tabla);
       eliminar2(tabla, filas2, columnas2);
        

    }


///// ------------------------------------------------------------------------------------------------------FIn de los metodos para mover piezas



//---------------------------------------------------------------------------------------------------------
//Este metodo reemplaza - al eliminar
 void eliminar(char** tabla, int filas, int cols){
          
        if(filas > 1){
        if (tabla[filas-1][cols] == 'o'  && tabla[filas-2][cols] == '*') {
            tabla[filas-1][cols] = '-';
           
            
        }
        }
        
        if (cols > 1) {
            if (tabla[filas][cols-1] == 'o' && tabla[filas][cols-2] == '*') {
            tabla[filas][cols-1] = '-';
        }
            
        }
        
        if (tabla[filas+1][cols] == 'o'  && tabla[filas+2][cols] == '*') {
            tabla[filas+1][cols] = '-';
           
            
        }
        
        if (tabla[filas][cols+1] == 'o' && tabla[filas][cols+2] == '*') {
            tabla[filas][cols+1] = '-';
        }
        
    }
    

//fin del eliminar de las blancas
    

//ELuminar las negras
   void eliminar2(char** tabla , int filas, int cols){
        
        
          if(filas > 1){
        if (tabla[filas-1][cols] == '*'  && tabla[filas-2][cols] == 'o') {
            tabla[filas-1][cols] = '-';
           
            
        }
        }
        
        if (cols > 1) {
            if (tabla[filas][cols-1] == '*' && tabla[filas][cols-2] == 'o') {
            tabla[filas][cols-1] = '-';
        }
            
        }
        
        
        
        
         if (tabla[filas+1][cols] == '*'  && tabla[filas+2][cols] == 'o' ) {
            
           tabla[filas+1][cols] = '-';
            
        }
        
        if (tabla[filas][cols+1] == '*' && tabla[filas][cols+2] == 'o' ) {
            tabla[filas][cols+1] = '-';
        }
        
    }
  //FIn del que elimina negras  
    
//---------------------------------------------------------------------------




//------------------------------------------------------------------------------
 //Metodo que veririfa si ganan 
    
    bool ganar2(char** tabla){
         if (tabla[0][0] == 'W') {
            return true;
        }else if (tabla[0][10] == 'W') {
            return true;
        }else if (tabla[10][10] == 'W') {
            return true;
        }else if (tabla[10][0] == 'W') {
            return true;
        }
         
         return false;
    }

    
      bool ganar1(char** tabla){
          int rey = 0;
          int fichas = 0;
          
          for (int i = 0; i < 11; i++) {
              for (int j = 0; j < 11; j++) {
                  if (tabla[i][j] == 'W') {
                      rey++;
                  }
                  
                  if (tabla[i][j] == 'o') {
                      fichas++;
                  }
                  
                  
              }
              
          }
          
          if (rey == 0) {
              return true;
          }
          
          if (rey == 0 && fichas == 0) {
              return true;
          }
         
         return false;
    }
    
///FIn de los metodos para ganar
//-------------------------------------------------------------------------------------------------------------------------



//Convirte en numero las letras de las coordenadas
int filasT(string coordenada){
 
	int fila = 0;

 if(coordenada == "A" || coordenada == "a" ){
                fila = 0;

        }else  if(coordenada == "B" || coordenada == "b"  ){
                fila = 1;

        } else  if(coordenada == "C" || coordenada == "c" ){
                fila = 2;

        }else if(coordenada == "D" || coordenada == "d" ){

                fila = 3;
        }else if(coordenada == "E" || coordenada == "e"  ){
                fila = 4;

        }else if(coordenada == "F" || coordenada == "f"  ){
                fila = 5;

        }else  if(coordenada == "G" || coordenada == "g"  ){

                fila = 6;
        }else if(coordenada == "H" || coordenada == "h"  ){

                fila = 7;
        }else if(coordenada == "I" || coordenada == "i"  ){
                fila = 8;

        }else if(coordenada == "J" || coordenada == "j"  ){
                fila= 9;

        }else if(coordenada == "K"  || coordenada == "k" ){
                fila = 10;

        }




return fila;

}

//final del que convierte en letras





///-----------------------------------------------------------------------------------------------------------------------------------------------




///Aqui termina el desarrollo del juego

/////EN las siguientes funciones se arma el tablero y se libera la matriz

char** crearMatriz(int size){

 char** matrix = NULL;
 matrix = new char*[size];

 for(int i = 0; i <size ; i++){
        matrix[i] = new char[size];
 }




return matrix;

}



void printMatrix(char** matrix,int size){

        for(int i = 0 ; i < size ; i ++){
                for(int j = 0; j < size ; j++) {
			cout<<"[";
                        cout << matrix[i][j];
			cout<<"]";

                }
                cout<<endl;

        }




}




void liberarMatriz(char**& matrix, int size){

        for(int i = 0; i < size ; i++){

           delete[]matrix[i];
           matrix[i] = NULL;
        }


          if(matrix != NULL){
          delete[] matrix;
          matrix = NULL;

        }



}




char** llenar(char** t){


        for(int i = 0; i < 11; i++){

                for(int j = 0 ; j < 11 ; j++){



			//Poner las piezas negras
		if (i == 0 && j > 3 && j < 7) {
                    t[i][j] = '*';
                }

                //fichas delanteras negras
                if (i == 2 && j == 11 / 2) {
                    t[i][j] = '*';
                }

                if (i == 8 && j == 11 / 2) {
                    t[i][j] = '*';
                }

                if (j == 2 && i == 11 / 2) {
                    t[i][j] = '*';
                }

                if (j == 8 && i == 11 / 2) {
                    t[i][j] = '*';
                }
                //fichas delanteras negras   
		
		//Fichas negras de enmedio
		if (i == 1 && j == ( (11 / 2) + 1)) {
                    t[i][j] = '*';
                }

                if (i == 9 && j == ((11 / 2) + 1)) {
                    t[i][j] = '*';
                }

                if (j == 1 && i == ((11 / 2) + 1) ) {
                    t[i][j] = '*';
                }

                if (j == 9 && i == ((11 / 2) + 1) ) {
                    t[i][j] = '*';
                }



		 if (i == 1 && j == ( (11 / 2) - 1)) {
                    t[i][j] = '*';
                }

                if (i == 9 && j == ((11 / 2) - 1)) {
                    t[i][j] = '*';
                }

                if (j == 1 && i == ((11 / 2) - 1) ) {
                    t[i][j] = '*';
                }

                if (j == 9 && i == ((11 / 2) - 1) ) {
                    t[i][j] = '*';
                }


		


		///fichas negras de enmedio

                if (j == 0 && i > 3 && i < 7) {
                    t[i][j] = '*';
                }

                if (j == 10 && i > 3 && i < 7) {
                    t[i][j] = '*';
                }

                if (i == 10 && j > 3 && j < 7) {
                    t[i][j] = '*';
                }



			//termino de pone las piezas negras





                        ///Aqui se ponen la fichas blancas


                if (i == 5 && j > 2 && j < 8) {
                    t[i][j] = 'o';
                }

                if (j == 5 && i > 2 && i < 8) {
                    t[i][j] = 'o';
                }
                if (j == 4 && i > 3 && i < 7) {
                    t[i][j] = 'o';
                }

                if (j == 6 && i > 3 && i < 7) {
                    t[i][j] = 'o';
                }




                }


                        //Aqui se terminan de poner las fichas blancas


        }


            t[5][5] = 'W';
            t[0][0] = 'x';
            t[0][10] = 'x';
            t[10][0] = 'x';
            t[10][10] = 'x';




 return t;
}
