# Qt Introductory Course

#### Whats Inside

- Different types of qt applications plus libraries
- Icons: https://github.com/erikflowers/weather-icons licensed under SIL OFL 1.1


#### Simple Build Instruction

Install docker, enter the source directory and run following commands from a bash:

    DIR_DEPLOY="$(pwd)/deploy/"
    rm -rf ${DIR_DEPLOY}
    mkdir -p ${DIR_DEPLOY}

    docker build --build-arg GROUP_ID=$(id -g ${USER}) --build-arg USER_ID=$(id -u ${USER}) --build-arg USER_NAME=${USER} -t qt_introductory_course .
    docker run -u ${USER} --rm=true -v ${DIR_DEPLOY}:/deploy/ qt_introductory_course cmake


#### Requirements

- Qt 5.15


#### Needs Updates

- add presentation still in work
- entrypoint.sh: make tests should execute tests
- add documentation to add OPENWEATHERMAP_APPID
- not happy with qwidget application
- internationalization not done yet
- app_id textfield to update


#### Thanks to

- [Jürgen Messerer](https://github.com/messi1) for his open mind and help
- [Erik Flowers](https://github.com/erikflowers/weather-icons) for his nice set of icons
