#ifndef FILE_H
#define FILE_H


# include <iostream>

//#include "Dir.h"
#include "File_Sys_Obj.h"
#include "utils.h"

#include<string>
#include<vector>





class File : public File_Sys_Obj
{

public:
//	string m_owning_user = "owning_user";
//	int m_size = 777;
//
//	string m_last_date_modified;
//	string m_name;


	// default constructor
	File(const string name)
	{
		m_name = name;
		m_last_date_modified = currentDateTime();
		m_file_sys_obj_type = "file";
	}





};






#endif

