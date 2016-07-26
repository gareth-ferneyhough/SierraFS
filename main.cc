#include "my-fuse++-fs.h"

int main(int argc, const char** argv){
    MyFusexxFs fs;
    return fs.Start(argc, argv);
}
