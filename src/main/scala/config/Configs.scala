//see LICENSE for license
package freechips.rocketchip

import Chisel._
import freechips.rocketchip.config._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.system._
import fib._

class WithFibAccel extends Config((site, here, up) => {
	case BuildRoCC => List(
		(p: Parameters) => {
			val fib = LazyModule(new FibAccel(OpcodeSet.custom3)(p))
			fib
		}
	)
})

class FibAccelConfig extends Config(new WithFibAccel ++ new DefaultConfig)
