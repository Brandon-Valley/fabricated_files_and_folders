#ifndef DIR_H
#define DIR_H

# include <iostream>

#include "File.h"
#include "utils.h"

#include<string>
#include<vector>

using namespace std;


const string ROOT_M_NAME = "root";



// can the owning user and size always be the same???????????????????????????????????????????????????????????????????????????????????????????????????
// no way to make vector of pointers to both dir and file objects right??????????????????????????????????????????????????????????????????????????????????
// should ls go to new line?????????????????????????????????????????????????????????????????????????????????????????????????
//ok if ls lists all dirs THEN all files???????????????????????????????????????????????????????????????????????????????
//are my comments good enought??????????????????????????????????????????????????????????????????????????????????????????????????
// do I need to block invalid file/dir names like 999.txt ??????????????????????????????????????????????????????????????
// what is 1pbg in power poiint showing ls -l // do i need it / can I just make it up ???????????????????????????????
// does ls -l need to line up the back of the #s for size like in pp??????????????????????????????????
// will access/permission stuff acually need to be useful in the future? like should I make a nice object or just do some crappy string stuff???????????????
// is the way I did time for ls -l ok??????????????????????????????????????????????????????????????????????????????????????

//remember to test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//remember to tset that you can cd into a dir when there is a file of the same name right next to it
//that you cant cd .. in root
// that you cant do mkdir or make file with name ""

class Dir
{

public:
	string m_owning_user = "owning_user";
	int m_size = 888;

	string m_last_date_modified;
	string m_name;
	Dir * m_parent_dir_p;
	vector<Dir*> m_dir_child_p_vec;
	vector<File*> m_file_child_p_vec;

	// default constructor
	Dir(const string name)
	{
		m_name = name;
		m_last_date_modified = currentDateTime();
	}


	//deconstructor
	~Dir()
	{
		for ( int i = 0; i < m_dir_child_p_vec.size(); i++)
		{
		    delete m_dir_child_p_vec[i];
		}
	}


	//makes new dir inside current dir and adds a pointer to it to m_dir_child_p_vec
	void mkdir(const string new_dir_name)
	{
		Dir *new_dir = new Dir(new_dir_name);
		new_dir->m_parent_dir_p = this;
		m_dir_child_p_vec.push_back(new_dir);
	}

// ???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
//	void rmdir(const string dir_name)
//	{
//		for (auto it = m_dir_child_p_vec.begin(); it != m_dir_child_p_vec.end(); ++it )//( auto &i : m_dir_child_p_vec )//( auto i = m_dir_child_p_vec.begin(); i != m_dir_child_p_vec.end(); i++ )//for(vector<*Dir>::iterator it = m_dir_child_p_vec.begin(); it != m_dir_child_p_vec.end(); ++it)  //for (int i = 0 ; i < m_dir_child_p_vec.size() ; i++)
//		{
//			if (*it. == dir_name)
//			{
//				cout << "deleteing in rmdir" << endl;//```````````````````````````````````````````````````````````````````
////				delete i;
//				it = m_dir_child_p_vec.erase(it);
//				return;
//			}
//		}
//
//		throw "rmdir: failed to remove " + dir_name + ":  No such directory";
//
//	}


	//lists all dirs and files in current dir
	void ls()
	{
		for(int i = 0 ; i < m_dir_child_p_vec.size() ; i++)
		{
			cout << m_dir_child_p_vec[i]->m_name << "   ";
		}

		for(int i = 0 ; i < m_file_child_p_vec.size() ; i++)
		{
			cout << m_file_child_p_vec[i]->m_name << "   ";
		}
		cout << endl;
	}

	void ls_l()
	{
		for(int i = 0 ; i < m_dir_child_p_vec.size() ; i++)
		{
			cout << m_dir_child_p_vec[i]->m_owning_user << "   " << m_dir_child_p_vec[i]->m_size << "   " << m_dir_child_p_vec[i]->m_last_date_modified << "   " << m_dir_child_p_vec[i]->m_name << "/" << endl;
		}
		cout << endl;
	}


	//returns pointer to named dir or to m_parent_dict_p if cd ..
	Dir * cd(const string dir_name)
	{
		if (dir_name == "..")
			return m_parent_dir_p;

		for (int i = 0 ; i < m_dir_child_p_vec.size() ; i++)
		{
			if (m_dir_child_p_vec[i]->m_name == dir_name)
				return m_dir_child_p_vec[i];
		}
	}


	void pwd()
	{
//		cout << "in pwd" << endl; //```````````````````````````````````````````````````````````````````````````````````````````
		string final_str = "";
		vector<string> parent_dir_names;
		Dir * current_dir_p = this;

		//fill parent_dir_names
		parent_dir_names.push_back(current_dir_p->m_name);

		while (current_dir_p->m_name != ROOT_M_NAME)
		{
			current_dir_p = current_dir_p->m_parent_dir_p;
			parent_dir_names.push_back(current_dir_p->m_name);
//			cout << current_dir_p->m_name << endl; //```````````````````````````````````````````````````````````````````````````````````````
		}

//		cout << parent_dir_names.size() << endl;//```````````````````````````````````````````````````````````````````

		//make final_str from parent_dir_names
		for (int i = 0 ; i < parent_dir_names.size() ; i++)
			final_str = parent_dir_names[i] + '/' + final_str;

		cout << final_str << endl;
	}


	// if file already exists, update m_last_date_modified, if not, make new file
	void touch(const string file_name)
	{
		for (int i = 0 ; i < m_file_child_p_vec.size() ; i++)
		{
			if (m_file_child_p_vec[i]->m_name == file_name)
			{
				m_file_child_p_vec[i]->update_last_date_modified();
				return;
			}
		}
		File *new_file = new File(file_name);
		m_file_child_p_vec.push_back(new_file);
	}



};
















#endif
