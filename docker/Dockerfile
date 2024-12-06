# Use an official Ubuntu as a parent image
FROM ubuntu:24.04

# Avoid any questions
ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt update && \
    apt install -y \
    git  \
    ninja-build  \
    build-essential  \
    flex  \
    bison  \
    libsctp-dev  \
    libgnutls28-dev  \
    libgcrypt-dev  \
    libssl-dev  \
    libidn11-dev  \
    libmongoc-dev  \
    libbson-dev  \
    libyaml-dev  \
    libnghttp2-dev  \
    libmicrohttpd-dev  \
    libcurl4-gnutls-dev  \
    libtins-dev  \
    libtalloc-dev  \
    libpcre2-dev  \
    curl  \
    wget  \
    default-jdk  \
    cmake  \
    jq \
    python3-pip \
    python3-h2 \
    meson

# Clone the repository
RUN git clone --recurse-submodules -b development https://github.com/davidjwbbc/rt-data-collection-application-function.git

# Set working directory
WORKDIR /rt-data-collection-application-function

# Update submodules
RUN git submodule update

# Build the application
RUN meson build && ninja -C build

# Run regression tests
RUN meson test -C build regression

# Install the application
RUN meson install --no-rebuild -C build

# Run Open5GS NRF and
CMD ["/rt-data-collection-application-function/entrypoint.sh"]

