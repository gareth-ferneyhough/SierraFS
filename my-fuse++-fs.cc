#include <iostream>
#include <string>
#include <errno.h>
#include <unistd.h>
#include "my-fuse++-fs.h"

using std::string;

MyFusexxFs::MyFusexxFs() {
}

MyFusexxFs::~MyFusexxFs() {
}

int MyFusexxFs::GetAttr(string path, struct stat* stbuf) {
    std::cout << "MyFusexxFs:GetAttr: " << path << std::endl;
	int res;

	res = lstat(path.c_str(), stbuf);
    std::cout << "result: " << res << std::endl;
	if (res == -1)
		return -errno;

	return 0;
}

