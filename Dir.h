#ifndef DIR_H
#define DIR_H

# include <iostream>

#include "File.h"
#include "utils.h"

#include<string>
#include<vector>

using namespace std;


const string ROOT_M_NAME = "root";



//are my comments good enought??????????????????????????????????????????????????????????????????????????????????????????????????
// what is 1pbg in power poiint showing ls -l // do i need it / can I just make it up ???????????????????????????????
// is the way I did time for ls -l ok??????????????????????????????????????????????????????????????????????????????????????

//can I make a member func in file and use it in dir without static casting?    -- ----- test this -------------????



//remember to test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//remember to tset that you can cd into a dir when there is a file of the same name right next to it
//that you cant cd .. in root
// that you cant do mkdir or make file with name ""
// that touch updates last date modified when used on existing file
//that you cant do chmod 999 or 1111


class Dir : public File_Sys_Obj
{

public:
	Dir * m_parent_dir_p;
	vector<File_Sys_Obj*> m_child_p_vec;


	// default constructor
	Dir(const string name)
	{
		m_name = name;
		m_last_date_modified = currentDateTime();
		m_file_sys_obj_type = "dir";
	}


	//deconstructor
	~Dir()
	{
		for (int i = 0; i < m_child_p_vec.size(); i++)
		{
			if (m_child_p_vec[i]->is_dir())
			{
				Dir * curr_dir = static_cast<Dir*>(m_child_p_vec[i]);
				curr_dir->~Dir();
			}
		    delete m_child_p_vec[i];
		}
	}


	//makes new dir inside current dir and adds a pointer to it to m_dir_child_p_vec
	void mkdir(const string new_dir_name)
	{
		Dir *new_dir = new Dir(new_dir_name);
		new_dir->m_parent_dir_p = this;
		m_child_p_vec.push_back(new_dir);
	}

// ???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
	void rmdir(const string dir_name)
	{
		cout << "begin:  " << (*m_child_p_vec.begin())->m_name << endl;//``````````````````````````````````````````````````````````````
		Dir * dir_2_delete = static_cast<Dir*>(*m_child_p_vec.begin());
//		m_child_p_vec.erase(m_child_p_vec.begin());
		dir_2_delete->~Dir();
		cout << "after ~dir() begin:  " << (*m_child_p_vec.begin())->m_name << endl;//``````````````````````````````````````````````````````````````

		m_child_p_vec.erase(m_child_p_vec.begin());

		cout << "after erase begin:  " << (*m_child_p_vec.begin())->m_name << endl;//``````````````````````````````````````````````````````````````



////		iterator<vector> it = m_child_p_vec.begin();
//		cout << "it" << it->m_name << endl;
//		for (int i = 0 ; i < m_child_p_vec.size() ; i++)
//		{
//
//		}

//		for (auto it = m_child_p_vec.begin(); it != m_child_p_vec.end(); ++it )//( auto &i : m_dir_child_p_vec )//( auto i = m_dir_child_p_vec.begin(); i != m_dir_child_p_vec.end(); i++ )//for(vector<*Dir>::iterator it = m_dir_child_p_vec.begin(); it != m_dir_child_p_vec.end(); ++it)  //for (int i = 0 ; i < m_dir_child_p_vec.size() ; i++)
//		{
//			if (*it->m_name == dir_name)
//			{
//				cout << "deleteing in rmdir" << endl;//```````````````````````````````````````````````````````````````````
////				delete i;
//				it = m_child_p_vec.erase(it);
//				return;
//			}
//		}
//
//		throw "rmdir: failed to remove " + dir_name + ":  No such directory";

	}

	//make this make rows !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//lists all dirs and files in current dir
	void ls()
	{
		for(int i = 0 ; i < m_child_p_vec.size() ; i++)
		{
			cout << m_child_p_vec[i]->m_name << "   ";
		}

		cout << endl;
	}

	//list all files and dir's in directory with all info
	void ls_l()
	{
		for(int i = 0 ; i < m_child_p_vec.size() ; i++)
		{
			cout << m_child_p_vec[i]->m_owning_user << "\t" << m_child_p_vec[i]->m_size << "\t" << m_child_p_vec[i]->m_last_date_modified << "\t" << m_child_p_vec[i]->m_name;

			if (m_child_p_vec[i]->is_dir() == true)
				cout << "/";
			cout << endl;
		}

	}


	//returns pointer to named dir or to m_parent_dict_p if cd ..
	Dir * cd(const string dir_name)
	{
		if (dir_name == "..")
			return m_parent_dir_p;

		for (int i = 0 ; i < m_child_p_vec.size() ; i++)
		{
			if (m_child_p_vec[i]->m_name == dir_name and m_child_p_vec[i]->is_dir())
				return static_cast<Dir*>(m_child_p_vec[i]);
		}
	}


	void pwd()
	{
		string final_str = "";
		vector<string> parent_dir_names;
		Dir * current_dir_p = this;

		//fill parent_dir_names
		parent_dir_names.push_back(current_dir_p->m_name);

		while (current_dir_p->m_name != ROOT_M_NAME)
		{
			current_dir_p = current_dir_p->m_parent_dir_p;
			parent_dir_names.push_back(current_dir_p->m_name);
		}

		//make final_str from parent_dir_names
		for (int i = 0 ; i < parent_dir_names.size() ; i++)
			final_str = parent_dir_names[i] + '/' + final_str;

		cout << final_str << endl;
	}


	// if file already exists, update m_last_date_modified, if not, make new file
	void touch(const string name)
	{
		for (int i = 0 ; i < m_child_p_vec.size() ; i++)
		{
			if (m_child_p_vec[i]->m_name == name)
			{
				m_child_p_vec[i]->update_last_date_modified();
				return;
			}
		}
		File *new_file = new File(name);
		m_child_p_vec.push_back(new_file);
	}


	//preforms chmod on the file or dir given which exists inside cur_dir, not on cur_dir itself
	void chmod(const string name, const int perm_num)
	{

	}



};
















#endif
