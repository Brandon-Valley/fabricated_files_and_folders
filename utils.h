#ifndef UTILS_H
#define UTILS_H

# include <iostream>
#include <stdio.h>
#include <time.h>

#include<string>
#include<vector>

using namespace std;

const string FULL_PERM_STR = "rwxrwxrwx";


string single_digit_int_2_binary_str(const int a)
{
    string binary  ("");
	  int mask = 1;
	  for(int i = 0; i < 3; i++)
	  {
	  if((mask&a) >= 1)
		  binary = "1"+binary;
	  else
		  binary = "0"+binary;
	  mask<<=1;
	  }
	  return binary;
}


string perm_num_2_str(const string perm_num_str)
{

}



// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}



#endif
