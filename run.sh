#!/bin/bash
if [ -z "$NO_CLIP" ]; then
./clipboard/test &
fi
dolphin &
./dragtest
