############### Builder image (not for distribution) ##################
FROM ubuntu:24.04 AS building

# Add OS dependencies and install Python packages
RUN apt-get update && \
    apt-get install -y git ninja-build build-essential flex bison git libsctp-dev libgnutls28-dev libgcrypt-dev libssl-dev libidn11-dev libmongoc-dev libbson-dev libyaml-dev libnghttp2-dev libmicrohttpd-dev libcurl4-gnutls-dev libtins-dev libtalloc-dev libpcre2-dev curl wget default-jdk cmake jq gcc g++ python3-pip python3-h2 util-linux-extra && \
    python3 -m pip install --break-system-packages --upgrade meson

# Copy the entire directory into the image
COPY . /source/rt-data-collection-application-function

# Specify working dir
WORKDIR /source/rt-data-collection-application-function

# Build DCAF
RUN meson setup --prefix /usr --sysconfdir /etc --localstatedir /var build
RUN meson compile -C build

# Install DCAF
RUN DESTDIR=/install meson install -C build

# Default configuration for container
RUN rm -f /install/usr/bin/open5gs-[a-ce-z]*

################# Build runtime image from binaries in building #############
FROM ubuntu:24.04 AS runtime

# Install runtime dependencies
RUN apt update && \
    apt -y install libsctp1 libgnutls30t64 libgcrypt20 libssl3t64 libidn12 libmongoc-1.0-0t64 libbson-1.0-0t64 libyaml-0-2 libnghttp2-14 libmicrohttpd12t64 libcurl3t64-gnutls libtins4.5 libtalloc2 libpcre2-16-0 python3

# Copy built files from the builder stage
COPY --from=building /install/ /

# Container entrypoint
ENTRYPOINT ["/usr/bin/open5gs-dcafd"]
