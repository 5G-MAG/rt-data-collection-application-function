<p align="center">
  <img src=".github/banner.svg" width="100%" alt="Reference Tools · UE Data Collection, Reporting and Event Exposure: Generic 3GPP Data Collection AF">
</p>

<p align="center">
  5G Data Collection Service Provider library and Application Function, implementing some of the
  data reports and events of 3GPP TS 26.531, TS 26.532 and TS 29.517.
</p>

<p align="center">
  <img alt="Status: under development"
    src="https://img.shields.io/badge/Status-Under%20Development-e67e22">
  <a href="https://github.com/5G-MAG/rt-data-collection-application-function/releases"><img alt="Version"
    src="https://img.shields.io/github/v/release/5G-MAG/rt-data-collection-application-function?label=Version"></a>
  <a href="LICENSE"><img alt="License: 5G-MAG Public License v1.0"
    src="https://img.shields.io/badge/License-5G--MAG%20PL%20v1.0-blue"></a>
</p>

<p align="center">
  <a href="https://www.5g-mag.com/reference-tools/data-collection/">Project page</a> &nbsp;&middot;&nbsp;
  <a href="https://github.com/5G-MAG/rt-data-collection-application-function/issues">Issues</a> &nbsp;&middot;&nbsp;
  <a href="https://www.5g-mag.com/contributing">Contributing</a>
</p>

---

## At a glance

