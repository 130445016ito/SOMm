#include "StdAfx.h"
#include "Scene.h"

#define sleep(n) Sleep(n*1000)

//	coordinate
//	(-1,1)____________
//	|		|(0,1)	  |
//	|		|		  |
//	|		|		  |
//	|		|		  |
//	|		|(0,0)	  |
//	|		|		  |
//	|		|		  |
//	|		|		  |
//	|		|		  |
//	|		|(0,-1)	  |(1,-1)
//	-------------------


void Scene::draw(void)
{
	for(ui i=0; i<numNeuro; i++){
		posY=(double)i*dia;
		for(ui j=0; j<numNeuro; j++){
			posX=(double)j*dia;
			glPushMatrix();
				glColor3d(refVec[j][i][0],refVec[j][i][1],refVec[j][i][2]);
				//glColor3d(refVec[j][i][0], 1-refVec[j][i][0],0 /*refVec[j][i][2]*/);	
				//glColor3d(1/*refVec[j][i][0]*/,1-refVec[j][i][1],1 /*refVec[j][i][2]*/);	
				glTranslated(rad+posX, rad+posY ,0.00);
				glTranslated(zeroCoordX, zeroCoordY, 0.00);
				glutSolidSphere(rad, 15, 15);	
			glPopMatrix();
		}
	}
	/*
	posY*=dia;
	posX*=dia;

			glPushMatrix();
				glColor3d(0,0,1);	
				glTranslated(rad+posX, rad+posY ,0.00);
				glTranslated(zeroCoordX, zeroCoordY, 0.00);
				glutSolidSphere(rad*2, 20, 30);	
			glPopMatrix();
			*/

} 

void Scene::CurDraw(void)
{
	//途中で再帰的に呼び出されていないかチェック
	static ui check;
	check++;

	static double oldPosX[64],oldPosY[64];
	//static ui count;
	double dis;
	double mark=0.04;

	//整数の座標からOpenGL座標へ縮小．
	//OnPaintの呼び出しが高速の場合は注意．（二回続けて呼ばれた場合，curPosの値が変化する）
	curPosY*=dia;
	curPosX*=dia;

	//printf("pos=%f\n",curPosX);

	//curPosの描画（SPHERE）
	glPushMatrix();
		glColor3d(1,1,1);
//		glLineWidth(100);
		glTranslated(rad+curPosX, rad+curPosY ,0.00);
		glTranslated(zeroCoordX, zeroCoordY, 0.00);
		glutSolidSphere(rad*2, 20, 30);
/*		glPushMatrix();
			glBegin(GL_LINES);
				glVertex2d(-mark,mark);
				glVertex2d(mark,-mark);
				glVertex2d(-mark,-mark);
				glVertex2d(mark,mark);
			glEnd();
		glPopMatrix();
*/
	glPopMatrix();

	//lineを繋ぐ点同士が離れすぎていないか，あるいは規定数を接続したかの判定
	if(countLine){
		dis=sqrt((curPosX-oldPosX[countLine-1])*(curPosX-oldPosX[countLine-1])+(curPosY-oldPosY[countLine-1])*(curPosY-oldPosY[countLine-1]));
		if(dis>(double)numNeuro*dia/2)
			countLine=0;
		else if(countLine>20){
			countLine=0;
			sleep(1);	//無理やり注意
		}
	}

	//curPosまでのlineを接続
	oldPosX[countLine]=curPosX;
	oldPosY[countLine]=curPosY;
		
	if(countLine){
		glColor3d(1,1,1);
		glLineWidth(3.0);
		glPushMatrix();
			glBegin(GL_LINES);
			for(ui i=0; i<countLine; i++){
				glVertex2d(zeroCoordX+rad+oldPosX[i], zeroCoordY+rad+oldPosY[i]);
				glVertex2d(zeroCoordX+rad+oldPosX[i+1], zeroCoordY+rad+oldPosY[i+1]);
			}
			glEnd();
		glPopMatrix();

		for(ui i=0; i<countLine; i++){
			glPushMatrix();
			glColor3d(1,1,1);
			glTranslated(rad+oldPosX[i], rad+oldPosY[i] ,0.00);
			glTranslated(zeroCoordX, zeroCoordY, 0.00);
			glutSolidSphere(rad, 20, 30);
			glPopMatrix();
		}

	}
	
	countLine++;

	
	//途中で再帰的に呼び出されていないかチェック
	if(check>1)
		printf("【注意！再帰的に関数が呼び出されています】\n");
	else if(check==1)
		check=0;
	else
		printf("【これが出たら意味不明】\n");

}


