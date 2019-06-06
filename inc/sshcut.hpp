#ifndef SSHCUT_HPP
#define SSHCUT_HPP

#include "utils.hpp"

namespace sshcut{

  int connectSSH(std::string ssh_shorthand);
  int removeSSH(std::string ssh_shorthand);
  int addSSH(std::string ssh_shorthand, std::string ssh_conn, std::string trigger_action);
  int updateSSH(std::string ssh_shorthand, std::string ssh_conn, std::string trigger_action);
  void showList(void);

}

#endif