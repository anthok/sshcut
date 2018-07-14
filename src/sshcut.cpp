#include "sshcut.hpp"

int sshcut::removeSSH(std::string ssh_shorthand){
  std::cout << "removing " << ssh_shorthand << std::endl;
  if (!utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " doesn't exist" << std::endl;
    return 0;
  }


  //remove line from file
  return 1;
}

int sshcut::addSSH(std::string ssh_shorthand, std::string ssh_conn){
  std::cout << "adding " << ssh_shorthand << " with " << ssh_conn << std::endl;
  if (utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " already exists" << std::endl;
    return 0;
  }

  if (!utils::isValidInput(ssh_shorthand,ssh_conn)){
    std::cout << "Invalid entry" << std::endl;
    return 0;
  } 



   std::ofstream out;
   out.open(utils::getFullConfigPath(), std::ios::app);

   std::string str = ssh_shorthand + "," + ssh_conn + "\n";
   out << str;

  return 1;
}

int sshcut::updateSSH(std::string ssh_shorthand, std::string ssh_conn){
  std::cout << "updating " << ssh_shorthand << " with " << ssh_conn << std::endl;
  if (!utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " doesn't exist" << std::endl;
    return 0;
  }
  if (!utils::isValidInput(ssh_shorthand,ssh_conn)){
    std::cout << "Invalid entry" << std::endl;
    return 0;
  } 

  //read old shortcut from file
  //removeSSH()
  //addSSH()


  return 1;
}

int sshcut::connectSSH(std::string ssh_shorthand){
  std::cout << "Attempting to connect to " << ssh_shorthand << std::endl;
  if (!utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " doesn't exist" << std::endl;
    return 0;
  }



  //actually do the ssh
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