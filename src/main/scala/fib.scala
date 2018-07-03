//see LICENSE for license
//authors: Xuhao Chen
package fib
import Chisel._
import freechips.rocketchip.rocket._
import freechips.rocketchip.config._
import freechips.rocketchip.tile._

class FibAccel(opcodes: OpcodeSet, val n: Int = 70)(implicit p: Parameters) extends LazyRoCC(opcodes) {
  override lazy val module = new FibAccelModuleImp(this)
}

class FibAccelModuleImp(outer: FibAccel) extends LazyRoCCModuleImp(outer)
    with HasCoreParameters {
  val regfile = Mem(outer.n, UInt(width = xLen))
  val length = io.cmd.bits.rs1
  val addr = io.cmd.bits.rs2
  val s_idle :: s_req :: s_resp :: s_other :: Nil = Enum(Bits(), 4)
  val state = Reg(init = s_idle)

  // datapath
  io.cmd.ready := (state === s_idle)
  val fib = regfile(addr)
  
  // control
  when (io.cmd.fire()) { state := s_req }
  when (io.resp.fire()) { state := s_idle }

  io.resp.valid := io.cmd.valid
  io.resp.bits.data := fib

  io.busy := io.cmd.valid
  io.interrupt := Bool(false)
  io.mem.req.valid := Bool(false)
}
