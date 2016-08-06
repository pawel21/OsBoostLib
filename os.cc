#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/date_time.hpp>
#include <vector>
#include <string>
#include <map>

using namespace boost::filesystem;
namespace greg = boost::gregorian;

class OperatingSystem
{
public:
  void pcwd();
  std::string getcwd();
  void print_list_current_directory();
  void listdir(path p);
  void map_ls();
  void current_time();
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

void OperatingSystem::listdir(path p)
{
  for (auto i = directory_iterator(p); i != directory_iterator(); i++)
  {
          std::cout << i->path().filename().string() << std::endl;
  }
}

void OperatingSystem::map_ls()
{
    std::map<std::string, std::vector<std::string> > ls;
    std::vector<std::string> directory;
    std::vector<std::string> files;

    path cwd = current_path();

    for(auto i = directory_iterator(cwd); i != directory_iterator(); i++)
    {
      if (is_directory(i->path()))
      {
        directory.push_back(i->path().filename().string());
      }
      else
          files.push_back(i->path().filename().string());
    }
    ls["directory: "] = directory;
    ls["files: "] = files;

    std::map<std::string, std::vector<std::string> >::iterator it;
    for(it=ls.begin(); it != ls.end(); ++it)
    {
      std::cout<< it->first << " => ";

      for (std::vector<std::string>::iterator eptr=it->second.begin(); eptr!=it->second.end(); eptr++)
        std::cout<< *eptr << " ";
      std::cout<<"\n";
    }
}

void OperatingSystem::current_time()
{
  greg::date today = greg::day_clock::local_day();
  std::cout<< today.day_of_week()<< " " << today.day() << " , " << today.month()
  << " , " << today.year() << "\n";
}
int main()
{
  OperatingSystem os = OperatingSystem ();
  os.pcwd();
  std::cout<<os.getcwd()<<"\n";
  os.print_list_current_directory();
  os.listdir("/home/pawel1/Pulpit/C++/boost");
  os.map_ls();
  os.current_time();
  return 0;
}
