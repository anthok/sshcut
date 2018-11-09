#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <filesystem>
#include <sys/types.h>
#include <sys/stat.h>

#define strtk_no_tr1_or_boost
#include "strtk.hpp"


namespace utils{

  const std::string config_file_from_userhome = "/.config/sshcut/config.sshcut";
  const std::string config_folder_from_userhome = "/.config/sshcut/";
  const std::string SSHCUT_VERSION = "0.1";


  std::string getFullConfigPath();
  std::string getFullConfigFolder();
  void createEmptyConfig();
  bool doesConfigFileExist();
  bool doesConfigFolderExist();
  void printUsage(void);
  bool doesNameExist(std::string potentialName);
  bool isValidInput(std::string shortcut, std::string ssh_cmd);


}

#endif
