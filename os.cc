#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>


using namespace boost::filesystem;
class OperatingSystem
{
public:
  void pcwd();
  std::string getcwd();
};

void OperatingSystem::pcwd()
{
  path cwd = current_path();
  std::cout<<"current working directory = " << cwd.generic_string() << std::endl;
}

std::string OperatingSystem::getcwd()
{	path cwd = current_path();
	return cwd.make_preferred().string();
}

int main()
{
  OperatingSystem os = OperatingSystem ();
  os.pcwd();
  std::cout<<os.getcwd()<<"\n";
  return 0;
}
