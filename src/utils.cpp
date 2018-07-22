#include "utils.hpp"

bool utils::doesNameExist(std::string potentialName){
  std::ifstream ifile(utils::getFullConfigPath());
  if (ifile) {
    std::string str;
    while (std::getline(ifile, str)) {
      // output the line
      std::vector<std::string> str_vect;
      strtk::parse(str,",",str_vect);
      if (str_vect.size() != 2){
        std::cout << "Parsing error on sshcut config, check your commas" << std::endl;
        ifile.close();
        return true;
      }
      if (potentialName == str_vect[0]){
        ifile.close();
        return true;
      }
    }
    ifile.close();
    return false;
  }
  else{
    std::cout << "No sshcut config" << std::endl;
    ifile.close();
    return true;
   }
}



bool utils::isValidInput(std::string shortcut, std::string ssh_cmd){

  std::size_t found = shortcut.find(',');
  if (found != std::string::npos){
    std::cout << "Invalid shortcut name" << std::endl;
    return false;
  }

  found = ssh_cmd.find(',');
  if (found != std::string::npos){
    std::cout << "Invalid ssh command" << std::endl;
    return false;
  }

  return true;
} 

std::string utils::getFullConfigPath(){
  char* env_var;
  env_var = getenv("HOME");

  if(env_var == NULL){
    std::cout << "HOME environment variable not set, exiting" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string homedir(env_var);
  homedir += "/" + config_file_from_userhome;
  return homedir;
}

bool utils::doesConfigExist(){
  std::ifstream ifile(utils::getFullConfigPath());
  if (ifile) {
    ifile.close();
    return true;
  }
  else{
    ifile.close();
    return false;
  }
}

void utils::createEmptyConfig(){
  std::ofstream ofile(utils::getFullConfigPath());
  ofile.close();

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
