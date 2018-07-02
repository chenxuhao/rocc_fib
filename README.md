rocc-fib
=============

If cloned into rocket-chip directory use

    ./install-symlinks

You can build the emulator using

    cd ../emulator && make ROCKETCHIP_ADDONS=fib CONFIG=FibAccelConfig

You can then test it using the emulator

    make run-asm-tests

You can emulate the software implementation of fib by running

    ./emulator-Top-FibAccelConfig pk ../fib/tests/fib-sw.rv +dramsim

or

    ./emulator-Top-FibAccelConfig pk ../fib/tests/fib-sw-bm.rv +dramsim

You can emulate the accelerated fib by running

    ./emulator-Top-FibAccelConfig pk ../fib/tests/fib-rocc-bm.rv +dramsim

or 

    ./emulator-Top-FibAccelConfig pk ../fib/tests/fib-rocc.rv +dramsim

The -bm versions of the code omit the print statements and will complete faster.
