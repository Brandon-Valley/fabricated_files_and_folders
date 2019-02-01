
# include <iostream>

//#include "Dir.h"
#include "utils.h"

#include<string>
#include<vector>





class File
{

public:
	string m_owning_user = "owning_user";
	int m_size = 777;

	string m_last_date_modified;
	string m_name;


	// default constructor
	File(const string name)
	{
		m_name = name;
		m_last_date_modified = currentDateTime();
	}


	void update_last_date_modified()
	{
		m_last_date_modified = currentDateTime();
	}
};