void Scene::init_reference(){
	ui i,j,k;
	for (i=0; i < numNeuro; i++)
		for (j=0; j < numNeuro; j++)
			for (k=0; k < numInpDim; k++)
				refVec[i][j][k] = (double)rand()/RAND_MAX;

	
}




void Scene::Som2d(int numSample){
	ui i,j,k;
	double tmp;
	double min;
	double denom;
	double hci;
	double dist;
	double sum = 0.0;

	//Position argmin;
	ui posX,posY;

	/**********************************/
	double sigma;
	double alpha;
	//alpha = 1-(double)count/(double)numLearn;
	//sigma=alpha + 10.3;
	alpha=0.8;
	sigma=5;

	///////////////////////////////追加(1/4)//////////////////////////

	/*
	accScene[0]=accArr[0];
	accScene[1]=accArr[1];
	accScene[2]=accArr[2];
	*/

	///////////////////////////////追加(1/4)//////////////////////////

	
	//↓一旦コメントアウト↓//
	/*
	static int colorTemp=1;

		//rand()%8+1;
	colorTemp++;
	if(colorTemp>3)
		colorTemp=1;

	if(colorTemp==1){
		inpVec[0] = 1;	//  ← ex)inpVec[0] = subaccArrDlg[0][0]
		inpVec[1] = 0;
		inpVec[2] = 0;
	}else if(colorTemp==2){
		inpVec[0] = 0;
		inpVec[1] = 1;
		inpVec[2] = 0;
	}else if(colorTemp==3){
		inpVec[0] = 0;
		inpVec[1] = 0;
		inpVec[2] = 1;
	}else if(colorTemp==4){
		inpVec[0] = 1;
		inpVec[1] = 1;
		inpVec[2] = 0;
	}else if(colorTemp==5){
		inpVec[0] = 0;
		inpVec[1] = 1;
		inpVec[2] = 1;
	}else if(colorTemp==6){
		inpVec[0] = 1;
		inpVec[1] = 0;
		inpVec[2] = 1;
	}else if(colorTemp==7){
		inpVec[0] = 1;
		inpVec[1] = 1;
		inpVec[2] = 1;
	}else if(colorTemp==8){
		inpVec[0] = 0;
		inpVec[1] = 0;
		inpVec[2] = 0;
	}
	*/
	///↑ここまでコメントアウト↑//


	
	 
	//++++++++++++++++++++++++++++++++++++++++開発中+++++++++++++++++++++++++++++++//

	static int colorTemp=1;

		rand()%8+1;
	colorTemp++;
	if(colorTemp>3)
		colorTemp=1;
/// (6/28学習プログラムのみの為、一時コメントアウト)

	static int count=0;

	if(count>=numSample)
		count=0;

	for(i=0;i<numInpDim;i++)
		inpVec[i] = subAccArrDlg[i][count];	//  ← ex)inpVec[0] = subaccArrDlg[0][0] or subangArrDlg[][]

	count++;

/*	}else if(colorTemp==2){
		inpVec[0] = 0;
		inpVec[1] = 1;
		inpVec[2] = 0;
	}else if(colorTemp==3){
		inpVec[0] = 0;
		inpVec[1] = 0;
		inpVec[2] = 1;
	}else if(colorTemp==4){
		inpVec[0] = 1;
		inpVec[1] = 1;
		inpVec[2] = 0;
	}else if(colorTemp==5){
		inpVec[0] = 0;
		inpVec[1] = 1;
		inpVec[2] = 1;
	}else if(colorTemp==6){
		inpVec[0] = 1;
		inpVec[1] = 0;
		inpVec[2] = 1;
	}else if(colorTemp==7){
		inpVec[0] = 1;
		inpVec[1] = 1;
		inpVec[2] = 1;
	}else if(colorTemp==8){
		inpVec[0] = 0;
		inpVec[1] = 0;
		inpVec[2] = 0;
	}
	


	*/

	/* Find the closest ref. vector */
	for (k=0; k<numInpDim; k++){
		tmp = refVec[0][0][k] - inpVec[k];
		sum += tmp*tmp;
	}
	posX = 0;
	posY = 0;
	min = sum;

	for (i=0; i<numNeuro; i++){
		for (j=0; j<numNeuro; j++){
			sum = 0.0;
			for (k=0; k<numInpDim; k++){
				tmp = refVec[i][j][k] - inpVec[k];
				sum += tmp*tmp;
			}
			if ( sum < min ){
			min = sum;
			posX = i;
			posY = j;
			}
		}
	}

	/* learning */
	for (i=0; i<numNeuro; i++){
		for (j=0; j<numNeuro; j++){
			dist = (i-posX)*(i-posX) +(j-posY)*(j-posY);
			denom = 2*sigma*sigma;
			hci = alpha*exp(-(double)dist/denom);

			for (k=0; k<numInpDim; k++)
				refVec[i][j][k] = refVec[i][j][k] +	hci* (inpVec[k] -refVec[i][j][k]);
		}
	}

}

