#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <windows.h> 

int cn = 0;
int o = 0;
int x = 0;

int door[3] = {0,0,0};

int main(){
	srand(time(NULL));
	for(;;){
		cn++;
		for(int i=0; i<3; i++) door[i]=0;
		int car = rand() % 3;
		door[car] = 1;
		for(int i=0; i<3; i++){
			if(door[i]!=1) door[i]=-9;
		}
		int cos = rand() % 3;
		int fcos = cos;
		for(int i=0; i<3; i++){
			if(door[i]==-9 && i!=cos){
				door[i] = -99;
				break;
			}
		}
		for(int i=0; i<3; i++){
			if(i!=cos && door[i]!=-99){
				cos = i;
				break;
			}
		}
		if(door[cos]==1){
			o++;
		}else x++;
		
		printf("%.2f%%\n", (double) o / (double) cn * 100.0);
		printf("%d %d %d\n",door[0],door[1],door[2]);
		printf("success:%d  fail:%d  count:%d \n",o,x,cn);
		printf("first door:%d  changed door:%d \n",fcos,cos);
		printf("\n");
		Sleep(5);
	}
}
