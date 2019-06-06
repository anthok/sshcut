# sshcut
[![forthebadge](https://forthebadge.com/images/badges/you-didnt-ask-for-this.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/built-with-resentment.svg)](https://forthebadge.com)  
## SSH shortcut manager for Linux



## Usage

```
sshcut help 
sshcut 0.2

Usage:
  sshcut <command> [arguments]

Commands: 
  sshcut devbox1 
  sshcut add devbox2 root@192.168.1.2 <optional trigger>
  sshcut update devbox2 root@192.168.1.3 <optional trigger>
  sshcut remove devbox2 
  sshcut list 
  sshcut help
```



### Installing
#### Easy Install
`sudo dpkg -i sshcut_0.2-0.deb` 

#### Manual Install
Download one of the prebuilt binaries for your pleasure and a copy of the bashcomplete script in res/
```
sudo mv $BIN_FILE /usr/bin/sshcut
sudo mv $RES_FILE /etc/bash_completion.d/sshcut
```

### Developers

Just your run of the mill C++, its not great.

## Versioning
##### 0.3 (PLANNED)
##### 0.2  
- Added ssh trigger feature

##### 0.1
- First release of sshcut
  
## Authors

* **anthok**


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* The Bearded Bros