void Scene::UseSOM(double current[]){
	ui i,j,k;
	double tmp;
	double min;
	double denom;
	double hci;
	double dist;
	double sum = 0.0;

	//Position argmin;
	ui posX,posY;

	/**********************************/
	double sigma;
	double alpha;
	//alpha = 1-(double)count/(double)numLearn;
	//sigma=alpha + 10.3;
	alpha=0.8;
	sigma=5;

	//static int count=0;

	//if(count>19)
	//	count=0;

	for(i=0;i<numInpDim;i++)
		inpVec[i] = current[i];	//  ← ex)inpVec[0] = subaccArrDlg[0][0] or subangArrDlg[][]

	//count++;


	/* Find the closest ref. vector */
	for (k=0; k<numInpDim; k++){
		tmp = refVec[0][0][k] - inpVec[k];
		sum += tmp*tmp;
	}
	posX = 0;
	posY = 0;
	min = sum;

	for (i=0; i<numNeuro; i++){
		for (j=0; j<numNeuro; j++){
			sum = 0.0;
			for (k=0; k<numInpDim; k++){
				tmp = refVec[i][j][k] - inpVec[k];
				sum += tmp*tmp;
			}
			if ( sum < min ){
			min = sum;
			curPosX = i;
			curPosY = j;
			}
		}
	}

	//　OnPaintの処理が高速の場合は，ここでOpenGLの座標変換をしておくことも考慮すること．
	//	curPosY*=dia;	
	//	curPosX*=dia;

}




int Scene::TasTest(){

	int iii;
	int jjj=4,kkk=7;

	//iii=numNeuro+kkk;
	iii=inpVec[0];

	return iii;



}


