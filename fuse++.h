#ifndef FUSEXX_H_
#define FUSEXX_H_

#include <sys/stat.h>
#include <string>

//enum fuse_readdir_flags;

//enum fuse_fill_dir_flags;


//typedef int (*fuse_fill_dir_t) (void *buf, const char *name,
//				const struct stat* stbuf, off_t off,
//				fuse_fill_dir_flags flags);

struct fuse_file_info;
namespace fusexx {

class SimpleFuse {
    public:
    virtual int Start(int argc, const char** argv);
    virtual int GetAttr(std::string path, struct stat *stbuf);
    virtual int Access(std::string path, int mask);
    virtual int ReadLink(std::string path, char *buf, size_t size);
 //   virtual int ReadDir(std::string path, void* buf, fuse_fill_dir_t filler,
 //                      off_t offset, struct fuse_file_info* fi,
 //                      enum fuse_readdir_flags flags);
    virtual int Mknod(std::string path, mode_t mode, dev_t rdev);
    virtual int Mkdir(std::string path, mode_t mode);
    virtual int Unlink(std::string path);
    virtual int Rmdir(std::string path);
    virtual int Symlink(std::string from, std::string to);
    virtual int Rename(std::string from, std::string to, unsigned int flags);
    virtual int Link(std::string from, std::string to);
    virtual int Chmod(std::string path, mode_t mode);
    virtual int Chown(std::string path, uid_t uid, gid_t gid);
    virtual int Truncate(std::string path, off_t size);
    //virtual int Utimens(std::string path, const struct timespec ts[2]);
    //virtual int Open(std::string path, struct fuse_file_info *fi);
    virtual int Read(std::string path, fuse_file_info *fi);
//    virtual int Write(std::string path, const char* buffer,
//                     off_t offset, struct fuse_file_info *fi);
//    virtual int Statfs(std::string path, struct statvfs *stbuf);
    //virtual int Release(std::string path, struct fuse_file_info *fi);
    //virtual int Fsync(std::string path, 
    //               struct fuse_file_info *fi);
//    virtual int Fallocate(std::string path, int mode,
                    //off_t offset, off_t length, struct fuse_file_info *fi);
};
}
#endif
