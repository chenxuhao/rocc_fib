Fibonacci Sequence RoCC Accelerator
=============
A Fibonacci circuit, called Fib.scala, plus a testbench, called FibTest.scala, 
that verifies that your circuit is working. The circuit should produce the 
sequence of Fibonacci numbers in order until it reaches some known end. 
Your circuit should use a handshaking interface for the input and be able 
to compute the 70th Fibonacci number. The input should be the length of 
the Fibonacci sequence. The output should produce a single Fibonacci number 
in the sequence, a valid signal, and an output signal indicating that it is done.

Usage:

If cloned into rocket-chip directory use

    cd rocket-chip/
    git clone https://github.com:chenxuhao/rocc_fib.git
    mv fib_rocc fib

You can build the emulator using

    cd emulator && make ROCKETCHIP_ADDONS=fib CONFIG=FibAccelConfig


You can emulate the software implementation of fib by running

    ./emulator-freechips.rocketchip.system-FibAccelConfig pk ../fib/tests/fib-sw.rv +dramsim

or

    ./emulator-freechips.rocketchip.system-FibAccelConfig pk ../fib/tests/fib-sw-bm.rv

You can emulate the accelerated fib by running

    ./emulator-freechips.rocketchip.system-FibAccelConfig pk ../fib/tests/fib-rocc-bm.rv

or 

    ./emulator-freechips.rocketchip.system-FibAccelConfig pk ../fib/tests/fib-rocc.rv

The -bm versions of the code omit the print statements and will complete faster.
