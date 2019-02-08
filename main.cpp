
# include "Dir.h"

# include <iostream>

using namespace std;


const string QUIT_PROGRAM_ERROR_MSG = "QUIT_PROGRAM";


Dir * parse(const string command, Dir * cur_dir)
{
	Dir * dp_cur_dir = static_cast<Dir*>(cur_dir);

	vector<string> cv = split(command);


	if      (cv.size() == 1 and   cv[0] == "quit")  { throw QUIT_PROGRAM_ERROR_MSG;} //command to stop loop
	else if (cv.size() == 1 and   cv[0] == "pwd")   { dp_cur_dir->pwd(); }
	else if (cv.size() == 1 and   cv[0] == "ls")   { dp_cur_dir->ls(); }


	else if (cv.size() == 2 and   cv[0] == "cd")    { return cur_dir->cd(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "mkdir")  { cur_dir->mkdir(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "rmdir")  { cur_dir->rmdir(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "touch")  { cur_dir->touch(cv[1]); }
	else if (cv.size() == 2 and   cv[0] == "rm")  { cur_dir->rm(cv[1]); }

	else if (cv.size() == 2 and   cv[0] == "ls" and cv[1] == "-l") { cur_dir->ls_l(); }


	else if (cv.size() == 3 and   cv[0] == "chmod")  { cur_dir->chmod(cv[2], cv[1]); }


	else { throw "No command '" + command + "' found"; }

	return cur_dir;
}




int main()
{
	//root is the top level directory
	Dir root = Dir(ROOT_M_NAME);
	Dir *cur_dir = &root;


	try
	{
		cur_dir = parse("mkdir a", cur_dir);
		cur_dir = parse("mkdir b", cur_dir);
		cur_dir = parse("touch c.t", cur_dir);
		cur_dir = parse("touch d.t", cur_dir);
		cur_dir = parse("cd a", cur_dir);
		cur_dir = parse("mkdir aa", cur_dir);
		cur_dir = parse("mkdir bb", cur_dir);
		cur_dir = parse("touch cc.t", cur_dir);
//		cur_dir = parse("rm cc.t", cur_dir);       //new
		cur_dir = parse("touch cc.tt", cur_dir);
		cur_dir = parse("rm cc.tt", cur_dir);
		cur_dir = parse("rmdir bb", cur_dir);
		cur_dir = parse("cd aa", cur_dir);
		cur_dir = parse("mkdir aaa", cur_dir);
		cur_dir = parse("mkdir bbb", cur_dir);
		cur_dir = parse("touch ccc.t", cur_dir);
		cur_dir = parse("touch ddd.t", cur_dir);
		cur_dir = parse("rm ddd.t", cur_dir);
		cur_dir = parse("rmdir bbb", cur_dir);
		cur_dir = parse("cd ..", cur_dir);
		cur_dir = parse("rmdir aa", cur_dir);
		cur_dir = parse("mkdir ff", cur_dir);
		cur_dir = parse("cd ff", cur_dir);
		cur_dir = parse("mkdir dddd", cur_dir);
		cur_dir = parse("dddd", cur_dir);
		cur_dir = parse("cd ..", cur_dir);
		cur_dir = parse("cd ..", cur_dir);
		cur_dir = parse("rm d.t", cur_dir);
		cur_dir = parse("rmdir b", cur_dir);
		cur_dir = parse("quit", cur_dir);
	}
	catch(...)
	{
		cout << "caught something" << endl;//``````````````````````````````````````````````````````````````````````
	}









//
//
//	while (true)
//	{
//		try
//		{
//			try
//			{
//				cout << cur_dir->pwd() << "  >> ";
//				string command;
//				getline(cin, command);
//				cout << " !!!DELETE THIS!!! command recieved:  " << command << endl;//`````````````````````````````````````````````````````````````````````````````
//				cur_dir = parse(command, cur_dir);
//			}
//			catch (string error_msg)
//			{
//				if (error_msg == QUIT_PROGRAM_ERROR_MSG)
//					break;
//				else
//					cout << error_msg << endl; }
//		}
//		catch (...)   { cout << "ERROR" << endl; }
//	}
//	delete cur_dir;
	cout << "done!!!!!!!!!!!!!!!" << endl;//````````````````````````````````````````````````````````````````
	exit(0);
	return 0;
}
