 #include "ConfigManager.h"
#include "Globals.h"
#include "Quiz.h"   
#include "GameManager.h"

#include <allegro.h>

using namespace std;

//#include <fstream>
//#include "Question.h"
#define WHITE makecol(255,255,255) 

int main(void) {  
	GameManager gameManager; 

	gameManager.init();
	gameManager.runGameLoop();
	gameManager.exit(); 
	return 0;
}
END_OF_MAIN()