// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VWaveformGenerator__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VWaveformGenerator::VWaveformGenerator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VWaveformGenerator__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_waveType{vlSymsp->TOP.io_waveType}
    , io_output{vlSymsp->TOP.io_output}
    , _mux_cond___05Fs0{vlSymsp->TOP._mux_cond___05Fs0}
    , _cond_pred___05Fs0{vlSymsp->TOP._cond_pred___05Fs0}
    , _cond_pred___05Fs1{vlSymsp->TOP._cond_pred___05Fs1}
    , _cond_pred___05Fs2{vlSymsp->TOP._cond_pred___05Fs2}
    , _cond_pred___05Fs3{vlSymsp->TOP._cond_pred___05Fs3}
    , io_freqCtrl{vlSymsp->TOP.io_freqCtrl}
    , io_phaseOffset{vlSymsp->TOP.io_phaseOffset}
    , _reg_signals___05Fs0{vlSymsp->TOP._reg_signals___05Fs0}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VWaveformGenerator::VWaveformGenerator(const char* _vcname__)
    : VWaveformGenerator(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VWaveformGenerator::~VWaveformGenerator() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VWaveformGenerator___024root___eval_debug_assertions(VWaveformGenerator___024root* vlSelf);
#endif  // VL_DEBUG
void VWaveformGenerator___024root___eval_static(VWaveformGenerator___024root* vlSelf);
void VWaveformGenerator___024root___eval_initial(VWaveformGenerator___024root* vlSelf);
void VWaveformGenerator___024root___eval_settle(VWaveformGenerator___024root* vlSelf);
void VWaveformGenerator___024root___eval(VWaveformGenerator___024root* vlSelf);

void VWaveformGenerator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VWaveformGenerator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VWaveformGenerator___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VWaveformGenerator___024root___eval_static(&(vlSymsp->TOP));
        VWaveformGenerator___024root___eval_initial(&(vlSymsp->TOP));
        VWaveformGenerator___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VWaveformGenerator___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VWaveformGenerator::eventsPending() { return false; }

uint64_t VWaveformGenerator::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VWaveformGenerator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VWaveformGenerator___024root___eval_final(VWaveformGenerator___024root* vlSelf);

VL_ATTR_COLD void VWaveformGenerator::final() {
    VWaveformGenerator___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VWaveformGenerator::hierName() const { return vlSymsp->name(); }
const char* VWaveformGenerator::modelName() const { return "VWaveformGenerator"; }
unsigned VWaveformGenerator::threads() const { return 1; }
void VWaveformGenerator::prepareClone() const { contextp()->prepareClone(); }
void VWaveformGenerator::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VWaveformGenerator::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VWaveformGenerator___024root__trace_decl_types(VerilatedVcd* tracep);

void VWaveformGenerator___024root__trace_init_top(VWaveformGenerator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VWaveformGenerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VWaveformGenerator___024root*>(voidSelf);
    VWaveformGenerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VWaveformGenerator___024root__trace_decl_types(tracep);
    VWaveformGenerator___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VWaveformGenerator___024root__trace_register(VWaveformGenerator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VWaveformGenerator::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VWaveformGenerator::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VWaveformGenerator___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
