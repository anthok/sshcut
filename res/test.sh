#!/bin/bash

user_home=$(eval echo "~$USER")
config_path="$user_home/.config/sshcut/config.sshcut"

echo $config_path
if [ ! -f $config_path ]; then
    echo 'no'
    exit
fi

    echo 'yes'
