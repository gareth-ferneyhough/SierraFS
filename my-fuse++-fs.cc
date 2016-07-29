#include <iostream>
#include <string>
#include <errno.h>
#include <unistd.h>
#include "fuse++.h"

class MyFusexxFs : public fusexx::SimpleFuse {
public:
    int GetAttr(std::string path, struct stat* stbuf) {
        std::cout << "MyFusexxFs:GetAttr: " << path << std::endl;
        int res;

        res = lstat(path.c_str(), stbuf);
        std::cout << "result: " << res << std::endl;
        if (res == -1)
            return -errno;

        return 0;
    }
};

int main(int argc, const char** argv){
    MyFusexxFs fs;
    return fs.Start(argc, argv);
}
