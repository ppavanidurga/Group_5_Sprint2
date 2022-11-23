#include <iostream>
#include<ctime>
//#include<stdlib>

#define reset(msg) \
        _log(stdout, __FILE__, __LINE__, msg,1)
#define error(msg) \
        _log(stderr, __FILE__, __LINE__, msg,2)
#define warning(msg) \
        _log(stderr, __FILE__, __LINE__, msg,3)
#define  notice(msg) \
        _log(stderr, __FILE__, __LINE__, msg,4)
#define info(msg) \
        _log(stdout, __FILE__, __LINE__, msg,5)


void _log(FILE* fd, char* file, int line, char* msg,int log_level);
        
