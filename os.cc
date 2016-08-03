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
  void print_list_current_directory();
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

void OperatingSystem::print_list_current_directory()
{
  path cwd = current_path();

  for (auto i = directory_iterator(cwd); i != directory_iterator(); i++)
  {
      if (!is_directory(i->path())) //we eliminate directories
      {
          std::cout << i->path().filename().string() << std::endl;
      }
      else
          continue;
  }
}

int main()
{
  OperatingSystem os = OperatingSystem ();
  os.pcwd();
  std::cout<<os.getcwd()<<"\n";
  os.print_list_current_directory();
  return 0;
}
