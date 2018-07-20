# daemon runs in the background
# run something like tail /var/log/Kwagshd/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/Kwagshd:/var/lib/Kwagshd -v $(pwd)/wallet:/home/kwagsh --rm -ti kwagsh:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG KWAGSH_VERSION=master
ENV KWAGSH_VERSION=${KWAGSH_VERSION}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost-all-dev && \
    git clone https://github.com/kwash-dev/Kwagsh.git /src/kwagsh && \
    cd /src/kwagsh && \
    git checkout $KWAGSH_VERSION && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/Kwagshd /usr/local/bin/Kwagshd && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/simplewallet /usr/local/bin/simplewallet && \
    cp src/miner /usr/local/bin/miner && \
    cp src/connectivity_tool /usr/local/bin/connectivity_tool && \
    strip /usr/local/bin/Kwagshd && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/simplewallet && \
    strip /usr/local/bin/miner && \
    strip /usr/local/bin/connectivity_tool && \
    cd / && \
    rm -rf /src/kwagsh && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the Kwagshd service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/Kwagshd Kwagshd && \
    useradd -s /bin/bash -m -d /home/kwagsh kwagsh && \
    mkdir -p /etc/services.d/Kwagshd/log && \
    mkdir -p /var/log/Kwagshd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Kwagshd/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/Kwagshd/run && \
    echo "cd /var/lib/Kwagshd" >> /etc/services.d/Kwagshd/run && \
    echo "export HOME /var/lib/Kwagshd" >> /etc/services.d/Kwagshd/run && \
    echo "s6-setuidgid Kwagshd /usr/local/bin/Kwagshd" >> /etc/services.d/Kwagshd/run && \
    chmod +x /etc/services.d/Kwagshd/run && \
    chown nobody:nogroup /var/log/Kwagshd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Kwagshd/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/Kwagshd/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/Kwagshd" >> /etc/services.d/Kwagshd/log/run && \
    chmod +x /etc/services.d/Kwagshd/log/run && \
    echo "/var/lib/Kwagshd true Kwagshd 0644 0755" > /etc/fix-attrs.d/Kwagshd-home && \
    echo "/home/kwagsh true kwagsh 0644 0755" > /etc/fix-attrs.d/kwagsh-home && \
    echo "/var/log/Kwagshd true nobody 0644 0755" > /etc/fix-attrs.d/Kwagshd-logs

VOLUME ["/var/lib/Kwagshd", "/home/kwagsh","/var/log/Kwagshd"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/kwagsh export HOME /home/kwagsh s6-setuidgid kwagsh /bin/bash"]
