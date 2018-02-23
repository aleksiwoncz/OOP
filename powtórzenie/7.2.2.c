#include <stdio.h>

struct trojkat{
	int bok1;
	int bok2;
	int bok3;
};

void zamiana(struct trojkat troj1, struct trojkat *troj2){
	
	*troj2 = troj1;
}


int main(){
	
	struct trojkat parametry = {1, 2, 3};
	struct trojkat parametry2 = {2, 3, 4};
	struct trojkat *troj2 = &parametry2;
	
	zamiana(parametry, troj2);
	
	printf("%d %d %d", parametry2.bok1, parametry.bok2, parametry.bok3);
	
	return 0;
}
