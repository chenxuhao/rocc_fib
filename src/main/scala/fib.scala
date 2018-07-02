//see LICENSE for license
//authors: Xuhao Chen
package fib
import Chisel._
import freechips.rocketchip.rocket._
import freechips.rocketchip.config._
import freechips.rocketchip.tile._

class FibAccel(opcodes: OpcodeSet)(implicit p: Parameters) extends LazyRoCC(opcodes) {
  override lazy val module = new FibAccelModuleImp(this)
}

class FibAccelModuleImp(outer: FibAccel) extends LazyRoCCModuleImp(outer) {
}
