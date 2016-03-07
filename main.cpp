#include <curses.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char*argv[]){

	(void)echo();
	int ganador=0,jugador=1,validar_movimiento,Valides_entrada;
	char continuar='s';
	char cordenada[10];
	char cordenada_x1,cordenada_x2,cordenada_y1,cordenada_y2;
	//cordenasa x,y de las pizas a mover
	int x1,y1;
	//cordenasa x,y de donde quiere mover
	int x2,y2;

	//temporal creada para imprimir las piezas del tablero
	char* temp= new char[5];;

	initscr();
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK); 
	init_pair(2,COLOR_BLUE,COLOR_BLACK);

	//crea tablero
	string tablero[8][8];
	//tablero para verificar movimientos de jugador 1 o 2	
	int tablero2[8][8];

	//llena tablero jugador 1
	
	//rey
	tablero[0][3]="[K]";
	tablero2[0][3]=11;
	
	//reyna
	tablero[0][4]="[Q]";
	tablero2[0][4]=1;

	//peones
	for(int i=0;i<8;i++){
		tablero[1][i]="[P]";
		tablero2[1][i]=111;
	}
	
	//torres
	tablero[0][0]="[T]";
	tablero2[0][0]=1;
	tablero[0][7]="[T]";
	tablero2[0][7]=1;

	//caballos
	tablero[0][1]="[C]";
	tablero[0][6]="[C]";
	tablero2[0][1]=1;
	tablero2[0][6]=1;

	//alfil
	tablero[0][2]="[A]";
	tablero[0][5]="[A]";
	tablero2[0][2]=1;
	tablero2[0][5]=1;

	//llena tablero jugador 2

	//rey
	tablero[7][3]="[K]";
	tablero2[7][3]=22;
	
	//reyna
	tablero[7][4]="[Q]";
	tablero2[7][4]=2;

	//peones
	for(int i=0;i<8;i++){
		tablero[6][i]="[P]";
		tablero2[6][i]=222;
	}
	
	//torres
	tablero[7][7]="[T]";
	tablero2[7][7]=2;
	tablero[7][0]="[T]";
	tablero2[7][0]=2;

	//caballos
	tablero[7][1]="[C]";
	tablero[7][6]="[C]";
	tablero2[7][1]=2;
	tablero2[7][6]=2;	
	
	//alfil
	tablero[7][2]="[A]";
	tablero[7][5]="[A]";
	tablero2[7][2]=2;
	tablero2[7][5]=2;

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(tablero[i][j]!="[P]" && tablero[i][j]!="[A]" && tablero[i][j]!="[T]" && tablero[i][j]!="[C]" && tablero[i][j]!="[K]" && tablero[i][j]!="[Q]"){
				tablero[i][j]="[ ]";
				tablero2[i][j]=0;
			}
		}
	}
	
	while(ganador==0 && continuar=='s'){
		move(0,0);
		printw("----------------Ajedrez--------------------");
		printw("\n");
		printw("\n");
		printw("Piezas: ");
		printw("\n");
		printw("P -> Peon      A -> Alfill      T -> Torre");
		printw("\n");
		printw("C -> Caballo   K -> Rey(king)   Q -> Reina(Quinn)");

		//imprimir tablero
		move(6,0);
		printw("   0   1   2   3   4   5   6   7");
		printw("\n");
		refresh();

		for(int i=0;i<8;i++){

			if(i==0){
				printw("A ");
			}else if(i==1){
				printw("B ");
			}else if(i==2){
				printw("C ");
			}else if(i==3){
				printw("D ");
			}else if(i==4){
				printw("E ");
			}else if(i==5){
				printw("F ");
			}else if(i==6){
				printw("G ");
			}else if(i==7){
				printw("H ");
			}

	
			for(int j=0;j<8;j++){
				if(tablero2[i][j]==1 || tablero2[i][j]==11 || tablero2[i][j]==111){
					attron(COLOR_PAIR(1));
					strcpy(temp, tablero[i][j].c_str());
					printw(temp);
					printw(" ");
					refresh();
					attroff (COLOR_PAIR(1));
				}else if(tablero2[i][j]==2 || tablero2[i][j]==22 || tablero2[i][j]==222){
					attron(COLOR_PAIR(2));
					strcpy(temp, tablero[i][j].c_str());
					printw(temp);
					printw(" ");
					refresh();
					attroff (COLOR_PAIR(2));
				}else{
					strcpy(temp, tablero[i][j].c_str());
					printw(temp);
					printw(" ");
					refresh();
				}
			}
	
			if(i==0){
				printw("A");
			}else if(i==1){
				printw("B");
			}else if(i==2){
				printw("C");
			}else if(i==3){
				printw("D");
			}else if(i==4){
				printw("E");
			}else if(i==5){
				printw("F");
			}else if(i==6){
				printw("G");
			}else if(i==7){
				printw("H");
			}
			printw("\n");
		}	

		move(15,0);
		printw("   0   1   2   3   4   5   6   7");
		//final impresion

		move(17,0);
		printw("COMO ME MUEVO?");
		printw("\n");
		printw(" (Para mover una pieza debe ingresar\n la conrdenada de la pieza que desea mover y luego hacia donde)");
		printw("\n");
		printw("\n");
		printw("Ejemplo: \n E0D0 -> E0 es la posicion de la pieza que desa mover y \n D0 es donde desea mover");
		refresh();
	
		move(7,50);
		printw("Desea continuar[s/n]: ");
		refresh();
    		continuar = getch();
		

		if(continuar=='s'){
			if(jugador==1){
				move(7,50);
				attron(COLOR_PAIR(1));
				printw("JUGADOR 1:               ");
				move(8,50);
				addstr("Ingrese cordenadas: ");
    				refresh();
   				getnstr(cordenada, sizeof(cordenada) - 1);
				refresh();
				attroff (COLOR_PAIR(1));

				//tomando cordenadas ingresadas por el usuario

				//tomando pieza a mover
				cordenada_x1=cordenada[0];
				cordenada_y1=cordenada[1];
				
				if(cordenada_x1=='A'){
					x1 = 0;
				}else if(cordenada_x1=='B'){
					x1 = 1;
				}else if(cordenada_x1=='C'){
					x1 = 2;
				}else if(cordenada_x1=='D'){
					x1 = 3;
				}else if(cordenada_x1=='E'){
					x1 = 4;
				}else if(cordenada_x1=='F'){
					x1 = 5;
				}else if(cordenada_x1=='G'){
					x1 = 6;
				}else if(cordenada_x1=='H'){
					x1 = 7;
				}else{
					Valides_entrada=1;
				}

				if(cordenada_y1=='0'){
					y1 = 0;
				}else if(cordenada_y1=='1'){
					y1 = 1;
				}else if(cordenada_y1=='2'){
					y1 = 2;
				}else if(cordenada_y1=='3'){
					y1 = 3;
				}else if(cordenada_y1=='4'){
					y1 = 4;
				}else if(cordenada_y1=='5'){
					y1 = 5;
				}else if(cordenada_y1=='6'){
					y1 = 6;
				}else if(cordenada_y1=='7'){
					y1 = 7;
				}else{
					Valides_entrada=1;
				}	
				
				//lugar hacia donde se movera la pieza
				//tomando pieza a mover
				cordenada_x2=cordenada[2];
				cordenada_y2=cordenada[3];

				if(cordenada_x2=='A'){
					x2 = 0;
				}else if(cordenada_x2=='B'){
					x2 = 1;
				}else if(cordenada_x2=='C'){
					x2 = 2;
				}else if(cordenada_x2=='D'){
					x2 = 3;
				}else if(cordenada_x2=='E'){
					x2 = 4;
				}else if(cordenada_x2=='F'){
					x2 = 5;
				}else if(cordenada_x2=='G'){
					x2 = 6;
				}else if(cordenada_x2=='H'){
					x2 = 7;
				}else{
					Valides_entrada=1;
				}

				if(cordenada_y2=='0'){
					y2 = 0;
				}else if(cordenada_y2=='1'){
					y2 = 1;
				}else if(cordenada_y2=='2'){
					y2 = 2;
				}else if(cordenada_y2=='3'){
					y2 = 3;
				}else if(cordenada_y2=='4'){
					y2 = 4;
				}else if(cordenada_y2=='5'){
					y2 = 5;
				}else if(cordenada_y2=='6'){
					y2 = 6;
				}else if(cordenada_y2=='7'){
					y2 = 7;
				}else{
					Valides_entrada=1;
				}		

				//validadno si la pieza es valida
				if(tablero2[x1][y1]==1 || tablero2[x1][y1]==11 || tablero2[x1][y1]==111){
					if(tablero2[x2][y2]==1 || tablero2[x2][y2]==11 || tablero2[x2][y2]==111 || Valides_entrada==1){
						move(7,50);
						printw("Ingreso cordenadas no valida");
						move(8,50);
						printw("Desea continuar[s/n]:       ");
						refresh();
    						continuar = getch();	
					}else{
						if(tablero[x1][y1]=="[P]" && tablero2[x2][y2]!=2 && tablero2[x2][y2]!=22 && tablero2[x2][y2]!=222){
							if(tablero2[x1][y1]==111){
								if(x2==x1+2 && y1==y2){
									tablero[x2][y2]="[P]";
									tablero2[x2][y2]= 1;
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;	
								}else if(x2==x1+1 && y1==y2){
									tablero[x2][y2]="[P]";
									tablero2[x2][y2]= 1;
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
								}else if(x1+2==x2 && y1+2==y2){
									if(tablero2[x1+1][y1+1]==2 || tablero2[x1+1][y1+1]==222 || tablero2[x1+1][y1+1]==22){
										tablero[x1][y1]="[ ]";
										tablero2[x1][y1]= 0;
										tablero[x2][y2]="[P]";
										tablero2[x2][y2]= 1;
										tablero[x1+1][y1+1]="[ ]";
										tablero2[x1+1][y1+1]= 0;
									}								
								}
							}else if(tablero2[x1][y1]==1){
								if(x2==x1+1 && y1==y2){
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[P]";
									tablero2[x2][y2]= 1;
								}else if(x1+2==x2 && y1+2==y2){
									if(tablero2[x1+1][y1+1]==2 || tablero2[x1+1][y1+1]==222 || tablero2[x1+1][y1+1]==22){
										tablero[x1][y1]="[ ]";
										tablero2[x1][y1]= 0;
										tablero[x2][y2]="[P]";
										tablero2[x2][y2]= 1;
										tablero[x1+1][y1+1]="[ ]";
										tablero2[x1+1][y1+1]= 0;
									}								
								}
							}
						}else if(tablero[x1][y1]=="[T]"){
							validar_movimiento=0;
							if(x1==x2){
								if(y1<y2){
									for(int i=y1;i<y2;i++){
										if(tablero2[x1][i]!=0 && i!=y1){
											validar_movimiento++;	
										}	
									}	
								}else if(y1>y2){
									for(int i=y1;i>y2;i--){
										if(tablero2[x1][i]!=0 && i!=y1){
											validar_movimiento++;	
										}
									}	
								}
							}else if(y1==y2){
								if(x1<x2){
									for(int i=x1;i<x2;i++){
										if(tablero2[i][y1]!=0 && i!=x1){
											validar_movimiento++;	
										}	
									}	
								}else if(y1>y2){
									for(int i=y1;i>y2;i--){
										if(tablero2[i][y1]!=0 && i!=x1){
											validar_movimiento++;	
										}
									}	
								}
							}

							if(validar_movimiento==0){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[T]";
								tablero2[x2][y2]= 1;
							}
						}else if(tablero[x1][y1]=="[C]"){
							if(x2==x1+2 && y2==y1-1){
								if(tablero2[x1+1][y1]!=0 || tablero2[x1+2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1+2 && y2==y1+1){
								if(tablero2[x1+1][y1]!=0 || tablero2[x1+2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1+1 && y2==y1+2){
								if(tablero2[x1][y1+1]!=0 || tablero2[x1][y1+2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1-1 && y2==y1+2){
								if(tablero2[x1][y1+1]!=0 || tablero2[x1][y1+2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1+1 && y2==y1-2){
								if(tablero2[x1][y1-1]!=0 || tablero2[x1][y1-2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1-1 && y2==y1-2){
								if(tablero2[x1][y1-1]!=0 || tablero2[x1][y1-2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1-2 && y2==y1+1){
								if(tablero2[x1-1][y1]!=0 || tablero2[x1-2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1-2 && y2==y1-1){
								if(tablero2[x1-1][y1]!=0 || tablero2[x1-2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}
						}else if(tablero[x1][y1]=="[A]"){

						}else if(tablero[x1][y1]=="[K]"){
							if(x2==x1+1 && y1==y2){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 1;
							}else if(x2==x1-1 && y1==y2){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 1;
							}else if(x2==x1 && y2==y1+1){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 1;
							}else if(x2==x1 && y2==y1-1){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 1;
							}
						}else if(tablero[x1][y1]=="[Q]"){

						}
					}
				}else{
					move(7,50);
					printw("Ingreso cordenadas no valida");
					move(8,50);
					printw("Desea continuar[s/n]:       ");
					refresh();
    					continuar = getch();
				}				

				jugador++;
			}else if(jugador==2){
				move(7,50);
				attron(COLOR_PAIR(2));
				printw("JUGADOR 2:               ");
				move(8,50);
				addstr("Ingrese cordenadas: ");
    				refresh();
   				getnstr(cordenada, sizeof(cordenada) - 1);
				refresh();
				attroff (COLOR_PAIR(2));

				//tomando cordenadas ingresadas por el usuario

				//tomando pieza a mover
				cordenada_x1=cordenada[0];
				cordenada_y1=cordenada[1];
				
				if(cordenada_x1=='A'){
					x1 = 0;
				}else if(cordenada_x1=='B'){
					x1 = 1;
				}else if(cordenada_x1=='C'){
					x1 = 2;
				}else if(cordenada_x1=='D'){
					x1 = 3;
				}else if(cordenada_x1=='E'){
					x1 = 4;
				}else if(cordenada_x1=='F'){
					x1 = 5;
				}else if(cordenada_x1=='G'){
					x1 = 6;
				}else if(cordenada_x1=='H'){
					x1 = 7;
				}else{
					Valides_entrada=1;
				}

				if(cordenada_y1=='0'){
					y1 = 0;
				}else if(cordenada_y1=='1'){
					y1 = 1;
				}else if(cordenada_y1=='2'){
					y1 = 2;
				}else if(cordenada_y1=='3'){
					y1 = 3;
				}else if(cordenada_y1=='4'){
					y1 = 4;
				}else if(cordenada_y1=='5'){
					y1 = 5;
				}else if(cordenada_y1=='6'){
					y1 = 6;
				}else if(cordenada_y1=='7'){
					y1 = 7;
				}else{
					Valides_entrada=1;
				}	
				
				//lugar hacia donde se movera la pieza
				//tomando pieza a mover
				cordenada_x2=cordenada[2];
				cordenada_y2=cordenada[3];

				if(cordenada_x2=='A'){
					x2 = 0;
				}else if(cordenada_x2=='B'){
					x2 = 1;
				}else if(cordenada_x2=='C'){
					x2 = 2;
				}else if(cordenada_x2=='D'){
					x2 = 3;
				}else if(cordenada_x2=='E'){
					x2 = 4;
				}else if(cordenada_x2=='F'){
					x2 = 5;
				}else if(cordenada_x2=='G'){
					x2 = 6;
				}else if(cordenada_x2=='H'){
					x2 = 7;
				}else{
					Valides_entrada=1;
				}

				if(cordenada_y2=='0'){
					y2 = 0;
				}else if(cordenada_y2=='1'){
					y2 = 1;
				}else if(cordenada_y2=='2'){
					y2 = 2;
				}else if(cordenada_y2=='3'){
					y2 = 3;
				}else if(cordenada_y2=='4'){
					y2 = 4;
				}else if(cordenada_y2=='5'){
					y2 = 5;
				}else if(cordenada_y2=='6'){
					y2 = 6;
				}else if(cordenada_y2=='7'){
					y2 = 7;
				}else{
					Valides_entrada=1;
				}		

				//validadno si la pieza es valida
				if(tablero2[x1][y1]==2 || tablero2[x1][y1]==22 || tablero2[x1][y1]==222){
					if(tablero2[x2][y2]==2 || tablero2[x2][y2]==22 || tablero2[x2][y2]==222 || Valides_entrada==1){
						move(7,50);
						printw("Ingreso cordenadas no valida");
						move(8,50);
						printw("Desea continuar[s/n]:       ");
						refresh();
    						continuar = getch();	
					}else{
						if(tablero[x1][y1]=="[P]" && tablero2[x2][y2]!=1 && tablero2[x2][y2]!=11 && tablero2[x2][y2]!=111){
							if(tablero2[x1][y1]==222){
								if(x2==x1-2 && y1==y2){
									tablero[x2][y2]="[P]";
									tablero2[x2][y2]= 2;
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;	
								}else if(x2==x1-1 && y1==y2){
									tablero[x2][y2]="[P]";
									tablero2[x2][y2]= 2;
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
								}else if(x1-2==x2 && y1-2==y2){
									if(tablero2[x1-1][y1-1]==1 || tablero2[x1-1][y1-1]==111 || tablero2[x1-1][y1+1]==11){
										tablero[x1][y1]="[ ]";
										tablero2[x1][y1]= 0;
										tablero[x2][y2]="[P]";
										tablero2[x2][y2]= 2;
										tablero[x1+1][y1+1]="[ ]";
										tablero2[x1+1][y1+1]= 0;
									}								
								}
							}else if(tablero2[x1][y1]==2){
								if(x2==x1-1 && y1==y2){
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[P]";
									tablero2[x2][y2]= 2;
								}else if(x1-2==x2 && y1-2==y2){
									if(tablero2[x1+1][y1+1]==2 || tablero2[x1+1][y1+1]==222 || tablero2[x1+1][y1+1]==22){
										tablero[x1][y1]="[ ]";
										tablero2[x1][y1]= 0;
										tablero[x2][y2]="[P]";
										tablero2[x2][y2]= 2;
										tablero[x1+1][y1+1]="[ ]";
										tablero2[x1+1][y1+1]= 0;
									}								
								}
							}
						}else if(tablero[x1][y1]=="[T]"){
							validar_movimiento=0;
							if(x1==x2){
								if(y1<y2){
									for(int i=y1;i<y2;i++){
										if(tablero2[x1][i]!=0 && i!=y1){
											validar_movimiento++;	
										}	
									}	
								}else if(y1>y2){
									for(int i=y1;i>y2;i--){
										if(tablero2[x1][i]!=0 && i!=y1){
											validar_movimiento++;	
										}
									}	
								}
							}else if(y1==y2){
								if(x1<x2){
									for(int i=x1;i<x2;i++){
										if(tablero2[i][y1]!=0 && i!=x1){
											validar_movimiento++;	
										}	
									}	
								}else if(y1>y2){
									for(int i=y1;i>y2;i--){
										if(tablero2[i][y1]!=0 && i!=x1){
											validar_movimiento++;	
										}
									}	
								}
							}

							if(validar_movimiento==0){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[T]";
								tablero2[x2][y2]= 2;
							}
						}else if(tablero[x1][y1]=="[C]"){
							if(x2==x1+2 && y2==y1-1){
								if(tablero2[x1+1][y1]!=0 || tablero2[x1+2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}else if(x2==x1+2 && y2==y1+1){
								if(tablero2[x1+1][y1]!=0 || tablero2[x1+2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}else if(x2==x1+1 && y2==y1+2){
								if(tablero2[x1][y1+1]!=0 || tablero2[x1][y1+2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}else if(x2==x1-1 && y2==y1+2){
								if(tablero2[x1][y1+1]!=0 || tablero2[x1][y1+2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}else if(x2==x1+1 && y2==y1-2){
								if(tablero2[x1][y1-1]!=0 || tablero2[x1][y1-2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}else if(x2==x1-1 && y2==y1-2){
								if(tablero2[x1][y1-1]!=0 || tablero2[x1][y1-2]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}else if(x2==x1-2 && y2==y1+1){
								if(tablero2[x1-1][y1]!=0 || tablero2[x1-2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 1;
								}
							}else if(x2==x1-2 && y2==y1-1){
								if(tablero2[x1-1][y1]!=0 || tablero2[x1-2][y1]!=0){

								}else{
									tablero[x1][y1]="[ ]";
									tablero2[x1][y1]= 0;
									tablero[x2][y2]="[C]";
									tablero2[x2][y2]= 2;
								}
							}
						}else if(tablero[x1][y1]=="[A]"){

						}else if(tablero[x1][y1]=="[K]"){
							if(x2==x1+1 && y1==y2){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 2;
							}else if(x2==x1-1 && y1==y2){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 2;
							}else if(x2==x1 && y2==y1+1){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 2;
							}else if(x2==x1 && y2==y1-1){
								tablero[x1][y1]="[ ]";
								tablero2[x1][y1]= 0;
								tablero[x2][y2]="[K]";
								tablero2[x2][y2]= 2;
							}
						}else if(tablero[x1][y1]=="[Q]"){

						}
					}
				}else{
					move(7,50);
					printw("Ingreso cordenadas no valida");
					move(8,50);
					printw("Desea continuar[s/n]:       ");
					refresh();
    					continuar = getch();
				}	

				jugador--;
			}
			Valides_entrada=0;
		}
		clear();

	}
	printw("Gracias por jugar adios");
	getch();
	endwin();
	return 0;
}
