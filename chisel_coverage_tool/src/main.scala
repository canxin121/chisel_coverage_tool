package main

import circt.stage.CustomStage
import file_util.FileUtil
import java.io.File
import circt.stage.ChiselStage
import chisel3.RawModule
import modules.WaveformGenerator
import modules.UART_rx
import modules.UART_tx
import chisel3.Reg
import modules.RegModule
import modules.ComplexExample
import firrtl.ir.CoverageTool
import org.chipsalliance.cde.config.{Parameters, Config, Field}
import freechips.rocketchip.rocket._
import freechips.rocketchip.rocket.ALU._
import freechips.rocketchip.util._
import _root_.circt.stage.ChiselStage
import freechips.rocketchip.system.DefaultConfig
import freechips.rocketchip.tile.{RocketTileParams, TileKey, LookupByHartIdImpl}
import freechips.rocketchip.tile.RocketTile
import org.chipsalliance.diplomacy.lazymodule.LazyModule
import freechips.rocketchip.system.ExampleRocketSystem

object Main {
  def main(args: Array[String]): Unit = {
    implicit val p: Parameters = new Config(
      new Config((site, here, up) => { case TileKey =>
        RocketTileParams()
      }) ++ new DefaultConfig
    ).toInstance

    val baseOutputDir = "output_generated"

    val modulesToProcess: Seq[(() => RawModule, String)] = Seq(
      (
        () => new WaveformGenerator,
        "waveform_generator"
      ),
      (
        () => new UART_rx(),
        "uart_rx"
      ),
      (
        () => new UART_tx(),
        "uart_tx"
      ),
      (() => new RegModule(), "reg_module"),
      (() => new ComplexExample(), "complex_example"),
      (() => new ALU(), "rocket_alu"),
      (() => new MulDiv(MulDivParams(), width = 64), "rocket_muldiv"),
      (
        () => {
          val ldut = LazyModule(new ExampleRocketSystem)
          ldut.module 
        },
        "example_rocket_system"
      )
    )

    modulesToProcess.foreach { case (moduleGenerator, outputSubDir) =>
      val outputDir = s"$baseOutputDir/$outputSubDir"
      CoverageTool.processModule(
        moduleGenerator = moduleGenerator,
        outputDir = outputDir,
        enableDevOutput = true
      )
    }
    println("所有模块处理完毕.")

  }
}
