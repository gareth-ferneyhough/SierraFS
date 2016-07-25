#ifndef FUSEXX_H_
#define FUSEXX_H_

#include <string>


/** Handle for a FUSE filesystem */
struct fuse;

/**
 * Readdir flags, passed to ->readdir()
 */
enum fuse_readdir_flags {
	/**
	 * "Plus" mode.
	 *
	 * The kernel wants to prefill the inode cache during readdir.  The
	 * filesystem may honour this by filling in the attributes and setting
	 * FUSE_FILL_DIR_FLAGS for the filler function.  The filesystem may also
	 * just ignore this flag completely.
	 */
	FUSE_READDIR_PLUS = (1 << 0),
};

enum fuse_fill_dir_flags {
	/**
	 * "Plus" mode: all file attributes are valid
	 *
	 * The attributes are used by the kernel to prefill the inode cache
	 * during a readdir.
	 *
	 * It is okay to set FUSE_FILL_DIR_PLUS if FUSE_READDIR_PLUS is not set
	 * and vice versa.
	 */
	FUSE_FILL_DIR_PLUS = (1 << 1),
};


typedef int (*fuse_fill_dir_t) (void *buf, const char *name,
				const struct stat *stbuf, off_t off,
				enum fuse_fill_dir_flags flags);

struct stat;

namespace fusexx {

class SimpleFuse {
    virtual int GetAttr(std::string path, stat *stbuf);
    virtual int Access(std::string path, int mask);
    virtual int ReadLink(std::string path, char *buf, size_t size);
    virtual int ReadDir(std::string path, void* buf, fuse_fill_dir_t filler,
                       off_t offset, struct fuse_file    
                       enum fuse_readdir_flags flags);
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
    virtual int Read(std::string path, 
                    struct fuse_file_info *fi);
    virtual int Write(std::string path, std::string bu
                     off_t offset, struct fuse_file_info *fi);
    virtual int Statfs(std::string path, struct statvfs *stbuf);
    //virtual int Release(std::string path, struct fuse_file_info *fi);
    //virtual int Fsync(std::string path, 
    //               struct fuse_file_info *fi);
    virtual int Fallocate(std::string path, int mode,
                    off_t offset, off_t length, struct fuse_file_info *fi);
};
}
#endif
