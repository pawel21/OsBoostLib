#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <string>
using namespace boost::filesystem;

class OperatingSystem
{
public:
  void cwd();
};

void OperatingSystem ::cwd()
{
  path cwd = current_path();
  std::cout<<"cwd = " << cwd.generic_string() << std::endl;
}

int main()
{
  OperatingSystem os = OperatingSystem ();
  os.cwd();
  return 0;
}
