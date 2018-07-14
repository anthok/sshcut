#include "sshcut.hpp"

int sshcut::removeSSH(std::string ssh_shorthand){
  std::cout << "removing " << ssh_shorthand << std::endl;

  return 1;
}

int sshcut::addSSH(std::string ssh_shorthand, std::string ssh_conn){
  std::cout << "adding " << ssh_shorthand << " with " << ssh_conn << std::endl;
  if (utils::doesNameExist(ssh_shorthand)) return 0;

  return 1;
}

int sshcut::updateSSH(std::string ssh_shorthand, std::string ssh_conn){
  std::cout << "updating " << ssh_shorthand << " with " << ssh_conn << std::endl;

  return 1;
}

int sshcut::connectSSH(std::string ssh_shorthand){
  std::cout << "Attempting to connect to " << ssh_shorthand << std::endl;
  return 1;
}

void sshcut::showList(void){
  std::ifstream ifile(utils::getFullConfigPath());
  if (ifile) {
    std::string str;
    while (std::getline(ifile, str)) {
      // output the line
      std::vector<std::string> str_vect;
      strtk::parse(str,",",str_vect);
      if (str_vect.size() != 2){
        std::cout << "Parsing error on sshcut config, check your commas" << std::endl;
        return;
      }
      std::cout << str_vect[0] << " -> " << str_vect[1] << std::endl;
    }
  }
  else{
    std::cout << "No sshcut config" << std::endl;
    return;
   }
}