int Scene::TasTest2(){

	return inpVec[0];
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//---------------------- G ----------------------------------------------------

void G_Scene::G_Draw(void)
{
	//draw for active object
	for(ui i=0; i<numGroup; i++){
		glPushMatrix();
			glColor3d(actGroup[i].col[0], actGroup[i].col[1], actGroup[i].col[2]);	
			glTranslated(actGroup[i].pos[0]*0.1, actGroup[i].pos[1]*0.1, 0.00);
			glTranslated(0, -rad*0.1, 0);
			glutSolidSphere(rad*0.1, 15, 15);	
		glPopMatrix();
	}

	// draw from grid information
	for(ui i=0; i<numHorisphe; i++){
		for(ui j=0; j<numVertsphe; j++){
			if(gridInfo[i][j].flag){
				glPushMatrix();
					glColor3d(gridInfo[i][j].col[0], gridInfo[i][j].col[1], gridInfo[i][j].col[2]);	
					glTranslated((int)(i-halfHori)*0.1, (int)(j-halfVert)*0.1, 0.00);	// ui-ui=negative -> X
					glTranslated(0, -rad*0.1, 0);
					glutSolidSphere(rad*0.1, 15, 15);	
				glPopMatrix();				
			}
		}
	}
	
	// draw wall line
	glPushMatrix();
		glColor3d(1,0,0);
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2f( (leftWall+rad)*0.1, -1 );
		glVertex2f( (leftWall+rad)*0.1, 1 );
		glEnd();

		glBegin(GL_LINES);
		glVertex2f( (rightWall-rad)*0.1, -1);
		glVertex2f( (rightWall-rad)*0.1, 1);
		glEnd();
	glPopMatrix();

	// draw score
	char str[256],str2[256];

	glPushMatrix();
		sprintf(str,"SCORE:%d\n",score);
		glColor3d(1, 0, 1);
		glRasterPos2f(-0.9,0.8);
		for(ui kk=0; kk<strlen(str); kk++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[kk]);
	glPopMatrix();

	glPushMatrix();
		sprintf(str2,"maxChain:%d\n",maxChain/4);
		glColor3d(1, 0, 1);
		glRasterPos2f(-0.9,0.6);
	
		for(ui kk=0; kk<strlen(str2); kk++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str2[kk]);
	glPopMatrix();
	
} 


void G_Scene::G_Init(void){

	actGroup[0].pos[0] = zeroCoordX1;
	actGroup[0].pos[1] = zeroCoordY1;
	actGroup[1].pos[0] = zeroCoordX1;
	actGroup[1].pos[1] = zeroCoordY1-dia;
	actGroup[2].pos[0] = zeroCoordX1;
	actGroup[2].pos[1] = zeroCoordY1-2*dia;
	actGroup[1].state=false;			// state of group = vert.mode (state=false)
	G_SetColor();

	for(ui i=0; i<numHorisphe; i++){
		for(ui j=0; j<numVertsphe; j++){
			gridInfo[i][j].checkFlag=false;
			gridInfo[i][j].elimFlag=false;
		}
	}

	eraseFlag=true;

	scoreBonus=0;

	printf("CURRENT SCPRE:%d\n",score);
	
}


void G_Scene::G_NextStep(void){

	ui scoreTemp=0;
	chain=0;
	//score=0;

	if(G_Coll('b')){
		for(ui i=0; i<numGroup; i++)
			actGroup[i].pos[1] -= 1;
	}else{

		G_CheckNextVacancy();
		while(eraseFlag){		
			eraseFlag=G_CheckElimination();	// if eraseFlag is fase, grid was not erased in pre step.
			G_SetBottom();
			Sleep(500);
			//chain++;
		}
		//cheeeet
		//if(gridInfo[-4+halfHori][-9+halfVert-1].flag && gridInfo[-4+halfHori][-9+halfVert-1].colInfo==1)
		if(chain>maxChain)
			maxChain=chain;

		G_Init();



	}

	if(gridInfo[zeroCoordX1+halfHori][zeroCoordY1+halfVert-1].flag){
		G_End();

	}


		
}

void G_Scene::G_Trans(char a){

	switch (a){
		case 'r':	// right
			if(G_Coll('r'))
				for(ui i=0; i<numGroup; i++)
					actGroup[i].pos[0] += 1;
			break;
		case 'l':	// left
			if(G_Coll('l'))
				for(ui i=0; i<numGroup; i++)
					actGroup[i].pos[0] -= 1;
			break;
		case 'u':	// up
			G_CheckNextVacancy();
			break;
		case 'd':	// down
			if(G_Coll('b')){
				for(ui i=0; i<numGroup; i++)
					actGroup[i].pos[1] -= 1;
			}else{
				G_CheckNextVacancy();
				//G_CheckElimination();
				//G_Init();
			}
			break;
		case '0':	// rotation
			G_Rot();
			actGroup[1].state=!actGroup[1].state; // input the state for base obj
			break;

//			change
//			dum = actGroup[2];
//			actGroup[2] = actGroup[0];
//			actGroup[0] = dum;
	}



}

void G_Scene:: G_Rot(void){

	double dx,dy;
	


	// distance from base object
	dx = actGroup[0].pos[0] - actGroup[1].pos[0];
	dy = actGroup[0].pos[1] - actGroup[1].pos[1];

	// rotation matrix
	actGroup[0].pos[0] = actGroup[1].pos[0] + (int)(dx*cos(M_PI/2)-dy*sin(M_PI/2));
	actGroup[0].pos[1] = actGroup[1].pos[1] + (int)(dy*cos(M_PI/2)+dx*sin(M_PI/2));

	// distance from base object
	dx = actGroup[2].pos[0] - actGroup[1].pos[0];
	dy = actGroup[2].pos[1] - actGroup[1].pos[1];

	// rotation matrix
	actGroup[2].pos[0] = actGroup[1].pos[0] + (int)(dx*cos(M_PI/2)-dy*sin(M_PI/2));
	actGroup[2].pos[1] = actGroup[1].pos[1] + (int)(dy*cos(M_PI/2)+dx*sin(M_PI/2));

	if((gridInfo[actGroup[0].pos[0]+halfHori][actGroup[0].pos[1]+halfVert].flag) || (gridInfo[actGroup[2].pos[0]+halfHori][actGroup[2].pos[1]+halfVert].flag)){
		// distance from base object
		dx = actGroup[0].pos[0] - actGroup[1].pos[0];
		dy = actGroup[0].pos[1] - actGroup[1].pos[1];
		// rotation matrix
		actGroup[0].pos[0] = actGroup[1].pos[0] + (int)(dx*cos(-M_PI/2)-dy*sin(-M_PI/2));
		actGroup[0].pos[1] = actGroup[1].pos[1] + (int)(dy*cos(-M_PI/2)+dx*sin(-M_PI/2));

		// distance from base object
		dx = actGroup[2].pos[0] - actGroup[1].pos[0];
		dy = actGroup[2].pos[1] - actGroup[1].pos[1];
		// rotation matrix
		actGroup[2].pos[0] = actGroup[1].pos[0] + (int)(dx*cos(-M_PI/2)-dy*sin(-M_PI/2));
		actGroup[2].pos[1] = actGroup[1].pos[1] + (int)(dy*cos(-M_PI/2)+dx*sin(-M_PI/2));
	}

			
}


bool G_Scene::G_Coll(char a){

	switch (a){
		case 'b':	// bottom (Group)
			for(ui i=0; i<numGroup; i++)
				if(actGroup[i].pos[1]-1 == -10)		// ground.y = -10
					return false;
				else if(gridInfo[actGroup[i].pos[0]+halfHori][actGroup[i].pos[1]+halfVert-1].flag)	// if collision (flag=true)
					return false;
			break;
		case 'r':	// right wall
			for(ui i=0; i<numGroup; i++)
				if(actGroup[i].pos[0]+1 == rightWall)		// right wall = 4
					return false;
			else if(gridInfo[actGroup[i].pos[0]+halfHori+1][actGroup[i].pos[1]+halfVert].flag)		// right colision
					return false;
			break;
		case 'l':	// left wall
			for(ui i=0; i<numGroup; i++)
				if(actGroup[i].pos[0]-1 == leftWall)		// left wall = 4
					return false;
				else if(gridInfo[actGroup[i].pos[0]+halfHori-1][actGroup[i].pos[1]+halfVert].flag)		// left colision
					return false;
			break;

		case 'B':	// bottom (when all obj drop, func return false)
			ui j=0;
			for(ui i=0; i<numGroup; i++)
				if(gridInfo[actGroup[i].pos[0]+halfHori][actGroup[i].pos[1]+halfVert-1].flag || actGroup[i].pos[1]-1 == -10)
					j++;
			if (j==numGroup)	return false;		// if all obj collide
			else				return true;
			break;



	}

	return true;

}



void G_Scene::G_CheckNextVacancy(void){


	if(actGroup[1].state)		// if Group State is hori. mode (state=true)
		do{
			for(ui i=0; i<numGroup; i++){
				if(actGroup[i].pos[1]-1 == -10)	
					continue;
				if(!gridInfo[actGroup[i].pos[0]+halfHori][actGroup[i].pos[1]+halfVert-1].flag)	// if next grid is false (vacancy)
					actGroup[i].pos[1] -=1;
			}
		}while(G_Coll('B'));	// if all obj drop, func return false.
	else						// if Group State is vert. mode (state=false)
		while(G_Coll('b'))
			for(ui i=0; i<numGroup; i++)
				actGroup[i].pos[1] -= 1;
			
	
	

	for(ui i=0; i<numGroup; i++){
		gridInfo[actGroup[i].pos[0]+halfHori][actGroup[i].pos[1]+halfVert].flag = true;		// set grid to final pos
		for(ui j=0; j<3; j++)
			gridInfo[actGroup[i].pos[0]+halfHori][actGroup[i].pos[1]+halfVert].col[j]=actGroup[i].col[j];	// set grid to color
		gridInfo[actGroup[i].pos[0]+halfHori][actGroup[i].pos[1]+halfVert].colInfo=actGroup[i].colInfo;	// set grid to color infomation
	}
	

}

void G_Scene::G_SetColor(void){


	ui colorTemp=0;
	static bool count=true;
	int preHori=7;
	int preVer=7;

	srand((ui)time(NULL));

	if(count){

		G_GetColorValue('A');
		//G_GetColorValue('G');
		//count=false;
	}
	/*}else{
		for(ui i=0; i<numGroup; i++){
			actGroup[i].colInfo=gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo;
			for(ui j=0; j<3; j++)
				actGroup[i].col[j]=gridInfo[preHori+halfHori][preVer+halfVert-i].col[j];
		}
	}*/
	/*
	for(ui i=0; i<numGroup; i++){
		gridInfo[preHori+halfHori][preVer+halfVert-i].flag=true;		// draw nextSphere
		gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo=actGroup[i].colInfo;
		for(ui j=0; j<3; j++)
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[j]=actGroup[i].col[j];	// change color

	}
	for(ui i=3; i<preVer+halfVert; i++)
		gridInfo[preHori+halfHori][preVer+halfVert-i].flag=false;						// erase under sphere
		*/
	/*
	for(ui i=0; i<numGroup; i++){
		colorTemp=rand()%7+1;

		if(colorTemp==1){
			actGroup[i].col[0] = 1;
			actGroup[i].col[1] = 1;
			actGroup[i].col[2] = 1;
			actGroup[i].colInfo= 1;
		}else if(colorTemp==2){
			actGroup[i].col[0] = 0;
			actGroup[i].col[1] = 1;
			actGroup[i].col[2] = 0;
			actGroup[i].colInfo= 2;
		}else if(colorTemp==3){
			actGroup[i].col[0] = 0;
			actGroup[i].col[1] = 0;
			actGroup[i].col[2] = 1;
			actGroup[i].colInfo= 3;
		}else if(colorTemp==4){
			actGroup[i].col[0] = 1;
			actGroup[i].col[1] = 1;
			actGroup[i].col[2] = 0;
			actGroup[i].colInfo= 4;
		}else if(colorTemp==5){
			actGroup[i].col[0] = 0;
			actGroup[i].col[1] = 1;
			actGroup[i].col[2] = 1;
			actGroup[i].colInfo= 5;
		}else if(colorTemp==6){
			actGroup[i].col[0] = 1;
			actGroup[i].col[1] = 0;
			actGroup[i].col[2] = 1;
			actGroup[i].colInfo= 6;
		}else if(colorTemp==7){
			actGroup[i].col[0] = 1;
			actGroup[i].col[1] = 0.5;
			actGroup[i].col[2] = 0;
			actGroup[i].colInfo= 7;
		}
	}
	count++;
	}else{
		for(ui i=0; i<numGroup; i++){
			actGroup[i].colInfo=gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo;
			for(ui j=0; j<3; j++)
				actGroup[i].col[j]=gridInfo[preHori+halfHori][preVer+halfVert-i].col[j];
		}

		for(ui i=0; i<numGroup; i++){
			gridInfo[preHori+halfHori][preVer+halfVert-i].flag = true;

		colorTemp=rand()%7+1;

			if(colorTemp==1){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 1;
		}else if(colorTemp==2){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 2;
		}else if(colorTemp==3){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 3;
		}else if(colorTemp==4){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 4;
		}else if(colorTemp==5){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 5;
		}else if(colorTemp==6){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 6;
		}else if(colorTemp==7){
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 0.5;
			gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 0;
			gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 7;
		}
	}
			for(ui i=3; i<preVer+halfVert; i++)
				gridInfo[preHori+halfHori][preVer+halfVert-i].flag=false;						// erase under sphere


	}
	*/
}

void G_Scene::G_GetColorValue(char a){

	int preHori=7;
	int preVer=7;
	ui n;
	
	

	if(a=='A'){
		

		for(ui i=0; i<numGroup; i++){
			n=rand()%4+1;
			switch (n){
				case 1:
					actGroup[i].col[0] = 1;
					actGroup[i].col[1] = 1;
					actGroup[i].col[2] = 1;
					actGroup[i].colInfo= 1;
					break;
				case 2:
					actGroup[i].col[0] = 0;
					actGroup[i].col[1] = 1;
					actGroup[i].col[2] = 0;
					actGroup[i].colInfo= 2;
					break;
				case 3:
					actGroup[i].col[0] = 1;
					actGroup[i].col[1] = 0;
					actGroup[i].col[2] = 1;
					actGroup[i].colInfo= 3;
					break;
				case 4:
					actGroup[i].col[0] = 1;
					actGroup[i].col[1] = 1;
					actGroup[i].col[2] = 0;
					actGroup[i].colInfo= 4;
					break;
				case 5:
					actGroup[i].col[0] = 0;
					actGroup[i].col[1] = 1;
					actGroup[i].col[2] = 1;
					actGroup[i].colInfo= 5;
					break;
				case 6:
					actGroup[i].col[0] = 1;
					actGroup[i].col[1] = 0;
					actGroup[i].col[2] = 1;
					actGroup[i].colInfo= 6;
					break;
				case 7:
					actGroup[i].col[0] = 1;
					actGroup[i].col[1] = 0.5;
					actGroup[i].col[2] = 0;
					actGroup[i].colInfo= 7;
					break;
				}
		}
		
	}else if(a=='G'){
		for(ui i=0; i<numGroup; i++){
			n=rand()%4+1;
			gridInfo[preHori+halfHori][preVer+halfVert-i].flag=true;
			switch (n){
			case 1:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 1;
				break;
			case 2:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 2;
				break;
			case 3:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 3;
				break;
			case 4:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 4;
				break;
			case 5:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 5;
				break;
			case 6:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 6;
				break;
			case 7:
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[0] = 1;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[1] = 0.5;
				gridInfo[preHori+halfHori][preVer+halfVert-i].col[2] = 0;
				gridInfo[preHori+halfHori][preVer+halfVert-i].colInfo= 7;
				break;
			}
		}

		for(ui i=3; i<preVer+halfVert; i++)
			gridInfo[preHori+halfHori][preVer+halfVert-i].flag=false;						// erase under sphere


	}






}

void G_Scene::G_CheckSameColor(ui i, ui j, ui *num, ui check){

	ui colCheck;

	if(gridInfo[i][j].flag){

		(*num)++;

		if(!check)	gridInfo[i][j].elimFlag=true;

		gridInfo[i][j].checkFlag=true;
		
		colCheck=gridInfo[i][j].colInfo;

		if((!gridInfo[i+1][j].checkFlag) && (colCheck==gridInfo[i+1][j].colInfo) && (i<numHorisphe))	G_CheckSameColor(i+1,j,num,check);
		if((!gridInfo[i-1][j].checkFlag) && (colCheck==gridInfo[i-1][j].colInfo) && (i>0))				G_CheckSameColor(i-1,j,num,check);
		if((!gridInfo[i][j+1].checkFlag) && (colCheck==gridInfo[i][j+1].colInfo) && (j<numVertsphe))	G_CheckSameColor(i,j+1,num,check);
		if((!gridInfo[i][j-1].checkFlag) && (colCheck==gridInfo[i][j-1].colInfo) && (j>0))				G_CheckSameColor(i,j-1,num,check);

		gridInfo[i][j].checkFlag=false;
		
	}
	
}

void G_Scene::G_Grid_Init(ui i, ui j){

	gridInfo[i][j].flag=false;			// vacancy of grid
	gridInfo[i][j].checkFlag=false;		
	gridInfo[i][j].elimFlag=false;
	gridInfo[i][j].colInfo=0;
	for(ui k=0; k<3; k++)
		gridInfo[i][j].col[k]=0;

}

bool G_Scene::G_CheckElimination(void){

	ui num=0;
	bool flag=false;

	
	for(ui i=0; i<numHorisphe; i++){
		for(ui j=0; j<numVertsphe; j++){
			G_CheckSameColor(i,j,&num,1);	// 1-> CHECK, 0-> FLAG ELIMINATE
			if(num>3){
				G_CheckSameColor(i,j,&num,0);
				flag=true;

			}
			num=0;
		}
	}
	for(ui i=0; i<numHorisphe; i++)
		for(ui j=0; j<numVertsphe; j++)
			if(gridInfo[i][j].elimFlag){
				G_Grid_Init(i,j);			// Initialize (ELIMINATE)
				G_Score();
				chain++;
			}

	return flag;

}

void G_Scene::G_SetBottom(void){

	for(ui j=0; j<numVertsphe; j++)			// begin search
		for(ui i=0; i<numHorisphe; i++)
			if(!gridInfo[i][j].flag)						// if grid is false (Vacancy)	1
				for(ui k=j+1, ui, jj=j; k<numVertsphe; k++)	// search up
					if(gridInfo[i][k].flag){				// if grid is true (Occupied)	2
						dum=gridInfo[i][jj+1];				// replace 1's top with 2
						gridInfo[i][jj+1]=gridInfo[i][k];
						gridInfo[i][k]=dum;
						jj++;								// to replace next 1's top
					}

			
		
}

void G_Scene::G_End(void){

	for(ui i=0; i<numHorisphe; i++)
		for(ui j=0; j<numVertsphe; j++)
			for(ui k=0; k<3; k++)
				gridInfo[i][j].col[k]=1;
	
	endFlag=true;
	printf("\n☆	FINAL SCORE:%d	☆",score);
	printf("\n☆	MAXIMUM CHAIN:%d	☆\n\n",maxChain/4);

	if(score<10000){

	
printf("　　　　　　　　　　　／￣￣￣＼\n");
printf("　　　　　　　　　　/ 　⌒　　⌒ ヽ\n");
printf("　　　　　　　　　/　　（ ●）（●|\n");
printf("　　　　　　　　 |　　　（__人__　}　　　うーっす\n");
printf("　　　　　　　　/､.　　　｀ ⌒´ ヽ\n");
printf("　　　　　　　/　　　　　　　　　　|\n");
printf("　　　　　　　|　　　　　　　　　 |/\n");
printf("　　　　　　　ヽ_|　　┌──┐　|丿\n");
printf("　　　　　　　　 |　　├──┤　|\n");
printf("　　　　　　　　 |　　├──┤　|\n");

	}else{

printf("　　　　　　　　　＿＿＿＿＿＿＿＿\n");
printf("　　　　　　　／　　　　　　　　　　　 　＼\n");
printf("　　　　　 ／　　　　　　　　　　　　 　　　＼\n");
printf("　　　　／　　　／・＼　　　　　／・＼　　　＼\n");
printf("　　 ／　　　／　　　 ＼　　 ／　　　 ＼　　　＼\n");
printf("　　|　　　　　￣￣￣￣　　　￣￣￣￣　　　　 |　\n");
printf("　　|　　　　　　　　 （＿＿人＿＿）　　　　　 　 |\n");
printf("　　|　　　　　 　 　　　 ＼　　　　|　　 　 　　　　|\n");
printf("　　 ＼　　　　　　　　　　＼　　　|　　　　　　 ／\n");
printf("　　　　＼　　　　　　　　　　＼＿|　　　　　／\n");


	}
}
void G_Scene::G_Score(void){
	
	
	scoreBonus+=1;
	score+=scoreBonus*scoreBonus;
	
				
}
