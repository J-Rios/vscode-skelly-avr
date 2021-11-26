# Build Help

```bash
Usage: make ...
Options:
    help: Show build usage information (current file).
    check: Show build parameters.
    clean: Clean last built files.
    rebuild: Force clean last built files and build again.
    flash: Build and write firmware to target device.
    fuses: Write fuses to target device.
    test: Build a Test Firmware (add TEST global Define to code).
    bootloader: Build to be used with a Bootloader.
```

# Build Examples

```bash
make
make help
make check
make clean
make rebuild
make flash
make fuses
make test
make bootloader
make test bootloader
```
