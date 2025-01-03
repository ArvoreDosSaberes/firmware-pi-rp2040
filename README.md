# Edge Impulse firmware for Raspberry Pi RP2040

Edge Impulse enables developers to create the next generation of intelligent device solutions with embedded Machine Learning. This repository contains the Edge Impulse firmware for the Raspberry Pi RP2040 based development boards, specifically Raspberry Pi Pico and Arduino Nano RP2040 Connect. This device supports Edge Impulse device features, including ingestion and inferencing.

**Note: Do you just want to use this development board with Edge Impulse? No need to build this firmware. See the instructions [here](https://docs.edgeimpulse.com/docs/raspberry-pi-rp2040) for a prebuilt firmware and instructions. Or, you can use the [data forwarder](https://docs.edgeimpulse.com/docs/cli-data-forwarder) to capture data from any sensor.**


## Requirements
### Hardware

- Raspberry Pi RP2040 based development boards, preferably Raspberry Pi Pico or Arduino Nano RP2040 Connect.
- (Optional) If you are using Raspberry Pi Pico, [Grove Shield for Pi Pico](https://wiki.seeedstudio.com/Grove_Shield_for_Pi_Pico_V1.0/) makes it easier to connect external sensors for data collection/inference.

### Tools
The below instructions assume you are using Debian-based Linux distribution. You must use gcc version 10.3.1, in the case of Ubuntu, the ideal is Ubuntu Focal. Alternative  instructions for those using Microsoft Windows or Apple macOS are provided in [Getting started with Pico guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) (Sections 9.1 and 9.2).

To build firmware, you will need pico-sdk, CMake, a
cross-platform tool used to build the software, and the GNU Embedded Toolchain for Arm. You can install both these via apt from the command line. 

```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential 
```

**NOTE**
Ubuntu and Debian users might additionally need to also install ```libstdc++-arm-none-eabi-newlib```.

You'll need PICO SDK to compile the firmware. You can obtain it from https://github.com/raspberrypi/pico-sdk and then specify PICO_SDK_PATH environmental variable, that would point to exact PICO SDK location on your system.
E.g.

```bash
cd ~/
git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk
export PICO_SDK_PATH="~/pico-sdk"
```

## Building the application
Then from the firmware folder execute:
```bash
mkdir build && cd build
cmake ..
make -j4
```

If you want to enable debug build (with lots of printing, specifically in data acquisition and flash read/write parts of the code), run 
```bash
mkdir build && cd build
cmake .. -DDEFINE_DEBUG=ON
make -j4
```

The  fastest  method  to  load  firmware  onto  a  RP2040-based  board  for  the  first  time  is  by  mounting  it  as  a  USB  Mass
Storage  Device.  Doing  this  allows  you  to  drag  a  file  onto  the  board  to  program  the  flash.  Go  ahead  and  connect  the
Raspberry  Pi  Pico  to  your  computer  using  a  micro-USB  cable,  making  sure  that  you  hold  down  the  BOOTSEL  button as you do so, to force it into USB Mass Storage Mode. Drag the ei_rp2040_firmware.uf2 file from build folder to newly appeared USB Mass Storage device.

## Using Docker for Development

For users who prefer a Docker-based environment, you can create a custom Docker image with all the necessary tools and libraries pre-installed. Below are the steps to create, configure, and use the Docker image.

### Building the Docker Image

1. Ensure Docker is installed and running on your system.
2. Create a `Dockerfile` with the following content:
    ```dockerfile
    # Use Ubuntu Focal como imagem base
    FROM ubuntu:focal

    # Definir o ambiente não interativo para evitar prompts durante a instalação
    ENV DEBIAN_FRONTEND=noninteractive

    # Atualizar e instalar ferramentas necessárias
    RUN apt-get update && apt-get install -y \
        wget \
        git \
        gcc-arm-none-eabi \
        libnewlib-arm-none-eabi \
        libstdc++-arm-none-eabi-newlib \
        build-essential && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*
    
    # Definir versões e caminhos para o CMake
    ENV CMAKE_VERSION=3.28
    ENV CMAKE_BUILD=1
    ENV CMAKE_DIR=/opt/cmake
    RUN mkdir -p /tmp/cmake && \
        cd /tmp/cmake && \
        wget https://cmake.org/files/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.${CMAKE_BUILD}-linux-x86_64.sh && \
        mkdir -p ${CMAKE_DIR} && \
        sh cmake-${CMAKE_VERSION}.${CMAKE_BUILD}-linux-x86_64.sh --skip-license --prefix=${CMAKE_DIR} && \
        rm -rf /tmp/cmake
    
    # Configurar o pico-sdk
    ENV PICO_SDK_PATH=/opt/pico-sdk
    RUN git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk ${PICO_SDK_PATH}
    
    # Definir o diretório de trabalho
    WORKDIR /home/workspace

    ```

3. Build the Docker image and tag it as `edgeimpulse:ubuntu_focal`:
    ```bash
    docker build -t edgeimpulse:ubuntu_focal .
    ```

### Running the Docker Container

1. Start a container using the image, mounting your workspace directory:
    ```bash
    docker run -it --rm \
        -v /path/to/your/workspace:/home/workspace \
        edgeimpulse:ubuntu_focal
    ```

    Replace `/path/to/your/workspace` with the absolute path to your local workspace. For example, on Linux or macOS, this might be `/home/yourusername/workspace`.

2. Inside the container, verify the PICO SDK path:
    ```bash
    echo $PICO_SDK_PATH
    ```

### Building the Firmware Inside the Container

1. Navigate to the firmware directory (e.g., `/home/workspace/firmware`):
    ```bash
    cd /home/workspace/firmware
    ```

2. Create a build directory and run CMake:
    ```bash
    mkdir build && cd build
    cmake ..
    ```

3. Compile the firmware:
    ```bash
    make -j4
    ```

4. The compiled firmware file `ei_rp2040_firmware.uf2` will be available in the `build` directory.

### Notes

- If you need to enable a debug build, modify the `cmake` command:
    ```bash
    cmake .. -DDEFINE_DEBUG=ON
    ```

- You can reuse the same container or create a new one as needed. The workspace folder will persist on your local machine.

By using Docker, you can avoid compatibility issues with your host environment and ensure a consistent build setup across different systems.

## Troubleshooting

- For Arduino RP2040 Connect, if you need to keep using Arduino IDE after you finished using Edge Impulse firmware, just connect the board to your computer and flash any code to the board. 

- If you are using Windows and experience isssue described in https://github.com/edgeimpulse/firmware-pi-rp2040/issues/1, you need to upgrade the tinyusb submodule of pico-sdk at least to commit https://github.com/hathach/tinyusb/commit/6ec5174d8b24d1f01a443c74a0a3dbee00523efc. After upgrade, remember to re-run cmake command.
