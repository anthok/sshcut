#include <iostream>
#include "utils.hpp"
#include "sshcut.hpp"


int main(int argc, char const *argv[]){

  //LESS THAN 2 ARGC
  if (argc < 2){
    utils::printUsage();
    return 0;
  }

  if(!utils::doesConfigFileExist()){
    utils::createEmptyConfig();
  }

  //2 ARGC
  //can be list,help,or connect
  else if(argc == 2){
    std::string opt = std::string(argv[1]);

    if (opt == "help"){
      utils::printUsage();
      return 0;
    }
    else if (opt == "list"){
      sshcut::showList();
    }
    else{
      sshcut::connectSSH(opt);
    }
  }

  //3 ARGC
  //remove
  else if(argc == 3){
    std::string opt = std::string(argv[1]);
    std::string shorthand = std::string(argv[2]);

    if (opt == "remove"){
      sshcut::removeSSH(shorthand);
    }
    else{
      utils::printUsage();
      return 0;
    }
  }

  //4 ARGC
  //add
  else if (argc == 4){
    std::string opt = std::string(argv[1]);
    std::string shorthand = std::string(argv[2]);
    std::string ssh_conn = std::string(argv[3]);

    if (opt == "add"){
      sshcut::addSSH(shorthand, ssh_conn);
    }
    else if (opt == "update"){
      sshcut::updateSSH(shorthand, ssh_conn);
    }
    else{
      utils::printUsage();
      return 0;
    }
  }

  //more than 4 ARGC
  else{
    utils::printUsage();
    return 0;
  }

  return 0;
}