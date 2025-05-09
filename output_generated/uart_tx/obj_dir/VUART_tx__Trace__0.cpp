// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VUART_tx__Syms.h"


void VUART_tx___024root__trace_chg_0_sub_0(VUART_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VUART_tx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_tx___024root__trace_chg_0\n"); );
    // Init
    VUART_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VUART_tx___024root*>(voidSelf);
    VUART_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VUART_tx___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VUART_tx___024root__trace_chg_0_sub_0(VUART_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VUART_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_tx___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->UART_tx__DOT__clkCnterReg),8);
        bufp->chgCData(oldp+1,(vlSelf->UART_tx__DOT__bitCnterReg),4);
        bufp->chgCData(oldp+2,(vlSelf->UART_tx__DOT__inDataReg),8);
        bufp->chgBit(oldp+3,(vlSelf->UART_tx__DOT__outDataReg));
        bufp->chgBit(oldp+4,(vlSelf->UART_tx__DOT__outTxBusyReg));
        bufp->chgBit(oldp+5,(vlSelf->UART_tx__DOT__outTxDoneReg));
        bufp->chgCData(oldp+6,(vlSelf->UART_tx__DOT__stateReg),2);
    }
    bufp->chgBit(oldp+7,(vlSelf->clock));
    bufp->chgBit(oldp+8,(vlSelf->reset));
    bufp->chgBit(oldp+9,(vlSelf->io_i_tx_trig));
    bufp->chgCData(oldp+10,(vlSelf->io_i_data),8);
    bufp->chgBit(oldp+11,(vlSelf->io_o_tx_busy));
    bufp->chgBit(oldp+12,(vlSelf->io_o_tx_done));
    bufp->chgBit(oldp+13,(vlSelf->io_o_serial_data));
}

void VUART_tx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VUART_tx___024root__trace_cleanup\n"); );
    // Init
    VUART_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VUART_tx___024root*>(voidSelf);
    VUART_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
