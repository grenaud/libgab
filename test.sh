#!/bin/bash

RVAL=0
set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -n "testing:"
./targetTest |md5sum > targetTest.md5sum
echo -e " ${GREEN}ok${NC}"

echo -n "testing md5sum:"
if diff targetTest.md5sum targetTest.md5sum_ > /dev/null
then
    echo -e " ${GREEN}test passed${NC}"
else
    echo -e " ${RED}test failed${NC}"
    exit 1
fi

