
# include "Dir.h"

# include <iostream>


//#include<vector>
////using std::vector;
using namespace std;

int main()
{
	cout << "hi there soifnhiosh" << endl;

	Dir root = Dir("");
	Dir *cur_dir = &root;

	cout << root.m_owning_user << endl;
	cout << cur_dir->m_owning_user << endl;
	cout << cur_dir->m_name << endl;
	cur_dir->mkdir("jeff");
	cur_dir->mkdir("bob");

	cout << cur_dir->m_child_dir_vec.size() << endl;
	cur_dir->ls();

}
