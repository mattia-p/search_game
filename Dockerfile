FROM ubuntu:22.04

# Otherwise libsdl2-dev gets stuck at asking geographical region
ARG DEBIAN_FRONTEND=noninteractive

# Update package lists
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    gdb \
    clang \
    g++ \
    sudo \
    libsdl2-dev \
    libsdl2-image-dev \
    libgtest-dev

# Set working directory
WORKDIR /app

# Copy your source code
COPY src/ .
