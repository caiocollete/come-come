struct TpMap{
	char** mat;
	int linhas,colunas;
};

struct TpHero{
	int x,y;
};

void readMap();
void printMap();
void alocMem();
void freeMemoryMap();
void searchPosHero();
void move(TpHero &hero,char tecla,int &wins);