|  |  |
|---|---|
| **Implements** | Some of the data reports and events defined in [3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm), [3GPP TS 26.532](https://www.3gpp.org/DynaReport/26532.htm) and [3GPP TS 29.517](https://www.3gpp.org/DynaReport/29517.htm) |
| **Part of** | [UE Data Collection, Reporting and Event Exposure](https://www.5g-mag.com/reference-tools/data-collection/), alongside [cmcd-toolkit](https://github.com/5G-MAG/cmcd-toolkit) |

## Introduction

This repository holds two things: a 5G Data Collection Service Provider library, and a
standalone Data Collection Application Function (AF) built on it. The library can also be
embedded in other Application Functions, such as the
[5GMS Application Function](https://github.com/5G-MAG/rt-5gms-application-function).

More information is on the [project page](https://www.5g-mag.com/reference-tools/data-collection/).

### 5G Data Collection Service Provider library

The library can provide the interfaces designated R1-R6 in [3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm)
(see clause 4.2). The Application Function that embeds it can disable individual interfaces at
start-up if it implements those, or similar, interfaces itself. The Application Function uses the
library through a C function API designed for Network Functions written for
[Open5GS](https://open5gs.org/).

### 5G Data Collection Application Function

The default Application Function in this repository uses the Service Provider library to
implement some of the data reports and events defined in
[3GPP TS 26.531](https://www.3gpp.org/DynaReport/26531.htm),
[3GPP TS 26.532](https://www.3gpp.org/DynaReport/26532.htm) and
[3GPP TS 29.517](https://www.3gpp.org/DynaReport/29517.htm). It is a Network Function based on the
[Open5GS](https://open5gs.org/) framework, and is meant to integrate with other 5G application suites
through its HTTP APIs.

A list of currently supported features will be published on the
[project page](https://www.5g-mag.com/reference-tools/data-collection/).

## Specification

Built against 3GPP TS 26.531, TS 26.532 and TS 29.517; this README states no document version.
The OpenAPI bindings are generated at build time from the 5G_APIs repository, by default at tag
`TSG105-Rel18` (Release 18, set by the `fiveg_api_release` and `fiveg_api_approval` options in
`meson_options.txt`).

Clause-by-clause coverage, and what is still absent, is recorded on the project page rather than
here: <https://www.5g-mag.com/reference-tools/data-collection/>

## Install dependencies

### Building with the regression tests

The optional regression tests need Ubuntu 24.04 (Noble Numbat) or later, because they rely on
command-line tools from curl v8.3.0 or later and util-linux v2.39 or later. To install the
dependencies, including those for the regression tests, on Ubuntu 24.04 or later:

```bash
sudo apt install git ninja-build build-essential flex bison libsctp-dev libgnutls28-dev libgcrypt-dev libssl-dev libidn11-dev libmongoc-dev libbson-dev libyaml-dev libnghttp2-dev libmicrohttpd-dev libcurl4-gnutls-dev libtins-dev libtalloc-dev libpcre2-dev curl wget default-jdk cmake jq util-linux-extra python3-h2
sudo python3 -m pip install --upgrade meson
```

### Building without the regression tests

If you do not plan to run the regression tests, install the build dependencies on Ubuntu with:

```bash
sudo apt install git ninja-build build-essential flex bison libsctp-dev libgnutls28-dev libgcrypt-dev libssl-dev libidn11-dev libmongoc-dev libbson-dev libyaml-dev libnghttp2-dev libmicrohttpd-dev libcurl4-gnutls-dev libtins-dev libtalloc-dev libpcre2-dev curl wget default-jdk cmake
sudo python3 -m pip install --upgrade meson
```

## Downloading

Release tar files can be downloaded from <https://github.com/5G-MAG/rt-data-collection-application-function/releases>.

The source can be obtained by cloning the GitHub repository. For example, to download the latest
release:

```bash
cd ~
git clone --recurse-submodules https://github.com/5G-MAG/rt-data-collection-application-function.git
```

## Building

The build needs a working Internet connection, because the API files are retrieved at build time.

To build the 5G Data Collection Application Function from the source:

```bash
cd ~/rt-data-collection-application-function
meson build
ninja -C build
```

**Note:** Errors during `meson build` are often caused by missing dependencies, or by a network
issue while retrieving the API files and the `openapi-generator` JAR file. The log
`~/rt-data-collection-application-function/build/meson-logs/meson-log.txt` has the errors in
detail; search for `generator-libspdc` to find the start of the API fetch sequence.

## Installing

To install the built Application Function as a system process:

```bash
cd ~/rt-data-collection-application-function/build
sudo meson install --no-rebuild
```

## Running

The Application Function needs a running 5G Core NRF Network Function to register with. If you
do not have a 5G Core running, the [Open5GS](https://open5gs.org/) Network Functions are
installed as part of the installation procedure, and the Open5GS NRF can be started with:

```bash
sudo /usr/local/bin/open5gs-nrfd &
```

Make sure the IP address and port of your NRF are configured in the `nrf` section of
`/usr/local/etc/open5gs/dcaf.yaml`, then run the Data Collection Application Function, for
example:

```bash
sudo /usr/local/bin/open5gs-dcafd &
```

## Development

This project follows the
[Gitflow workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow).
The `development` branch is the integration branch for new features, so switch to the
`development` branch before starting work on a new feature.

### Regression tests (optional)

Regression tests check that the data collection library and Application Function behave as
expected. They need the extra dependencies listed under
[Install dependencies](#install-dependencies). Run them with:

```bash
cd ~/rt-data-collection-application-function
meson test -C build regression
```

This builds the Data Collection AF if needed, starts an Open5GS NRF and the Data Collection AF,
runs the regression tests, shuts down the NRF and the AF, and displays the results.

### Integration tests (optional)

End-to-end tests, run with pytest against a running local Data Collection AF started from
`docker/local`, create, read and delete resources on the R1 (provisioning sessions and data
reporting configurations), R2 (data reporting sessions and reports) and R6 (event subscriptions)
APIs. Requirements and commands are in [tests/integration/README.md](tests/integration/README.md).

## Contributing

Contributions are welcome. How to raise an issue, fork the repository and open a pull request, and
the Contributor License Agreement required before code can be merged, are described at
<https://www.5g-mag.com/contributing>.

## License

Distributed under the 5G-MAG Public License v1.0. See [LICENSE](LICENSE).
