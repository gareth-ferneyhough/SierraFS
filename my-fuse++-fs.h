#include <string>
#include "fuse++.h"

class MyFusexxFs : public fusexx::SimpleFuse {
    public:
    MyFusexxFs();
    virtual ~MyFusexxFs();

    virtual int GetAttr(std::string path, struct stat* stbuf);

};
