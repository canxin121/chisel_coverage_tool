// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRocketALU.h for the primary calling header

#include "VRocketALU__pch.h"
#include "VRocketALU__Syms.h"
#include "VRocketALU___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VRocketALU___024root___dump_triggers__ico(VRocketALU___024root* vlSelf);
#endif  // VL_DEBUG

void VRocketALU___024root___eval_triggers__ico(VRocketALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRocketALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRocketALU___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VRocketALU___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRocketALU___024root___dump_triggers__act(VRocketALU___024root* vlSelf);
#endif  // VL_DEBUG

void VRocketALU___024root___eval_triggers__act(VRocketALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRocketALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRocketALU___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VRocketALU___024root___dump_triggers__act(vlSelf);
    }
#endif
}
