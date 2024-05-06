#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio2.h>
#include "map.h"

TpMap map;

void freeMemoryMap(){
	for(int i=0;i<map.linhas;i++) 
		free(map.mat[i]);
	free(map.mat);
}

void readMap(){
	FILE *p = fopen("map.txt","r");
	
	//alocando espaco dinamicamente
	fscanf(p,"%d %d",&map.linhas,&map.colunas);
	alocMem();
	//
	
	for(int i=0; i<map.linhas;i++){
		fscanf(p,"%s",map.mat[i]);
	}
	fclose(p);
}

void printMap(){
	for(int i=0; i<map.linhas;i++){
		printf("%s\n",map.mat[i]);
	}
}

void alocMem(){
	map.mat=(char **)malloc(sizeof(int*) * map.linhas);
	for(int i=0;i<map.linhas;i++)
		map.mat[i]=(char *)malloc(sizeof(int) * (map.colunas+1));
}


void move(TpHero &hero,char tecla,int &wins){
	switch(tecla){
		case 'w': //cima
				if(map.mat[hero.x-1][hero.y]=='>'){
					wins=1;
				}
				if(map.mat[hero.x-1][hero.y]=='.'){
					map.mat[hero.x][hero.y]='.';
					map.mat[hero.x-1][hero.y]='@';
					hero.x=hero.x-1;
				}
	
				break;	
				
				
		case 's': //baixo
				if(map.mat[hero.x+1][hero.y]=='>'){
					wins=1;
				}
				if(map.mat[hero.x+1][hero.y]=='.'){
					map.mat[hero.x][hero.y]='.';
					map.mat[hero.x+1][hero.y]='@';
					hero.x=hero.x+1;
				}	
				break;	
						
		case 'd': //direita
				if(map.mat[hero.x][hero.y+1]=='>'){
					wins=1;
				}
				if(map.mat[hero.x][hero.y+1]=='.'){
					map.mat[hero.x][hero.y]='.';
					map.mat[hero.x][hero.y+1]='@';
					hero.y=hero.y+1;					
				}
				break;
						
		case 'a': //esquerda
				if(map.mat[hero.x][hero.y-1]=='>'){
					wins=1;
				}
				if(map.mat[hero.x][hero.y-1]=='.'){
					map.mat[hero.x][hero.y]='.';
					map.mat[hero.x][hero.y-1]='@';
					hero.y=hero.y-1;					
				}	
				break;		
	}
}

void searchPosHero(TpHero &h){
	for(int i=0; i<map.linhas;i++){
		for(int j=0;j<map.colunas; j++){
			if(map.mat[i][j]=='@'){
				h.x=i;
				h.y=j;
			}
		}
	}
}

int main(){
	TpHero hero;
	char tecla;
	int wins=0;
	
	readMap();
	searchPosHero(hero);
	
	do{
		system("cls");
		printMap();
		
		tecla=getch();
		tecla=tolower(tecla);
		
		move(hero,tecla,wins);
		
	}while(wins!=1);
	
	printf("Wins!");
	
	freeMemoryMap();
}
