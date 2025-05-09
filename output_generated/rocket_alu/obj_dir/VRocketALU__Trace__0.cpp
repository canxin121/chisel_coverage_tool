// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRocketALU__Syms.h"


void VRocketALU___024root__trace_chg_0_sub_0(VRocketALU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VRocketALU___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRocketALU___024root__trace_chg_0\n"); );
    // Init
    VRocketALU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRocketALU___024root*>(voidSelf);
    VRocketALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VRocketALU___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VRocketALU___024root__trace_chg_0_sub_0(VRocketALU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRocketALU___024root__trace_chg_0_sub_0\n"); );
    VRocketALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgQData(oldp+0,(vlSelfRef.RocketALU__DOT__in2_inv),64);
        bufp->chgQData(oldp+2,(vlSelfRef.RocketALU__DOT__in1_xor_in2),64);
        bufp->chgBit(oldp+4,(vlSelfRef.RocketALU__DOT__slt));
        bufp->chgIData(oldp+5,(vlSelfRef.RocketALU__DOT__shin_hi),32);
        bufp->chgQData(oldp+6,(vlSelfRef.RocketALU__DOT__shin),64);
        bufp->chgQData(oldp+8,(vlSelfRef.RocketALU__DOT__out),64);
    }
    bufp->chgBit(oldp+10,(vlSelfRef.clock));
    bufp->chgBit(oldp+11,(vlSelfRef.reset));
    bufp->chgBit(oldp+12,(vlSelfRef.io_dw));
    bufp->chgCData(oldp+13,(vlSelfRef.io_fn),5);
    bufp->chgQData(oldp+14,(vlSelfRef.io_in2),64);
    bufp->chgQData(oldp+16,(vlSelfRef.io_in1),64);
    bufp->chgQData(oldp+18,(vlSelfRef.io_out),64);
    bufp->chgQData(oldp+20,(vlSelfRef.io_adder_out),64);
    bufp->chgBit(oldp+22,(vlSelfRef.io_cmp_out));
}

void VRocketALU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRocketALU___024root__trace_cleanup\n"); );
    // Init
    VRocketALU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRocketALU___024root*>(voidSelf);
    VRocketALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
