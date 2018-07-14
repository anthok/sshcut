#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

#define strtk_no_tr1_or_boost
#include "strtk.hpp"


namespace utils{

  const std::string config_file_from_userhome = "/.config/sshcut/config.sshcut";
  const std::string SSHCUT_VERSION = "0.1";


  std::string getFullConfigPath();
  void createEmptyConfig();
  bool doesConfigExist();


  void showList(void);
  void printUsage(void);
  bool doesNameExist(std::string potentialName);
  int connectSSH(std::string ssh_shorthand);
  int removeSSH(std::string ssh_shorthand);
  int addSSH(std::string ssh_shorthand, std::string ssh_conn);
  int updateSSH(std::string ssh_shorthand, std::string ssh_conn);



}

#endif
