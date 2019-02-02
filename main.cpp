
# include "Dir.h"
//#include

# include <iostream>


//#include<vector>
////using std::vector;
using namespace std;

int main()
{
	cout << "hi there soifnhiosh" << endl;

	//root is the top level directory
	Dir root = Dir(ROOT_M_NAME);
	Dir *cur_dir = &root;

	cout << root.m_owning_user << endl;
	cout << cur_dir->m_owning_user << endl;
	cout << cur_dir->m_name << endl;
	cur_dir->mkdir("jeff");
	cur_dir->mkdir("bob");

	cout << cur_dir->m_child_p_vec.size() << endl;
	cur_dir->ls();

	cur_dir = cur_dir->cd("jeff");
	cur_dir->mkdir("joe");
	cur_dir->ls();

	cout << "here" << endl;
	cur_dir->pwd();

	cout << cur_dir->m_parent_dir_p->m_name << endl;

	cur_dir = cur_dir->cd("..");
	cur_dir->ls();
	cur_dir->pwd();

	cout << "here 2" << endl;
//	cur_dir->rmdir("jeff");
	cur_dir->ls();
	cur_dir->ls_l();

	cur_dir->touch("victor.txt");
	cur_dir->ls();
	cur_dir->ls_l();

}
