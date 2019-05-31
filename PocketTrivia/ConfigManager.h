#pragma once
#include "Globals.h"


// FUNCTION DECLARATIONS
class ConfigManager{
public:
	/*
	   Loads Configurations from the config file
	   Parameters:
		  char *configFile - Config file name
	   Returns: void 
	*/
	void load_config(const char* configFile);


	/*
	   Save the configurations to the config file
	   Parameters:
		  char *configFile - Config file name
	   Returns: void 
	*/
	void save_config(const char* configFile);
};