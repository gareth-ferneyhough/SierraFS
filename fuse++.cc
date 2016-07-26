#define FUSE_USE_VERSION 30

#include <iostream>
#include <errno.h>
#include <unistd.h>
#include "fuse.h" 
#include "fuse++.h"

static fusexx::SimpleFuse* instance = NULL;
int _getattr(const char *path, struct stat *stbuf) {
    std::cout << "_getattr" << std::endl;
	int res;

	res = lstat(path, stbuf);
	if (res == -1)
		return -errno;

	return 0;
    //return instance->GetAttr(std::string(path), stbuf); 
}

namespace fusexx {
int SimpleFuse::Start(int argc, const char** argv) {
    std::cout << "SimpleFuse::Start" << std::endl;
    instance = this;

    static fuse_operations xmp_oper;
    xmp_oper.getattr = _getattr;
    umask(0);
    return fuse_main(argc, argv, &xmp_oper, NULL);
}

int SimpleFuse::GetAttr(std::string path, struct stat *stbuf) {
    std::cout << "SimpleFuse::GetAttr" << std::endl;
	int res;

	res = lstat(path.c_str(), stbuf);
	if (res == -1)
		return -errno;

	return 0;
}

int SimpleFuse::Access(std::string path, int mask) {
    std::cout << "SimpleFuse::Access" << std::endl;
}

int SimpleFuse::ReadLink(std::string path, char *buf, size_t size) {
    std::cout << "SimpleFuse::ReadLink" << std::endl;
}

//int SimpleFuse::ReadDir(std::string path, void* buf, fuse_fill_dir_t filler,
//               off_t offset, struct fuse_file_info* fi,
//               enum fuse_readdir_flags flags) {
//    std::cout << "SimpleFuse::ReadDir" << std::endl;
//}

int SimpleFuse::Mknod(std::string path, mode_t mode, dev_t rdev) {
    std::cout << "SimpleFuse::Mknod" << std::endl;
}

int SimpleFuse::Mkdir(std::string path, mode_t mode) {
    std::cout << "SimpleFuse::Mkdir" << std::endl;
}

int SimpleFuse::Unlink(std::string path) {
    std::cout << "SimpleFuse::Unlink" << std::endl;
}

int SimpleFuse::Rmdir(std::string path) {
    std::cout << "SimpleFuse::Rmdir" << std::endl;
}

int SimpleFuse::Symlink(std::string from, std::string to) {
    std::cout << "SimpleFuse::Symlink" << std::endl;
}

int SimpleFuse::Rename(std::string from, std::string to, unsigned int flags) {
    std::cout << "SimpleFuse::Rename" << std::endl;
}

int SimpleFuse::Link(std::string from, std::string to) {
    std::cout << "SimpleFuse::Link" << std::endl;
}

int SimpleFuse::Chmod(std::string path, mode_t mode) {
    std::cout << "SimpleFuse::Chmod" << std::endl;
}

int SimpleFuse::Chown(std::string path, uid_t uid, gid_t gid) {
    std::cout << "SimpleFuse::Chown" << std::endl;
}

int SimpleFuse::Truncate(std::string path, off_t size) {
    std::cout << "SimpleFuse::Truncate" << std::endl;
}

int SimpleFuse::Read(std::string path, fuse_file_info *fi) {
    std::cout << "SimpleFuse::Read" << std::endl;
}

//int SimpleFuse::Write(std::string path, const char* buffer,
//             off_t offset, struct fuse_file_info *fi) {
//    std::cout << "SimpleFuse::Write" << std::endl;
//}
//
//int SimpleFuse::Statfs(std::string path, struct statvfs *stbuf) {
//    std::cout << "SimpleFuse::Statfs" << std::endl;
//}
//
//int SimpleFuse::Fallocate(std::string path, int mode,
//            off_t offset, off_t length, struct fuse_file_info *fi) {
//    std::cout << "SimpleFuse::Fallocate" << std::endl;
//}
}
