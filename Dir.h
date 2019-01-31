#ifndef DIR_H
#define DIR_H

# include <iostream>

#include<string>
#include<vector>

using namespace std;

// can the owning user and size always be the same???????????????????????????????????????????????????????????????????????????????????????????????????
// no way to make vector of pointers to both dir and file objects right??????????????????????????????????????????????????????????????????????????????????
// should ls go to new line?????????????????????????????????????????????????????????????????????????????????????????????????
//ok if ls lists all dirs THEN all files???????????????????????????????????????????????????????????????????????????????
//are my comments good enought??????????????????????????????????????????????????????????????????????????????????????????????????

//remember to test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//remember to tset that you can cd into a dir when there is a file of the same name right next to it
//that you cant cd .. in root
class Dir
{

public:
	string m_owning_user = "owning_user";
	int m_size = 888;

	string m_last_date_modified;
	string m_name;
	Dir * m_parent_dir_p;
	vector<Dir*> m_child_dir_p_vec;

	// default constructor
	Dir(const string name)
	{
		m_name = name;
	}

	//makes new dir inside current dir and adds a pointer to it to m_child_dir_p_vec
	void mkdir(const string new_dir_name)
	{
		Dir *new_dir = new Dir(new_dir_name);
		new_dir->m_parent_dir_p = this;
		cout << "in mkdir, new dir parent name:  " << new_dir->m_parent_dir_p->m_name << endl; //``````````````````````````````````````````````
		m_child_dir_p_vec.push_back(new_dir);

//		cout << new_dir->m_name << endl; //`````````````````````````````````````````````````````````````````````````````````````````
	}

	//lists all dirs and files in current dir
	void ls()
	{
//		cout << "in ls" << m_child_dir_p_vec.size() << endl; //````````````````````````````````````````````````````````````````````````````````````
		for(int i = 0 ; i < m_child_dir_p_vec.size() ; i++)
		{
			cout << m_child_dir_p_vec[i]->m_name << "   ";
		}

		cout << endl;
	}

	//returns pointer to named dir or to m_parent_dict_p if cd ..
	Dir * cd(const string dir_name)
	{
		if (dir_name == "..")
			return m_parent_dir_p;

		for (int i = 0 ; i < m_child_dir_p_vec.size() ; i++)
		{
			if (m_child_dir_p_vec[i]->m_name == dir_name)
				return m_child_dir_p_vec[i];
		}
	}

};
















#endif
