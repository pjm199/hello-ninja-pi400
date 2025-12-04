#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="build"

echo "== Configure =="
cmake -S . -B "$BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Debug

echo "== Build =="
cmake --build "$BUILD_DIR"

echo "== Test =="
cd "$BUILD_DIR"
ctest --output-on-failure
