############### Builder image (not for distribution) ##################
FROM ubuntu:24.04 AS building
# Specify working dirs
WORKDIR /install
WORKDIR /source
# Add OS dependancies
RUN --network=default apt update
RUN --network=default apt -y install git ninja-build build-essential flex bison git libsctp-dev libgnutls28-dev libgcrypt-dev libssl-dev libidn11-dev libmongoc-dev libbson-dev libyaml-dev libnghttp2-dev libmicrohttpd-dev libcurl4-gnutls-dev libtins-dev libtalloc-dev libpcre2-dev curl wget default-jdk cmake jq gcc g++ python3-pip python3-h2 util-linux-extra
RUN --network=default python3 -m pip install --break-system-packages --upgrade meson
# Build DCAF
RUN --mount=type=bind,source=.,dst=/source/rt-data-collection-application-function,rw --network=default cd rt-data-collection-application-function; meson setup --prefix /usr --sysconfdir /etc --localstatedir /var ../build
RUN --mount=type=bind,source=.,dst=/source/rt-data-collection-application-function,rw ninja -C build
RUN --mount=type=bind,source=.,dst=/source/rt-data-collection-application-function,rw --network=default MESON_BUILD_ROOT=$PWD/build meson test -C build regression
RUN --mount=type=bind,source=.,dst=/source/rt-data-collection-application-function,rw DESTDIR=/install ninja -C build install
# Default configuration for container
COPY docker-open5gs-dcaf.yaml /install/etc/open5gs/dcaf.yaml
RUN rm -f /install/usr/bin/open5gs-[a-ce-z]*

################# Build runtime image from binaries in building #############
FROM ubuntu:24.04 AS runtime
RUN --network=default apt update && apt -y install libsctp1 libgnutls30t64 libgcrypt20 libssl3t64 libidn12 libmongoc-1.0-0t64 libbson-1.0-0t64 libyaml-0-2 libnghttp2-14 libmicrohttpd12t64 libcurl3t64-gnutls libtins4.5 libtalloc2 libpcre2-16-0 python3
COPY --from=building /install/ /
RUN ls -l /
# Container ports and entrypoint
LABEL org.opencontainers.image.source="https://github.com/5G-MAG/rt-data-collection-application-function.git"
LABEL org.opencontainers.image.description="5G Data Collection Application Function"
LABEL org.opencontainers.image.vendor="5G-MAG"
LABEL org.opencontainers.image.licenses="LicenseRef-5G-MAG"
EXPOSE 5000/tcp 5100/tcp 5101/tcp 5102/tcp 5200/tcp 5201/tcp
ENTRYPOINT ["/usr/bin/open5gs-dcafd"]
