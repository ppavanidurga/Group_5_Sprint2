#include <iostream>
#include<ctime>
#include "Logger.h"
//#include<stdlib>
#include<fstream>

using namespace std;

void _log(FILE* fd, char* file, int line, char* msg,int log_level)
{
       time_t t=time(0);
        if(log_level==2)
	{
		printf("\033[1;31m%s",msg);
	}
	else if(log_level==3)
        {
                printf("\033[1;33m%s",msg);
        }

	else if(log_level==4)
	{
		printf("\033[32;1m%s",msg);
	}
	 else if(log_level==5)
        {
                printf("\033[36m%s",msg);
        }

	else
	{ 
	    printf("\033[0m%s","");
	}
	//ofstream lg;
	//lg.open("log.txt","+a");
	FILE *lg;
        lg= fopen("log.txt","a+");
	std:string timestr= ctime(&t);
	timestr = timestr.substr(0,timestr.length()-1);
        fprintf(lg,"[%s][%s]:[%d] %s\n",const_cast<char*>(timestr.c_str()), file, line, msg);
	fclose(lg);
	printf("\033[0m%s","");
}
        
