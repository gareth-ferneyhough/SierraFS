#include "fuse++.h"

class MyFusexxFs : public fusexx::SimpleFuse {
    MyFusexxFs();
    virtual ~MyFusexxFs();

    virtual GetAttr(string path, stat* stbuf) override;

};
