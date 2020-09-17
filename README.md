# Qt Introductory Course


#### Requirements

- Qt 5.15


#### Simple Build Instruction

Install docker, enter the source directory and run following commands from a bash:

    DIR_DEPLOY="$(pwd)/deploy/"
    rm -rf ${DIR_DEPLOY}
    mkdir -p ${DIR_DEPLOY}

    docker build --build-arg GROUP_ID=$(id -g ${USER}) --build-arg USER_ID=$(id -u ${USER}) --build-arg USER_NAME=${USER} -t qt_introductory_course .
    docker run -u ${USER} --rm=true -v ${DIR_DEPLOY}:/deploy/ qt_introductory_course cmake


#### Whats Inside

- Different types of applications plus libraries
- Icons: https://github.com/erikflowers/weather-icons licensed under SIL OFL 1.1


#### Needs Updates

- add presentation still in work
- entrypoint.sh: make tests should execute tests
- add documentation to add OPENWEATHERMAP_APPID
- not happy with qwidget application
- internationalization not done yet


#### Thanks to

- [Jürgen Messerer for his open mind and help](https://github.com/messi1)
- [Erik Flowers for his nice set of icons](https://github.com/erikflowers/weather-icons)
