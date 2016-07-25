#include <iostream>
#include <string>
#include "my-fuse++-fs.h"

using std::string;

MyFusexxFs::MyFusexxFs() {
}

MyFusexxFs::~MyFusexxFs() {
}

int MyFusexxFs::GetAttr(string path, struct stat* stbuf) {
    std::cout << "GetAttr: " << path << std::endl;
}

