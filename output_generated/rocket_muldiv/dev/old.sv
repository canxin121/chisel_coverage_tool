// Generated by CIRCT firtool-1.43.0
module MulDiv(
  input          clock,
                 reset,
                 io_req_valid,
  input  [4:0]   io_req_bits_fn,
  input          io_req_bits_dw,
  input  [63:0]  io_req_bits_in1,
                 io_req_bits_in2,
  input  [4:0]   io_req_bits_tag,
  input          io_kill,
                 io_resp_ready,
  output         io_req_ready,
                 io_resp_valid,
  output [63:0]  io_resp_bits_data,
  output [127:0] io_resp_bits_full_data,
  output [4:0]   io_resp_bits_tag
);

  reg  [2:0]   state;
  reg          req_dw;
  reg  [4:0]   req_tag;
  reg  [6:0]   count;
  reg          neg_out;
  reg          isHi;
  reg          resHi;
  reg  [64:0]  divisor;
  reg  [129:0] remainder;
  wire [63:0]  result = resHi ? remainder[128:65] : remainder[63:0];
  wire [31:0]  loOut = req_dw | state[0] ? result[31:0] : result[63:32];
  wire         _io_resp_valid_output = state == 3'h6 | (&state);
  wire         _io_req_ready_output = state == 3'h0;
  always @(posedge clock) begin
    automatic logic [2:0] decoded_invInputs = ~(io_req_bits_fn[2:0]);
    automatic logic [1:0] _GEN = {decoded_invInputs[1], decoded_invInputs[2]};
    automatic logic       lhs_sign;
    automatic logic       rhs_sign;
    automatic logic       _GEN_0;
    automatic logic       _GEN_1;
    automatic logic       _GEN_2;
    automatic logic       _GEN_3;
    automatic logic       _GEN_4;
    automatic logic       _GEN_5;
    automatic logic       _GEN_6;
    lhs_sign =
      (|{decoded_invInputs[0], &_GEN})
      & (io_req_bits_dw ? io_req_bits_in1[63] : io_req_bits_in1[31]);
    rhs_sign =
      (|{&_GEN, &{decoded_invInputs[0], io_req_bits_fn[2]}})
      & (io_req_bits_dw ? io_req_bits_in2[63] : io_req_bits_in2[31]);
    _GEN_0 = state == 3'h1;
    _GEN_1 = state == 3'h5;
    _GEN_2 = state == 3'h2;
    _GEN_3 = _GEN_2 & count == 7'h3F;
    _GEN_4 = state == 3'h3;
    _GEN_5 = count == 7'h40;
    _GEN_6 = _io_req_ready_output & io_req_valid;
    if (reset)
      state <= 3'h0;
    else if (_GEN_6) begin
      if (decoded_invInputs[2])
        state <= 3'h2;
      else
        state <= {1'h0, ~(lhs_sign | rhs_sign), 1'h1};
    end
    else if (io_resp_ready & _io_resp_valid_output | io_kill)
      state <= 3'h0;
    else if (_GEN_4 & _GEN_5)
      state <= {1'h1, ~neg_out, 1'h1};
    else if (_GEN_3)
      state <= 3'h6;
    else if (_GEN_1)
      state <= 3'h7;
    else if (_GEN_0)
      state <= 3'h3;
    if (_GEN_6) begin
      automatic logic [1:0] _GEN_7 =
        {&{io_req_bits_fn[0], decoded_invInputs[2]}, io_req_bits_fn[1]};
      req_dw <= io_req_bits_dw;
      req_tag <= io_req_bits_tag;
      count <= {1'h0, decoded_invInputs[2] & ~io_req_bits_dw, 5'h0};
      if (|_GEN_7)
        neg_out <= lhs_sign;
      else
        neg_out <= lhs_sign != rhs_sign;
      isHi <= |_GEN_7;
      divisor <=
        {rhs_sign,
         io_req_bits_dw ? io_req_bits_in2[63:32] : {32{rhs_sign}},
         io_req_bits_in2[31:0]};
      remainder <=
        {66'h0,
         io_req_bits_dw ? io_req_bits_in1[63:32] : {32{lhs_sign}},
         io_req_bits_in1[31:0]};
    end
    else begin
      automatic logic [64:0] subtractor;
      subtractor = remainder[128:64] - divisor;
      if (_GEN_4 | _GEN_2)
        count <= count + 7'h1;
      neg_out <= ~(_GEN_4 & count == 7'h0 & ~(subtractor[64]) & ~isHi) & neg_out;
      if (_GEN_0 & divisor[63])
        divisor <= subtractor;
      if (_GEN_4)
        remainder <=
          {1'h0,
           subtractor[64] ? remainder[127:64] : subtractor[63:0],
           remainder[63:0],
           ~(subtractor[64])};
      else if (_GEN_2) begin
        automatic logic [65:0] _GEN_8 =
          {{65{remainder[64]}}, remainder[0]} * {divisor[64], divisor}
          + {remainder[129], remainder[129:65]};
        remainder <= {_GEN_8[65:1], count == 7'h3E & neg_out, _GEN_8[0], remainder[63:1]};
      end
      else if (_GEN_1 | _GEN_0 & remainder[63])
        remainder <= {66'h0, 64'h0 - result};
    end
    resHi <= ~_GEN_6 & (_GEN_4 & _GEN_5 | _GEN_3 ? isHi : ~_GEN_1 & resHi);
  end // always @(posedge)
  assign io_req_ready = _io_req_ready_output;
  assign io_resp_valid = _io_resp_valid_output;
  assign io_resp_bits_data = {req_dw ? result[63:32] : {32{loOut[31]}}, loOut};
  assign io_resp_bits_full_data = {remainder[128:65], remainder[63:0]};
  assign io_resp_bits_tag = req_tag;
endmodule

