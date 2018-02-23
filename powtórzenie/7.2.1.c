#include <stdio.h>

struct trojkat{
	int bok1;
	int bok2;
	int bok3;
};

int obwod(struct trojkat parametry){
	
	return parametry.bok1 + parametry.bok2 + parametry.bok3;
}


int main(){
	
	struct trojkat parametry = {1, 2, 3};
	int wynik = obwod(parametry);
	
	printf("%d", wynik);
	
	return 0;
}
