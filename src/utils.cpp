#include "utils.hpp"

int utils::removeSSH(std::string ssh_shorthand){
  std::cout << "removing " << ssh_shorthand << std::endl;

  return 1;
}

int utils::addSSH(std::string ssh_shorthand, std::string ssh_conn){
  std::cout << "adding " << ssh_shorthand << " with " << ssh_conn << std::endl;
  return 1;
}

int utils::updateSSH(std::string ssh_shorthand, std::string ssh_conn){
  std::cout << "updating " << ssh_shorthand << " with " << ssh_conn << std::endl;
  return 1;
}

int utils::connectSSH(std::string ssh_shorthand){
  std::cout << "Attempting to connect to " << ssh_shorthand << std::endl;
  return 1;
}

void utils::showList(void){
  std::ifstream ifile(config_path);
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
    std::cout << "No sshcut saved entries" << std::endl;
    return;
   }
}


void utils::printUsage(void){
  std::cout << "sshcut " << SSHCUT_VERSION << std::endl << std::endl;
  std::cout << "Usage:" << std::endl;
  std::cout << "  sshcut <command> [arguments]" << std::endl << std::endl;

  std::cout << "Commands: " << std::endl;

  std::cout << "  sshcut devbox1 " << std::endl;
  std::cout << "  sshcut add devbox2 root@192.168.1.2" << std::endl;
  std::cout << "  sshcut update devbox2 root@192.168.1.3" << std::endl;
  std::cout << "  sshcut remove devbox2 " << std::endl;
  std::cout << "  sshcut list " << std::endl;
  std::cout << "  sshcut help " << std::endl;
}
