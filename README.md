# Project

* *NOTE*: Don't launch manually minicom if you want to upload a firmware image, because it will block the device and the image cannot be upload.

# Compile

```
cmake -DINPUT_BOARD=pro -DINPUT_PORT=/dev/ttyUSB0 -DINPUT_SERIAL=minicom -DBOARD_CPU=16MHzatmega328 ..
```

# Upload

1. Push reset button.
1. Release reset button.
1. Execute immediately ```make upload```

# Manual minicom

```
sudo minicom -D /dev/ttyUSB0 -b 9600
```
