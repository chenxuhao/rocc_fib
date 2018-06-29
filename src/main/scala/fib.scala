//see LICENSE for license
//authors: Xuhao Chen
package fib

//import Chisel.Implicits._
import Chisel._

import rocket._

abstract class SimpleRoCC()(implicit p: Parameters) extends RoCC()(p)
{
  io.interrupt := Bool(false)
  // Set this true to trigger an interrupt on the processor (please refer to supervisor documentation)
}

class Sha3Accel()(implicit p: Parameters) extends SimpleRoCC()(p) {
  //parameters
} 
