#include "my-fuse++-fs.h"

int main(int argc, const char** argv){
    MyFusexxFs fs;
    fs.Start();
    return 0;
}
