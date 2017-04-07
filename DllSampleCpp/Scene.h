#pragma once

#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES
#include <cmath>

//include <boost/multi_array.hpp>

typedef unsigned int ui;
//typedef boost::multi_array<double, 3> MyArray;

class Scene
{
	GLfloat temp;
public:
	ui numNeuro;
	ui numInpDim;
	ui numLearn;
	ui countLine;
	double zeroCoordX;
	double zeroCoordY;
	double posX, posY;
	double dia;
	double rad;
	double ***refVec;
	double *inpVec;
	double accScene[5];////////////////////////////追加(1/4)////////
	//++++++++++++++++++++++++++++追加(1/19)+++++++++++++++++++++++
	double subAccArrDlg[5][40];
	//++++++++++++++++++++++++++++追加(1/19)+++++++++++++++++++++++
	double subCurAccArrDlg[5];
	//
	double max, min;
	bool curFlag;
	double curPosX, curPosY;

	

	//FILE *output;
	
	// Constructor
	Scene(){
		numNeuro=50;		// Number of Neurons
		numInpDim=5;		// Input Dimension /6軸に変更/
		numLearn=1000;		// Number of Learning
		zeroCoordX=-1.00;	// Zero Coordinate X
		zeroCoordY=-1.00;	// Zero Coordinate Y
		dia=2.0/(double)numNeuro;	// Diameter of Sphere
		rad=dia*0.5;				// Radius of Sphere
		curFlag=false;
		curPosX=-1;
		curPosY=-1;
		countLine=0;

		// Allocate
		refVec=new double**[numNeuro];
		for(ui i=0; i<numNeuro; i++) {
			refVec[i] = new double*[numNeuro];
			for(ui j=0; j<numNeuro; j++){
				refVec[i][j] = new double[numInpDim];
			}
		}
		inpVec=new double[numInpDim];
	}

	// Destructor
	~Scene(){

		// Release
		for(ui i=0; i<numNeuro; i++) {
			for(ui j=0; j<numNeuro; j++){
				delete[] refVec[i][j];
			}
			delete[] refVec[i];
		}
		delete [] inpVec;
		
	}

	void setTemp(float a) { temp = a; }
	void draw(void);
	void CurDraw(void);
	void init_reference(void);
	void Som2d(int numSample);
	void UseSOM(double current[]);
	int TasTest(void);
	int TasTest2(void);
};

// ファイル入出力のためのクラス
class FileControl
{
	public:
	FILE *output;


};

//+++++++++++++++++++++++++++++++++++++++++++

class G_Scene
{
	GLfloat temp2;
public:
	struct Obj{
		bool state;			// 0-> vert, 1->hori
		int pos[2];			// x, y
		double col[3];		// RGB
		ui colInfo;			// 0-> non
	};
	struct Gri{
		bool flag;			// True -> including
		double col[3];		// RGB
		ui colInfo;			// 0-> non
		bool checkFlag;
		bool elimFlag;
	};

	Gri dum;		// Dummy
	Obj *actGroup;	// Control Target

	Gri **gridInfo;
			
	bool startFlag;
	bool eraseFlag;
	bool endFlag;
	ui startCount;
	ui numCoord;
	ui numGroup;
	ui numVertsphe;
	ui numHorisphe;
	ui halfVert;
	ui halfHori;
	ui score;
	ui chain;
	ui maxChain;
	ui scoreBonus;
	int zeroCoordX1;
	int zeroCoordY1;
	double dia;
	double rad;
	double leftWall;
	double rightWall;

	
	// Constructor
	G_Scene(){
		startFlag=false;
		eraseFlag=false;
		endFlag=false;
		startCount=0;
		numCoord=2;
		numGroup=3;
		numVertsphe=20;
		numHorisphe=19;
		halfVert=(int)(numVertsphe*0.5);
		halfHori=(int)(numHorisphe*0.5);
		score=0;
		chain=0;
		maxChain=0;
		scoreBonus;
		zeroCoordX1=0;	// Zero Coordinate X
		zeroCoordY1=10;	// Zero Coordinate Y
		dia=20/(double)numVertsphe;	// Diameter of Sphere
		rad=dia*0.5;
		leftWall=-4;
		rightWall=4;

		// Allocate
		actGroup=new Obj[3];
		gridInfo=new Gri*[numHorisphe];
		for(ui i=0; i<numHorisphe; i++){
			gridInfo[i] = new Gri[numVertsphe];
		}

		// Initialize
		for(ui i=0; i<numGroup; i++){
			actGroup[i].state=false;		// state is vert
			actGroup[i].colInfo=0;
		}

		for(ui i=0; i<numHorisphe; i++){
			for(ui j=0; j<numVertsphe; j++){
				gridInfo[i][j].flag=false;		// vacancy of grid
				gridInfo[i][j].checkFlag=false;
				gridInfo[i][j].elimFlag=false;
				gridInfo[i][j].colInfo=0;
			}
		}

	}

	// Destructor
	~G_Scene(){
		// Release
		delete [] actGroup;
		for(ui i=0; i<numHorisphe; i++) {
			delete[] gridInfo[i];
		}
		delete [] gridInfo;
	}

	void setTemp2(float a) { temp2 = a; }
	void G_Draw(void);
	void G_Init(void);
	void G_NextStep(void);
	void G_Trans(char a);
	void G_Rot(void);
	bool G_Coll(char);
	void G_CheckNextVacancy(void);
	void G_Scene::G_SetColor(void);
	bool G_Scene::G_CheckElimination(void);
	void G_Scene::G_CheckSameColor(ui x, ui y, ui *num, ui check);
	void G_Scene::G_Grid_Init(ui i, ui j);
	void G_Scene::G_SetBottom(void);
	void G_Scene::G_End(void);
	void G_Scene::G_Score(void);
	void G_Scene::G_GetColorValue(char a);

};




