#include "my-fuse++-fs.h"

int main(int argv, const char** argv){
    MyFusexxFs fs;
    fs.start();
    return 0;
}
