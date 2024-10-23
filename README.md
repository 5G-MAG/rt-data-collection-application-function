<h1 align="center">5G Data Collection Application Function</h1>
<p align="center">
  <img src="https://img.shields.io/github/v/tag/5G-MAG/rt-data-collection-application-function?label=version" alt="Version">
  <img src="https://img.shields.io/badge/Status-Under_Development-yellow" alt="Under Development">
  <img src="https://img.shields.io/badge/License-5G--MAG%20Public%20License%20(v1.0)-blue" alt="License">
</p>

## Introduction

This repository provides a 5G Data Collection Service Provider library and Application Function. The library is designed to be used by this stand alone Application Function or to be used as an embedded service within other Application Functions such as the [5GMS Application Function](https://github.com/5G-MAG/rt-5gms-application-function). The library can provide the interfaces designated as R1-R6 in the [3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm) specification (See Clause 4.2). The defautl Application Function implementation here implements some of the data reports and events defined in [3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm), [3GPP TS 26.532](https://www.3gpp.org/DynaReport/26532.htm) and [3GPP TS 29.517](https://www.3gpp.org/DynaReport/29517.htm).

Additional information can be found at: https://5g-mag.github.io/Getting-Started/pages/ue-data-collection-reporting-exposure/

### 5G Data Collection Service Provider library

The library is designed to be used by this stand alone Application Function or to be used as an embedded service within other Application Functions such as the [5GMS Application Function](https://github.com/5G-MAG/rt-5gms-application-function). The library can provide the interfaces designated as R1-R6 in the [3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm) specification (See Clause 4.2). Individual interfaces can be disabled at application start up by the controlling Application Function if it implements those, or similar, interfaces itself. The Application Function interacts with the Service Provider library via a C function API designed to work with Network Functions written for [Open5GS](https://open5gs.org/).

### 5G Data Collection Application Function

This Application Function uses the Service Provider library to implement some of the data reports and events defined in [3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm), [3GPP TS 26.532](https://www.3gpp.org/DynaReport/26532.htm) and [3GPP TS 29.517](https://www.3gpp.org/DynaReport/29517.htm).

This is implemented as a Network Function based on the [Open5GS](https://open5gs.org/) framework. The runtime should integrate with other 5G application suites via the HTTP APIs.

A list of currently supported features is available [here (actual page TDB)](https://5g-mag.github.io/Getting-Started/pages/ue-data-collection-reporting-exposure/).

## Install dependencies

```bash
sudo apt install git ninja-build build-essential flex bison git libsctp-dev libgnutls28-dev libgcrypt-dev libssl-dev libidn11-dev libmongoc-dev libbson-dev libyaml-dev libnghttp2-dev libmicrohttpd-dev libcurl4-gnutls-dev libtins-dev libtalloc-dev libpcre2-dev curl wget default-jdk cmake jq
sudo python3 -m pip install --upgrade meson
```

## Downloading

Release tar files can be downloaded from <https://github.com/5G-MAG/rt-data-collection-application-function/releases>.

The source can be obtained by cloning the github repository.

For example to download the latest release you can use:

```bash
cd ~
git clone --recurse-submodules https://github.com/5G-MAG/rt-data-collection-application-function.git
```

## Building

The build process requires a working Internet connection as the API files are retrieved at build time.

To build the 5G Data Collection Application Function from the source:

```bash
cd ~/rt-data-collection-application-function
meson build
ninja -C build
```

**Note:** Errors during the `meson build` command are often caused by missing dependencies or a network issue while trying to retrieve the API files and `openapi-generator` JAR file. See the `~/rt-data-collection-application-function/build/meson-logs/meson-log.txt` log file for the errors in greater detail. Search for `generator-libspdc` to find the start of the API fetch sequence.

## Installing

To install the built Application Function as a system process:

```bash
cd ~/rt-data-collection-application-function/build
sudo meson install --no-rebuild
```

## Running

The Application Function requires a running 5G Core NRF Network Function to register with. If you do not have a running 5G Core, the [Open5GS](https://open5gs.org/) Network Functions are installed as part of the installation procedure and the Open5GS NRF can be started using:

```bash
sudo /usr/local/bin/open5gs-nrfd &
```

Make sure the IP address and port details of the NRF you are running are configured in the `nrf` section of `/usr/local/etc/open5gs/dcaf.conf` and then run the Data Collection Application Function. For example:

```bash
sudo /usr/local/bin/open5gs-dcafd &
```

## Development

This project follows
the [Gitflow workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow). The
`development` branch of this project serves as an integration branch for new features. Consequently, please make sure to
switch to the `development` branch before starting the implementation of a new feature.
