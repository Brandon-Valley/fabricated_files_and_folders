
# include "Dir.h"
//#include

# include <iostream>


//#include<vector>
////using std::vector;
using namespace std;



Dir * parse(const string command, Dir * cur_dir)
{
//		cout << "command:  " << command << endl;//````````````````````````````````````````````````````````````````````````````````````````

	Dir * dp_cur_dir = static_cast<Dir*>(cur_dir);

	vector<string> cv = split(command);


//		for (int i = 0 ; i < cv.size() ; i++)
//		{
//			cout << "cv[" << i << "]:  " << cv[i] << endl;//``````````````````````````````````````````````````````````````````````````````
//		}

//	if      (cv.size() == 1)
//	{
//		if (cv[0] == "quit")  { throw 0;} //command to stop loop
//	}
//	else if (cv.size() == 2)
//	{
//
//	}
//	else if (cv.size() == 3)
//	{
//
//	}




	if      (cv.size() == 1 and   cv[0] == "quit")  { throw 0;} //command to stop loop
	else if (cv.size() == 1 and   cv[0] == "pwd")   { dp_cur_dir->pwd(); }
	else if (cv.size() == 1 and   cv[0] == "ls")   { dp_cur_dir->ls(); }


	else if (cv.size() == 2 and   cv[0] == "cd")    { return cur_dir->cd(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "mkdir")  { cur_dir->mkdir(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "rmdir")  { cur_dir->rmdir(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "touch")  { cur_dir->touch(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "rm")  { cur_dir->rm(cv[1]); }

	else if (cv.size() == 2 and   cv[0] == "ls" and cv[1] == "-l") { cur_dir->ls_l(); }


	else if (cv.size() == 3 and   cv[0] == "chmod")  { cur_dir->chmod(cv[2], cv[1]); }




//	else if (cv[0] == "ls" and cv.size() == 1)                   { cur_dir->ls(); }
//	else if (cv[0] == "ls" and cv.size() == 2 and cv[1] == "-l") { cur_dir->ls_l(); }
//			{
//				if (cv.size() == 1)  { ls(); }
//				else if (cv.size() == 2 and cv[1] == "-l") { ls_l(); }
//			}
	else { throw "No command '" + command + "' found"; }






//	catch (string error_msg) { cout << error_msg << endl; }
//	catch (...)              { cout << "ERROR" << endl; }











//	if (cv.size() == 1)
//	{
//		if (cv[0] == "quit")
//			return false;
//	}
//	else if (cv.size() == 2)
//	{
//
//	}
//	else if (cv.size() == 3)


	return cur_dir;
}




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
	cur_dir->touch("ex_file.txt");
	cur_dir->ls();

	cout << "here" << endl;
	cur_dir->pwd();

	cout << cur_dir->m_parent_dir_p->m_name << endl;

	cur_dir = cur_dir->cd("..");
	cur_dir->ls();
//	cur_dir->pwd();

	cout << "here 2" << endl;
//	cur_dir->rmdir("jeff");
	cur_dir->ls();
	cur_dir->ls_l();

	cur_dir->touch("victor.txt");
	cur_dir->ls();
	cur_dir->ls_l();

	try
	{
		cur_dir->rmdir("bo");
	}
	catch (string error)
	{
	        cout << error << endl;
	}

//	cur_dir->rmdir("jeff");

	cur_dir->ls();
	cout << cur_dir->m_child_p_vec.size() << endl;

	cur_dir->rm("victor.txt");
	cur_dir->ls();

	cur_dir->chmod("bob", "703");
	cur_dir->ls_l();
//
//	cur_dir->mkdir("bill");
//	cur_dir->mkdir("dave");
//	cur_dir->mkdir("chuck");
//
//	cur_dir->ls_l();
//	cur_dir->ls();

//	bool loop = true;
	while (true)
	{
		try
		{
			try
			{
				cout << cur_dir->pwd() << "  >> " <<  endl;
				string command;
				getline(cin, command);
				cur_dir = parse(command, cur_dir);
			}
			catch (int i) {	break; }
			catch (string error_msg) { cout << error_msg << endl; }

		}
		catch (...)   { cout << "ERROR" << endl; }
//		cout << "loop:  " << loop << endl;//``````````````````````````````````````````````````````````````````````````````````````
	}


}
