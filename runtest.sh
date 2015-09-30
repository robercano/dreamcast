#!/bin/bash

# Global config
ITER=20
STR=test

# Get the script directory
pushd `dirname $0` >/dev/null
DIR=`pwd -P`
popd >/dev/null

# Compile the SH4 and the X86 binaries
sh-elf-gcc -m4 -o $DIR/tests/sh4tests tests/sh4tests.c
gcc -o $DIR/tests/sh4tests.x86 tests/sh4tests.c

# Run the tests and compare
diff <($DIR/tests/sh4tests.x86 $ITER $STR) <($DIR/tools/sh4interpreter $DIR/tests/sh4tests $ITER $STR) > .runtests.diff
DIFF=`cat .runtests.diff`

if [ "$DIFF" != "" ]; then
    echo "ERROR running the tests (x86 --> sh4)"
    echo ""
    cat .runtests.diff
    rm -f .runtests.diff
    exit 1
fi

echo "Done!"
rm -f .runtests.diff
exit 0
