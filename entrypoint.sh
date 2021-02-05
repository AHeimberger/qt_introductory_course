#!/bin/bash

echo -e "Executing: ${0}" # print filename
set -e # exit on any failure (e.g. a crashing test)
set -o pipefail # propagate a failure through pipe

DIR_CURRENT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# DIR_DEPLOY will be set in Dockerfile

if [ -z ${1} ] || [ ${1} == "help" ] ; then
    echo "Help Information:
 - /bin/bash
 - cmake
"
elif [ ${#} == 1 ] && [ ${1} == "cmake" ]; then
    if [ ! -z "${DIR_DEPLOY}" ]; then
        echo "Docker Execution"
        echo "DIR_DEPLOY: \"${DIR_DEPLOY}\""
        cd "${DIR_DEPLOY}"
        cmake "/source/"
    else
        echo "Local Execution"
        export CMAKE_PREFIX_PATH=/opt/Qt/5.15.0/gcc_64
        export QT_DIR=/opt/Qt/5.15.0/gcc_64/lib/cmake/Qt5
        rm -rf "deploy"
        mkdir "deploy"
        cd "deploy"
        cmake ..
    fi

    make
    
    # make tests
    # ./libraries/businesslogic/tests/tests_businesslogic
    # ./libraries/openweathermap/tests/tests_openweathermap
elif [ ${#} == 1 ] && [ -e ${1} ]; then
    ${1}
else
    printError "- Command \"${1}\" not found.\n"
    commands
    exit 1;
fi
