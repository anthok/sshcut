#include "sshcut.hpp"

/**
We will iterate over the config file line by line until we hit our shorthand
We can't look for substring because we need to make sure it hits in the first section
Then we remove the target line by replacing it with an empty string.
*/
int sshcut::removeSSH(std::string ssh_shorthand){
  // std::cout << "removing " << ssh_shorthand << std::endl;
  if (!utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " doesn't exist" << std::endl;
    return 1;
  }
  std::string line;
  std::ifstream infile(utils::getFullConfigPath());
  std::ofstream outfile(utils::getFullConfigPath() + ".tmp");

  std::vector<std::string> sshcut_parsed;
  while (std::getline(infile, line)){
    //clearing vector after every iteration
    sshcut_parsed.clear();

    if (line.empty()) continue;
    strtk::parse(line,",",sshcut_parsed);
    if (sshcut_parsed.size() != 2 && sshcut_parsed.size() != 3){
      std::cout << sshcut_parsed.size() << std::endl;
      std::cout << "Parsing error, removeSSH() in sshcut config, check your commas" << std::endl;
      return 1;
    }
    if (sshcut_parsed[0] != ssh_shorthand){
      outfile << line << std::endl;
    }
  }
  outfile.close();
  infile.close();

  //now that a new file has been created
  //we make a backuup of the orignal
  //then move the new in
  int result = 0;
  result = rename(utils::getFullConfigPath().c_str(), (utils::getFullConfigPath() + ".bak").c_str());
  if (result != 0) {
    std::cout << "Error making backup" << std::endl;
    return 1;
  }

  result = rename((utils::getFullConfigPath() + ".tmp").c_str(), utils::getFullConfigPath().c_str());
  if (result != 0){
    std::cout << "Error making sshcut config" << std::endl;
    return 1;
  }

  return 0;
}

int sshcut::addSSH(std::string ssh_shorthand, std::string ssh_conn, std::string trigger_action){
  // std::cout << "adding " << ssh_shorthand << " with " << ssh_conn << std::endl;
  if (utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " already exists" << std::endl;
    return 1;
  }

  if (!utils::isValidInput(ssh_shorthand,ssh_conn,trigger_action)){
    return 1;
  } 

  std::ofstream out;
  out.open(utils::getFullConfigPath(), std::ios::app);
  std::string str = "";
  if (trigger_action.length() == 0){
    str = ssh_shorthand + "," + ssh_conn + "\n";
  }
  else{
    str = ssh_shorthand + "," + ssh_conn + "," + trigger_action + "\n";
  }
  out << str;

  return 0;
}

int sshcut::updateSSH(std::string ssh_shorthand, std::string ssh_conn, std::string trigger_action){
  // std::cout << "updating " << ssh_shorthand << " with " << ssh_conn << std::endl;
  if (!utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " doesn't exist" << std::endl;
    return 1;
  }
  if (!utils::isValidInput(ssh_shorthand,ssh_conn,trigger_action)){
    std::cout << "Invalid entry" << std::endl;
    return 1;
  } 

  sshcut::removeSSH(ssh_shorthand);
  sshcut::addSSH(ssh_shorthand, ssh_conn, trigger_action);

  return 0;
}

int sshcut::connectSSH(std::string ssh_shorthand){
  if (!utils::doesNameExist(ssh_shorthand)){
    std::cout << ssh_shorthand << " doesn't exist" << std::endl;
    return 1;
  }

  std::string line;
  std::ifstream infile(utils::getFullConfigPath());
  std::vector<std::string> sshcut_parsed;
  while (std::getline(infile, line)){
    //clearing vector after every iteration
    sshcut_parsed.clear();

    if (line.empty()) continue;
    strtk::parse(line,",",sshcut_parsed);
    if (sshcut_parsed.size() != 2 && sshcut_parsed.size() != 3){
      std::cout << sshcut_parsed.size() << std::endl;
      std::cout << "Parsing error, connectSSH() in sshcut config, check your commas" << std::endl;
      return 1;
    }
    if (sshcut_parsed[0] == ssh_shorthand){
     break;
    }
  }

  if(sshcut_parsed.size() == 3){
    std::cout << "Executing trigger..."<< std::endl;
    system((sshcut_parsed[2]).c_str());
  }

  std::cout << "Attempting to connect to " << ssh_shorthand << std::endl;
  system(("ssh " + sshcut_parsed[1]).c_str());

  //actually do the ssh
  return 0;
}

void sshcut::showList(void){
  std::ifstream ifile(utils::getFullConfigPath());
  if (ifile) {
    std::string str;
    std::vector<std::string> str_vect;
    while (std::getline(ifile, str)) {
      // output the line
      if (str.empty()) continue;
      str_vect.clear();
      strtk::parse(str,",",str_vect);
      if (str_vect.size() != 2 && str_vect.size() != 3){
        std::cout << "Parsing error, showList() in sshcut config, check your commas" << std::endl;
        return;
      }
      if(str_vect.size() == 2){
        std::cout << str_vect[0] << " -> " << str_vect[1] << std::endl;
      }
      else{
        std::cout << str_vect[0] << " -> " << str_vect[1] << std::endl;
        std::cout << "\t On Host Trigger: " << str_vect[2] << std::endl;
      }
    }
  }
  else{
    std::cout << "No sshcut config" << std::endl;
    return;
   }
}