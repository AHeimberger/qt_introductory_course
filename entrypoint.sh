#!/bin/bash

echo -e "Executing: ${0}" # print filename
set -e # exit on any failure (e.g. a crashing test)
set -o pipefail # propagate a failure through pipe

DIR_CURRENT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -z ${1} ] || [ ${1} == "help" ] ; then
    echo "Prints this help information:
 - /bin/bash
 - cmake
"
elif [ ${#} == 1 ] && [ ${1} == "cmake" ]; then
    cd "../deploy"
    cmake "../source/weather_application"
    make
    # make tests
    ./libraries/businesslogic/tests/tests_businesslogic
    ./libraries/openweathermap/tests/tests_openweathermap
    # /bin/bash
elif [ ${#} == 1 ] && [ -e ${1} ]; then
    ${1}
else
    printError "- Command \"${1}\" not found.\n"
    commands
    exit 1;
fi
