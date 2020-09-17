FROM ubuntu:20.04
LABEL maintainer="aheimberger"



# setup environment
ENV DEBIAN_FRONTEND     noninteractive
ENV DIR_DEPLOY          /deploy/
ENV DIR_SOURCE          /source/



# setup default build arguments
ARG GROUP_ID=1000
ARG USER_ID=1000
ARG USER_NAME=builduser



# prerequisites
RUN apt-get -qq update && \
    apt-get -qq dist-upgrade && \
    # install dependencies
    apt-get install -qq -y --no-install-recommends \
    tzdata locales \
    ca-certificates \
    build-essential \
    cmake \
    software-properties-common \
    mesa-common-dev \
    libgl1-mesa-dev



# install Qt 5.15
# all packages: https://launchpad.net/~beineri
# found here: https://launchpad.net/~beineri/+archive/ubuntu/opt-qt515-xenial
RUN add-apt-repository -y ppa:beineri/opt-qt-5.15.0-focal && \
    apt-get -qq update
RUN apt-get -qq install \
    qt515base \
    qt515multimedia \
    qt515declarative \
    qt515imageformats \
    qt515quickcontrols \
    qt515quickcontrols2 \
    qt515svg \
    qt515serialport \
    qt515tools \
    qt515translations \
    qt515x11extras \
    qt515webchannel \
    qt515webengine
ENV PATH=${PATH}:/opt/qt515/bin/


# create group and user, user will be set after copying files
RUN groupadd -g ${GROUP_ID} ${USER_NAME} && \
    useradd -u ${USER_ID} -g ${GROUP_ID} -m -s /bin/bash ${USER_NAME}


# create volume mounts
RUN mkdir ${DIR_DEPLOY} && \
    chown -R ${USER_NAME}:${USER_NAME} ${DIR_DEPLOY}


# set timezone for test cases
# - TODO (AHE) : change test cases !!!
RUN ln -sf /usr/share/zoneinfo/Europe/Zurich /etc/localtime && \
    echo "Europe/Zurich" > /etc/timezone


# copy scripts
COPY . ${DIR_SOURCE}
RUN chown -R ${USER_NAME}:${USER_NAME} ${DIR_SOURCE}


# switch USER all commands using RUN will be executed as user
USER ${USER_NAME}


# set working directory
WORKDIR ${DIR_SOURCE}


# build project
ENTRYPOINT ["./entrypoint.sh"]
CMD ["help"]
