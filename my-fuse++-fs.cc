#include <iostream>
#include <sys/stat.h>
#include "my-fuse++-fs.h"

#include <string>
using std::string

MyFusexxFs::MyFusexxFs() {
}

MyFusexxFs::~MyFusexxFs() {
}

MyFusexxFs::GetAttr(string path, stat* stbuf) {
    std::cout << "GetAttr: " << path << std::endl;
}

