// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopModule.h for the primary calling header

#include "VTopModule__pch.h"
#include "VTopModule__Syms.h"
#include "VTopModule___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopModule___024root___dump_triggers__stl(VTopModule___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTopModule___024root___eval_triggers__stl(VTopModule___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopModule___024root___eval_triggers__stl\n"); );
    VTopModule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTopModule___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
