/***********************************************************************
*                                                                      *
* (C) 2016, Moritz Nöltner-Augustin                                    *
*                                                                      *
* This program is free software; you can redistribute it and/or modify *
* it under the terms of the GNU General Public License as published by *
* the Free Software Foundation; either version 3 of the License, or    *
* (at your option) any later version.                                  *
*                                                                      *
* This program is distributed in the hope that it will be useful,      *
* but WITHOUT ANY WARRANTY; without even the implied warranty of       *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
* GNU General Public License for more details.                         *
*                                                                      *
* You should have received a copy of the GNU General Public License    *
* along with this program; if not, write to the Free Software          *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 *
* USA                                                                  *
*                                                                      *
***********************************************************************/

// A little test program to see if the getopt_pp library works as expected
#include <iostream>
#include "getopt_pp.h"

int main(int argc, char* argv[])
{
	int a_number;
	std::string a_string;
	bool a_flag;

	GetOpt::GetOpt_pp ops(argc, argv);
	ops.exceptions(std::ios::failbit|std::ios::eofbit);
	try
	{
		ops>>GetOpt::Option('n', "number", a_number, 999);
		ops>>GetOpt::Option('s', "string", a_string, "foo");
		ops>>GetOpt::OptionPresent('f', "flag", a_flag);
	}
	catch(GetOpt::GetOptEx ex)
	{
		std::cerr<<"Error in arguments"<<std::endl;
		std::cerr<<"Usage: "<<argv[0]<<" [options]"<<std::endl;
		std::cerr<<"Options:"<<std::endl;
		std::cerr<<"-n|--number <NUM>"<<std::endl;
		std::cerr<<"-s|--string <STR>"<<std::endl;
		std::cerr<<"-f|--flag"<<std::endl;
		return -1;
	}

	std::cout<<"Number was set to "<<a_number<<" (999 is the default value).\n";
	std::cout<<"String was set to \""<<a_string<<"\" (\"foo\" is the default value).\n";
	std::cout<<"Flag was "<<(a_flag?"":"not ")<<"set."<<std::endl;

	return 0;
}

