#include "StdAfx.h"
#include "Som.h"






void init_reference(){

	int i,j,k;
	for (i=0; i < N_XUNITS; i++)
		for (j=0; j < N_YUNITS; j++)
			for (k=0; k<DIM_INPUT; k++)
				RV[i][j][k] = drand48();

}




void Som::Learning(){

	int i,j,n;
	double x,y;
	long seed = 1234567;
	double alpha,sigma;

	srand(time(NULL));
	srand48(time(NULL));


	while(1){
		init_reference();
		for(i=0;i<N_LEARNING;i++){
		
			alpha = 1-(double)i/(double)N_LEARNING;
			for(j=0;j<N_SUB_LEARNING;j++)	som2d(alpha);
			if(i%10==true){
				write_data();
			}
		}
	}
	fclose(gp);





}




/*
Som::Som(void)
{
}


Som::~Som(void)
{
}
*/
