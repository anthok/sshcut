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

  const std::string config_path = "config.sshcut";
  const std::string SSHCUT_VERSION = "0.1";


  void showList(void);
  void printUsage(void);
  int connectSSH(std::string ssh_shorthand);
  int removeSSH(std::string ssh_shorthand);
  int addSSH(std::string ssh_shorthand, std::string ssh_conn);
  int updateSSH(std::string ssh_shorthand, std::string ssh_conn);

}

#endif
