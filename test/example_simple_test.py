import os
from subprocess import call

test_directory_name = "testdir"

def setup():
    if os.path.isdir(test_directory_name):
        call(["fusermount", "-u", test_directory_name])
        os.rmdir(test_directory_name)
    os.mkdir(test_directory_name)
    call(["../examples/bin/simple", test_directory_name])
    
def test_getattr():
    assert test_directory_name in os.listdir('.')
